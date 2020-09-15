#include "global.h"
#include "shuffler.h"
#include "random.h"
#include "constants/species.h"
#include "item.h"
#include "constants/items.h"
#include "data.h"
#include "constants/trainers.h"

#include "printf.h"
#include "mgba.h"

static const u16 possibleStarters[42] = {
    SPECIES_BULBASAUR,
    SPECIES_CHARMANDER,
    SPECIES_SQUIRTLE,
    SPECIES_CATERPIE,
    SPECIES_WEEDLE,
    SPECIES_PIDGEY,
    SPECIES_NIDORAN_F,
    SPECIES_NIDORAN_M,
    SPECIES_ODDISH,
    SPECIES_POLIWAG,
    SPECIES_ABRA,
    SPECIES_MACHOP,
    SPECIES_BELLSPROUT,
    SPECIES_GEODUDE,
    SPECIES_GASTLY,
    SPECIES_EEVEE,
    SPECIES_DRATINI,
    SPECIES_CHIKORITA,
    SPECIES_CYNDAQUIL,
    SPECIES_TOTODILE,
    SPECIES_ZUBAT,
    SPECIES_PICHU,
    SPECIES_CLEFFA,
    SPECIES_IGGLYBUFF,
    SPECIES_MAREEP,
    SPECIES_HOPPIP,
    SPECIES_HORSEA,
    SPECIES_LARVITAR,
    SPECIES_TREECKO,
    SPECIES_TORCHIC,
    SPECIES_MUDKIP,
    SPECIES_WURMPLE,
    SPECIES_LOTAD,
    SPECIES_SEEDOT,
    SPECIES_RALTS,
    SPECIES_SLAKOTH,
    SPECIES_AZURILL,
    SPECIES_ARON,
    SPECIES_TRAPINCH,
    SPECIES_SPHEAL,
    SPECIES_BAGON,
    SPECIES_BELDUM
};

EWRAM_DATA u16 realStarterMon[3] = 
{
    0,0,0
};

EWRAM_DATA struct Trainer savedTrainers[MAX_SAVED_TRAINERS];
EWRAM_DATA u16 savedTrainerIds[MAX_SAVED_TRAINERS];
EWRAM_DATA union TrainerMon savedTrainerParties[MAX_SAVED_TRAINERS];
EWRAM_DATA u8 nextSavedTrainer;

// this needs to be sorted.
EWRAM_DATA struct WarpData realWarps[TOTAL_WARPS][2] = {};

// values are indicies into realWarps.
// room index, north/south, into me / out of me
static const u8 Rooms[TOTAL_ROOMS][2][2] = {
    {{0,1},{-1,-1}}, // outside
    {{2,4},{1,0}},   // brendan 1f
    {{3,9},{4,2}},   // brendan 2f
    {{10,5},{9,3}},  // lab
    {{6,8},{5,10}},  // may 1f
    {{7,11},{8,6}},  // may 2f
    {{-1,-1},{11,7}} // oldale house
};

static const u16 RoomTrainers[TOTAL_ROOMS][MAX_TRAINERS_PER_ROOM] = {
    {TRAINER_NONE, TRAINER_NONE},     // outside
    {TRAINER_SAWYER_1, TRAINER_NONE}, // brendan 1f
    {TRAINER_NONE, TRAINER_NONE},     // brendan 2f
    {TRAINER_NONE, TRAINER_NONE},     // lab
    {TRAINER_NONE, TRAINER_NONE},     // may 1f
    {TRAINER_NONE, TRAINER_NONE},     // may 2f
    {TRAINER_NONE, TRAINER_NONE}      // oldale house
};

EWRAM_DATA u16 AdjustedTrainers[MAX_TRAINER_ID + 1][2] = {};

