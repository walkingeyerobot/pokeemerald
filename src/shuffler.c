#include "global.h"
#include "shuffler.h"
#include "random.h"
#include "tinymt32.h"
#include "data.h"
#include "battle_setup.h"
#include "constants/battle_ai.h"
#include "constants/event_objects.h"
#include "constants/map_groups.h"
#include "constants/trainers.h"

#include "printf.h"
#include "mgba.h"

#include "data/shuffle_trainers.h"
#include "data/shuffle_starters.h"
#include "data/shuffle_rooms.h"

EWRAM_DATA int seed;
EWRAM_DATA tinymt32_t currentRoomSeed;
EWRAM_DATA u16 realStarterMon[3];

EWRAM_DATA struct MapEvents AdjustedMapEvents;
EWRAM_DATA struct ObjectEventTemplate AdjustedTemplates[MAX_OBJECTS];
EWRAM_DATA u16 CurrentAdjustedRoom = 0xFFFF;
EWRAM_DATA u8 CurrentAdjustedRoomIndex;

EWRAM_DATA union ShuffledObject AdjustedObjects[MAX_OBJECTS];

EWRAM_DATA struct WarpData realWarps[TOTAL_WARPS][4] = {};
EWRAM_DATA u8 distances[TOTAL_ROOMS];

void Shuffle() {
    tinymt32_t tinymt;
    tinymt.mat1 = MAT1;
    tinymt.mat2 = MAT2;
    tinymt.tmat = TMAT;
    seed = Random32();
    tinymt32_init(&tinymt, seed);
    mgba_printf(MGBA_LOG_INFO, "seed: %u", seed);

    int r;
    for (int i = 0; i < TOTAL_ROOMS; i++) {
        // burn RNs for room seeds.
        r = tinymt32_generate_uint32(&tinymt); 
    }
    for (int i = 0; i < 3; ) {
        r = tinymt32_generate_uint32(&tinymt) % POSSIBLE_STARTERS;
        if (i >= 1) {
            if (realStarterMon[0] == possibleStarters[r]) {
                continue;
            }
        }
        if (i == 2) {
            if (realStarterMon[1] == possibleStarters[r]) {
                continue;
            }
        }
        realStarterMon[i] = possibleStarters[r];
        i++;
    }

    int allRooms[TOTAL_ROOMS - 2];
    for (int j = 0; j < TOTAL_ROOMS - 2; j++) {
        allRooms[j] = j + 1;
    }
    
    for (int j = TOTAL_ROOMS - 3; j > 0; j--) {
        r = (tinymt32_generate_uint32(&tinymt) % j);
        u16 t = allRooms[r];
        allRooms[r] = allRooms[j];
        allRooms[j] = t;
    }

    allRooms[3] = 6;
    int currentRoomIndex = 0;
    distances[currentRoomIndex] = 0;
    for (int j = 0; j < TOTAL_ROOMS - 3; j++) {
        int targetRoomIndex = allRooms[j];
        distances[targetRoomIndex] = distances[currentRoomIndex] + 1;
        u8 roomGroup = Rooms[targetRoomIndex].id >> 8;
        u8 roomId = Rooms[targetRoomIndex].id & 0xFF;
        u8 warpId = Rooms[targetRoomIndex].warpIds[SOUTH];
        realWarps[currentRoomIndex][NORTH] = (struct WarpData){roomGroup, roomId, warpId, -1, -1};
        roomGroup = Rooms[currentRoomIndex].id >> 8;
        roomId = Rooms[currentRoomIndex].id & 0xFF;
        warpId = Rooms[currentRoomIndex].warpIds[NORTH];
        realWarps[targetRoomIndex][SOUTH] = (struct WarpData){roomGroup, roomId, warpId, -1, -1};
        currentRoomIndex = targetRoomIndex;
    }
}

void SetCurrentRoomSeed() {
    tinymt32_t tinymt;
    tinymt.mat1 = MAT1;
    tinymt.mat2 = MAT2;
    tinymt.tmat = TMAT;
    tinymt32_init(&tinymt, seed);
    int seed2;
    int broke = 0;
    // burn an appropriate amount of RNs here.
    for (int i = 0; i < TOTAL_ROOMS; i++) {
        seed2 = tinymt32_generate_uint32(&tinymt);
        if (Rooms[i].id == CurrentAdjustedRoom) {
            CurrentAdjustedRoomIndex = i;
            broke = 1;
            break;
        }
    }
    if (broke == 0) {
        mgba_printf(MGBA_LOG_INFO, "never broke!");
    }
    currentRoomSeed.mat1 = MAT1;
    currentRoomSeed.mat2 = MAT2;
    currentRoomSeed.tmat = TMAT;
    //int seed2 = tinymt32_generate_uint32(&tinymt);
    tinymt32_init(&currentRoomSeed, seed2);
}

