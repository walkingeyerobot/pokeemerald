#include "global.h"
#include "shuffler.h"
#include "random.h"
#include "tinymt32.h"
#include "data.h"
#include "battle_setup.h"
#include "constants/trainers.h"
#include "constants/battle_ai.h"
#include "constants/event_objects.h"

#include "printf.h"
#include "mgba.h"

#include "data/shuffle_trainers.h"
#include "data/shuffle_starters.h"

EWRAM_DATA int seed;
EWRAM_DATA tinymt32_t currentRoomSeed;
EWRAM_DATA u16 realStarterMon[3];

EWRAM_DATA struct MapEvents AdjustedMapEvents;
EWRAM_DATA struct ObjectEventTemplate AdjustedTemplates[MAX_OBJECTS];
EWRAM_DATA u16 CurrentAdjustedRoom = 0xFFFF;

EWRAM_DATA union ShuffledObject AdjustedObjects[MAX_OBJECTS];

void Shuffle() {
    tinymt32_t tinymt;
    tinymt.mat1 = MAT1;
    tinymt.mat2 = MAT2;
    tinymt.tmat = TMAT;
    seed = Random32();
    tinymt32_init(&tinymt, seed);
    mgba_printf(MGBA_LOG_INFO, "seed: %u", seed);

    int r;
    r = tinymt32_generate_uint32(&tinymt); // burn one RN for room seed testing for now.
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
}

void SetCurrentRoomSeed() {
    tinymt32_t tinymt;
    tinymt.mat1 = MAT1;
    tinymt.mat2 = MAT2;
    tinymt.tmat = TMAT;
    tinymt32_init(&tinymt, seed);
    // burn an appropriate amount of RNs here.
    currentRoomSeed.mat1 = MAT1;
    currentRoomSeed.mat2 = MAT2;
    currentRoomSeed.tmat = TMAT;
    int seed2 = tinymt32_generate_uint32(&tinymt);
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
    AdjustedObjects[objNum].t.trainer.partyFlags = 0;
    AdjustedObjects[objNum].t.trainer.trainerClass = tt.trainerClass;
    AdjustedObjects[objNum].t.trainer.trainerPic = tt.trainerPic;
    if (tt.rarity == 0) {
        AdjustedObjects[objNum].t.trainer.partySize = 2;
        AdjustedObjects[objNum].t.trainer.party = tt.party;
    } else {
        AdjustedObjects[objNum].t.trainer.partySize = 1;
        AdjustedObjects[objNum].t.party.NoItemDefaultMoves[0].iv = 0;
        AdjustedObjects[objNum].t.party.NoItemDefaultMoves[0].lvl = 1;
        AdjustedObjects[objNum].t.party.NoItemDefaultMoves[0].species = SPECIES_CATERPIE;
        AdjustedObjects[objNum].t.trainer.party.NoItemDefaultMoves = &AdjustedObjects[objNum].t.party;
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
    AdjustedObjects[objNum].wm.NoItemDefaultMoves.lvl = 5;
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
    CurrentAdjustedRoom = 0;
    // When a pokemon encounter happens, AI data from the last trainer faced is read.
    // If we've switched rooms since fighting a trainer, this could be an invalid value,
    // so just 0 it out here.
    // I don't actually know if the AI flags are used or not during the wild battle.
    gTrainerBattleOpponent_A = 0;
    gTrainerBattleOpponent_B = 0;
}