void Shuffle() {
    u16 i = 0;
    u16 r = 0;
    u8 visited = 1;
    u8 distance = 1;
    u8 j = 0;
    u16 r2 = 0;

    savedTrainerIds[0] = 0;
    savedTrainerIds[0] = 0;
    nextSavedTrainer = 0;

    realWarps[ 0][0] = (struct WarpData){0,9,1,-1,-1};
    realWarps[ 1][0] = (struct WarpData){1,0,1,-1,-1};
    realWarps[ 2][0] = (struct WarpData){1,0,2,-1,-1};
    realWarps[ 3][0] = (struct WarpData){1,1,0,-1,-1};
    realWarps[ 4][0] = (struct WarpData){1,1,1,-1,-1};
    realWarps[ 5][0] = (struct WarpData){1,2,0,-1,-1};
    realWarps[ 6][0] = (struct WarpData){1,2,2,-1,-1};
    realWarps[ 7][0] = (struct WarpData){1,3,0,-1,-1};
    realWarps[ 8][0] = (struct WarpData){1,3,1,-1,-1};
    realWarps[ 9][0] = (struct WarpData){1,4,0,-1,-1};
    realWarps[10][0] = (struct WarpData){1,4,2,-1,-1};
    realWarps[11][0] = (struct WarpData){2,0,0,-1,-1};

    for (i = 0; i < TOTAL_WARPS; i++) {
        mgba_printf(MGBA_LOG_INFO, "%d,%d,%d->%d,%d,%d", realWarps[i][0].mapGroup, realWarps[i][0].mapNum, realWarps[i][0].warpId, realWarps[i][1].mapGroup, realWarps[i][1].mapNum, realWarps[i][1].warpId);
    }
    i = 0;

    mgba_printf(MGBA_LOG_INFO, "ROOMS");
    mgba_printf(MGBA_LOG_INFO, "ADDING FIRST ROOM: %d", i);
    while(visited <= 63) {
        if (visited == 63) {
            mgba_printf(MGBA_LOG_INFO, "visited is == 63, %d, setting r = 6", visited);
            r = 6;
        } else {
            r = Random() % (TOTAL_ROOMS - 1);
            mgba_printf(MGBA_LOG_INFO, "rolled r = %d", r);
        }
        if (visited < 63) {
            mgba_printf(MGBA_LOG_INFO, "visited < 63, = %d", visited);
            if ((visited & (1 << r)) > 0) {
                mgba_printf(MGBA_LOG_INFO, "room already visited: %d %d %d", visited, r, visited & (1 << r));
                continue;
            }
        } else {
            mgba_printf(MGBA_LOG_INFO, "visited >= 63, = %d", visited);
        }

        visited |= 1 << r;
        mgba_printf(MGBA_LOG_INFO, "ADDING ROOM: %d", r);
        memcpy(&realWarps[Rooms[i][0][1]][1],
               &realWarps[Rooms[r][1][0]][0],
               sizeof(struct WarpData));
        memcpy(&realWarps[Rooms[r][1][1]][1],
               &realWarps[Rooms[i][0][0]][0],
               sizeof(struct WarpData));

        for (j = 0; j < MAX_TRAINERS_PER_ROOM; j++) {
            if (RoomTrainers[r][j] != TRAINER_NONE) {
                r2 = Random() % (MAX_TRAINER_ID + 1);
                mgba_printf(MGBA_LOG_INFO, "trainer found, mapping %d to %d, level %d", RoomTrainers[r][j], r2, distance);
                AdjustedTrainers[RoomTrainers[r][j]][0] = r2;
                AdjustedTrainers[RoomTrainers[r][j]][1] = distance;
            }
        }

        distance++;
        i = r;
    }
    mgba_printf(MGBA_LOG_INFO, "DONE ROOMS");
    for (i = 0; i < TOTAL_WARPS; i++) {
        mgba_printf(MGBA_LOG_INFO, "%d,%d,%d->%d,%d,%d", realWarps[i][0].mapGroup, realWarps[i][0].mapNum, realWarps[i][0].warpId, realWarps[i][1].mapGroup, realWarps[i][1].mapNum, realWarps[i][1].warpId);
    }
    i = 0;
    /*
    // OLDALE TOWN HOUSE
    (struct WarpData){1,3,0,-1,-1}; // to may 2f
    (struct WarpData){2,0,0,-1,-1}; // to oldale town house 1
    // MAY 2F
    (struct WarpData){1,2,2,-1,-1}; // to may 1f
    (struct WarpData){1,3,1,-1,-1}; // to may 2f
    // MAY 1F
    (struct WarpData){1,4,2,-1,-1}; // to lab
    (struct WarpData){1,2,0,-1,-1}; // to may 1f
    // LAB
    (struct WarpData){1,1,0,-1,-1}; // to brendan 2f
    (struct WarpData){1,4,0,-1,-1}; // to lab
    // BRENDAN 2F
    (struct WarpData){1,0,2,-1,-1}; // to brendan 1f
    (struct WarpData){1,1,1,-1,-1}; // to brendan 2f
    // BRENDAN 1F
    (struct WarpData){0,9,1,-1,-1}; // to outside
    (struct WarpData){1,0,1,-1,-1}; // to brendan 1f
    // START
    */

    i = 0;
    do {
        r = Random();
        r &= 63;
        if (r >= 42) {
            continue;
        }
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
        mgba_printf(MGBA_LOG_INFO, "%d", possibleStarters[r]);
        realStarterMon[i] = possibleStarters[r];
        i++;
    } while (i < 3);

    // add 3 random TMs / HMs
    i = 0;
    do {
        r = Random() & 63;
        if (r > 57) {
            continue;
        }
        i++;
        AddBagItem(r + 289, 1);
    } while (i < 3);

    AddBagItem(ITEM_POTION, 3);
    AddBagItem(ITEM_ELIXIR, 3);
    AddBagItem(ITEM_REVIVE, 1);

    // add 3 random berries
    i = 0;
    do {
        r = Random() & 63;
        if (r > 42) {
            continue;
        }
        i++;
        AddBagItem(r + 133, 1);
    } while (i < 3);

    // add 3 random battle items
    i = 0;
    do {
        r = Random() & 63;
        if (r > 46) {
            continue;
        }
        i++;
        AddBagItem(r + 179, 1);
    } while (i < 3);
}