void MirrorMapData() {
    u16 currentRoom = gSaveBlock1Ptr->location.mapNum | (gSaveBlock1Ptr->location.mapGroup << 8);
    if (CurrentAdjustedRoom != currentRoom) {
        CurrentAdjustedRoom = currentRoom;
        SetCurrentRoomSeed();

        size_t mapevents_bytes = sizeof(struct MapEvents);
        memcpy(&AdjustedMapEvents, gMapHeader.events, mapevents_bytes);
        
        u8 num_objs = AdjustedMapEvents.objectEventCount;
        if (num_objs > MAX_OBJECTS) {
            mgba_printf(MGBA_LOG_INFO, "num_objs > MAX_OBJECTS, shit is broken: %d", num_objs);
        } else {
            size_t objs_bytes = num_objs * sizeof(struct ObjectEventTemplate);
            memcpy(&AdjustedTemplates, AdjustedMapEvents.objectEvents, objs_bytes);
            AdjustedMapEvents.objectEvents = &AdjustedTemplates[0];
        }
    }

    gMapHeader.events = &AdjustedMapEvents;
}

void DeclareTrainer(u8 objNum) {
    MirrorMapData();

    int i = tinymt32_generate_uint32(&currentRoomSeed) % POSSIBLE_TRAINERS;

    struct TrainerTemplate tt = qTrainers[i];

    AdjustedObjects[objNum].t.trainer.aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY;
    AdjustedObjects[objNum].t.trainer.doubleBattle = FALSE;
    AdjustedObjects[objNum].t.trainer.encounterMusic_gender = tt.encounterMusic_gender;
    AdjustedObjects[objNum].t.trainer.trainerClass = tt.trainerClass;
    AdjustedObjects[objNum].t.trainer.trainerPic = tt.trainerPic;
    if (tt.rarity == 0) {
        AdjustedObjects[objNum].t.trainer.partyFlags = tt.partyFlags;
        AdjustedObjects[objNum].t.trainer.partySize = tt.partySize;

        int move_bytes = tt.partySize;
        switch (tt.partyFlags & 3) {
            case 0:
                move_bytes *= sizeof(struct TrainerMonNoItemDefaultMoves);
                memcpy(&AdjustedObjects[objNum].t.party, tt.party.NoItemDefaultMoves, move_bytes);
                for (int i = 0; i < tt.partySize; i++) {
                    AdjustedObjects[objNum].t.party.NoItemDefaultMoves[i].lvl = distances[CurrentAdjustedRoomIndex] + 1;
                }
                AdjustedObjects[objNum].t.trainer.party.NoItemDefaultMoves = &AdjustedObjects[objNum].t.party;
                break;
            case F_TRAINER_PARTY_CUSTOM_MOVESET:
                move_bytes *= sizeof(struct TrainerMonNoItemCustomMoves);
                memcpy(&AdjustedObjects[objNum].t.party, tt.party.NoItemCustomMoves, move_bytes);
                for (int i = 0; i < tt.partySize; i++) {
                    AdjustedObjects[objNum].t.party.NoItemCustomMoves[i].lvl = distances[CurrentAdjustedRoomIndex] + 1;
                }
                AdjustedObjects[objNum].t.trainer.party.NoItemCustomMoves = &AdjustedObjects[objNum].t.party;
                break;
            case F_TRAINER_PARTY_HELD_ITEM:
                move_bytes *= sizeof(struct TrainerMonItemDefaultMoves);
                memcpy(&AdjustedObjects[objNum].t.party, tt.party.ItemDefaultMoves, move_bytes);
                for (int i = 0; i < tt.partySize; i++) {
                    AdjustedObjects[objNum].t.party.ItemDefaultMoves[i].lvl = distances[CurrentAdjustedRoomIndex] + 1;
                }
                AdjustedObjects[objNum].t.trainer.party.ItemDefaultMoves = &AdjustedObjects[objNum].t.party;
                break;
            case F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET:
                move_bytes *= sizeof(struct TrainerMonItemCustomMoves);
                memcpy(&AdjustedObjects[objNum].t.party, tt.party.ItemCustomMoves, move_bytes);
                for (int i = 0; i < tt.partySize; i++) {
                    AdjustedObjects[objNum].t.party.ItemCustomMoves[i].lvl = distances[CurrentAdjustedRoomIndex] + 1;
                }
                AdjustedObjects[objNum].t.trainer.party.ItemCustomMoves = &AdjustedObjects[objNum].t.party;
                break;
        }
    } else {
        AdjustedObjects[objNum].t.trainer.partyFlags = 0;
        AdjustedObjects[objNum].t.trainer.partySize = 2;
        for (int i = 0; i < AdjustedObjects[objNum].t.trainer.partySize; i++) {
            AdjustedObjects[objNum].t.party.NoItemDefaultMoves[i].iv = 0;
            AdjustedObjects[objNum].t.party.NoItemDefaultMoves[i].lvl = distances[CurrentAdjustedRoomIndex] + 1;
            int r = tinymt32_generate_uint32(&currentRoomSeed) % 20;
            int s = TrainerMonTypes[tt.type1][r];
            AdjustedObjects[objNum].t.party.NoItemDefaultMoves[i].species = s;
        }
        AdjustedObjects[objNum].t.trainer.party.NoItemDefaultMoves = &AdjustedObjects[objNum].t.party.NoItemDefaultMoves;
    }
    AdjustedObjects[objNum].t.defeatText = tt.defeatText;
    AdjustedObjects[objNum].t.introText = tt.introText;
    AdjustedObjects[objNum].t.name = tt.trainerName;
    AdjustedTemplates[objNum].graphicsId = tt.graphicsId;
}