void RedirectShuffledWarp(struct WarpData *warp) {
    u8 min = 0;
    u8 max = TOTAL_WARPS - 1;
    u8 mid;
    struct WarpData w;
    mgba_printf(MGBA_LOG_INFO, "looking for warp: %d,%d,%d", warp->mapGroup, warp->mapNum, warp->warpId);
    do {
        mid = (max + min) >> 1;
        w = realWarps[mid][0];
        if (w.mapGroup < warp->mapGroup) {
            min = mid + 1;
        } else if (w.mapGroup > warp->mapGroup) {
            max = mid - 1;
        } else if (w.mapNum < warp->mapNum) {
            min = mid + 1;
        } else if (w.mapNum > warp->mapNum) {
            max = mid - 1;
        } else if (w.warpId < warp->warpId) {
            min = mid + 1;
        } else if (w.warpId > warp->warpId) {
            max = mid - 1;
        } else {
            w = realWarps[mid][1];
            mgba_printf(MGBA_LOG_INFO, "redirecting: %d,%d,%d", w.mapGroup, w.mapNum, w.warpId);
            warp->mapGroup = w.mapGroup;
            warp->mapNum = w.mapNum;
            warp->warpId = w.warpId;
            warp->x = w.x;
            warp->y = w.y;
            return;
        }
    } while(min <= max && max < TOTAL_WARPS && min < TOTAL_WARPS);
    mgba_printf(MGBA_LOG_INFO, "not redirecting");
}

struct Trainer RedirectTrainer(u16 index) {
    size_t moves_bytes;
    u8 i;
    u16 newLevel;
    u16 newIndex;

    if (savedTrainerIds[0] == index) {
        return savedTrainers[0];
    } else if (savedTrainerIds[1] == index) {
        return savedTrainers[1];
    } else if (index > MAX_TRAINER_ID) {
        return gTrainers[index];
    }

    newIndex = AdjustedTrainers[index][0];
    newLevel = AdjustedTrainers[index][1];

    memcpy(&savedTrainers[nextSavedTrainer], &gTrainers[newIndex], sizeof(struct Trainer));

    switch(savedTrainers[nextSavedTrainer].partyFlags & 3) {
        case 0:
            moves_bytes = gTrainers[newIndex].partySize * sizeof(struct TrainerMonNoItemDefaultMoves);
            memcpy(&savedTrainerParties[nextSavedTrainer], gTrainers[newIndex].party.NoItemDefaultMoves, moves_bytes);
            for (i = 0; i < savedTrainers[nextSavedTrainer].partySize; i++) {
                savedTrainerParties[nextSavedTrainer].NoItemDefaultMoves[i].lvl = newLevel;
            }
            savedTrainers[nextSavedTrainer].party.NoItemDefaultMoves = &savedTrainerParties[nextSavedTrainer].NoItemDefaultMoves[0];
            break;
        case F_TRAINER_PARTY_CUSTOM_MOVESET:
            moves_bytes = gTrainers[newIndex].partySize * sizeof(struct TrainerMonNoItemCustomMoves);
            memcpy(&savedTrainerParties[nextSavedTrainer], gTrainers[newIndex].party.NoItemCustomMoves, moves_bytes);
            for (i = 0; i < savedTrainers[nextSavedTrainer].partySize; i++) {
                savedTrainerParties[nextSavedTrainer].NoItemCustomMoves[i].lvl = newLevel;
            }
            savedTrainers[nextSavedTrainer].party.NoItemCustomMoves = &savedTrainerParties[nextSavedTrainer].NoItemCustomMoves[0];
            break;
        case F_TRAINER_PARTY_HELD_ITEM:
            moves_bytes = gTrainers[newIndex].partySize * sizeof(struct TrainerMonItemDefaultMoves);
            memcpy(&savedTrainerParties[nextSavedTrainer], gTrainers[newIndex].party.ItemDefaultMoves, moves_bytes);
            for (i = 0; i < savedTrainers[nextSavedTrainer].partySize; i++) {
                savedTrainerParties[nextSavedTrainer].ItemDefaultMoves[i].lvl = newLevel;
            }
            savedTrainers[nextSavedTrainer].party.ItemDefaultMoves = &savedTrainerParties[nextSavedTrainer].ItemDefaultMoves[0];
            break;
        case F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET:
            moves_bytes = gTrainers[newIndex].partySize * sizeof(struct TrainerMonItemCustomMoves);
            memcpy(&savedTrainerParties[nextSavedTrainer], gTrainers[newIndex].party.ItemCustomMoves, moves_bytes);
            for (i = 0; i < savedTrainers[nextSavedTrainer].partySize; i++) {
                savedTrainerParties[nextSavedTrainer].ItemCustomMoves[i].lvl = newLevel;
            }
            savedTrainers[nextSavedTrainer].party.ItemCustomMoves = &savedTrainerParties[nextSavedTrainer].ItemCustomMoves[0];
            break;
    }

    i = nextSavedTrainer;
    nextSavedTrainer++;
    if (nextSavedTrainer == MAX_SAVED_TRAINERS) {
        nextSavedTrainer = 0;
    }

    return savedTrainers[i];
}