const u8 *GetAdjustedTrainerIntroText(u16 objNum) {
    if (objNum < MAX_OBJECTS) {
        return AdjustedObjects[objNum].t.introText;
    }
    return unknown_string;
}

const u8 *GetAdjustedTrainerDefeatText(u16 objNum) {
    if (objNum < MAX_OBJECTS) {
        return AdjustedObjects[objNum].t.defeatText;
    }
    return unknown_string;
}

const u8 *GetRedirectTrainerName(u16 index) {
    u16 objNum = index - 1;
    if (objNum < MAX_OBJECTS) {
        return AdjustedObjects[objNum].t.name;
    }
    return unknown_string;
}

struct Trainer RedirectTrainer(u16 index) {
    u16 objNum = index - 1;
    if (objNum < MAX_OBJECTS) {
        return AdjustedObjects[objNum].t.trainer;
    }
    return gTrainers[index];
}

void DeclareWildMon(u8 objNum) {
    MirrorMapData();
    int i = tinymt32_generate_uint32(&currentRoomSeed) % 809;
    AdjustedObjects[objNum].wm.NoItemDefaultMoves.iv = 15;
    AdjustedObjects[objNum].wm.NoItemDefaultMoves.lvl = distances[CurrentAdjustedRoomIndex] + 1;
    AdjustedObjects[objNum].wm.NoItemDefaultMoves.species = i + 1;
    AdjustedTemplates[objNum].graphicsId = OBJ_EVENT_GFX_POKEMON_001 + i;
}

u8 GetAdjustedWildMonLevel(u8 objNum) {
    return AdjustedObjects[objNum].wm.NoItemDefaultMoves.lvl;
}

u16 GetAdjustedWildMonSpecies(u8 objNum) {
    return AdjustedObjects[objNum].wm.NoItemDefaultMoves.species;
}

void NotifyShufflerChangedRoom() {
    CurrentAdjustedRoom = -1;
    CurrentAdjustedRoomIndex = -1;
    // When a pokemon encounter happens, AI data from the last trainer faced is read.
    // If we've switched rooms since fighting a trainer, this could be an invalid value,
    // so just 0 it out here.
    // I don't actually know if the AI flags are used or not during the wild battle.
    gTrainerBattleOpponent_A = 0;
    gTrainerBattleOpponent_B = 0;
}

void RedirectShuffledWarp(struct WarpData *warp) {
    // We skip the first two warp redirects.
    // The first warp places the player in the truck.
    // The second warp takes the player from the truck to littleroot town.
    static int warpSkips = 0;
    if (warpSkips < 2) {
        warpSkips++;
        return;
    }
    int fromIndex = -1;
    int roomId = (warp->mapGroup << 8) | warp->mapNum;
    for (int i = 0; i < TOTAL_ROOMS; i++) {
        if (Rooms[i].id == roomId) {
            fromIndex = i;
            break;
        }
    }
    if (fromIndex == -1) {
        mgba_printf(MGBA_LOG_INFO, "unknown warp {%d, %d, %d, %d, %d}", warp->mapGroup, warp->mapNum, warp->warpId, warp->x, warp->y);
        return;
    }
    int leavingDirection = warp->warpId;
    struct WarpData w = realWarps[fromIndex][leavingDirection];
    warp->mapGroup = w.mapGroup;
    warp->mapNum = w.mapNum;
    warp->warpId = w.warpId;
    warp->x = w.x;
    warp->y = w.y;
}
