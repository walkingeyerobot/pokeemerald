#include "global.h"
#include "shuffler.h"
#include "random.h"
#include "constants/species.h"
#include "item.h"
#include "constants/items.h"

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

EWRAM_DATA struct WarpData realWarps[TOTAL_WARPS][2] = {};

void Shuffle() {
    u8 i = 0;
    u16 r = 0;
    realWarps[0][0] = (struct WarpData){0,9,0,-1,-1};
    realWarps[0][1] = (struct WarpData){0,9,1,-1,-1};
    realWarps[1][0] = (struct WarpData){1,0,1,-1,-1};
    realWarps[1][1] = (struct WarpData){1,2,0,-1,-1};
    while (TRUE) {
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
        mgba_printf(MGBA_LOG_DEBUG, "%d", possibleStarters[r]);
        realStarterMon[i] = possibleStarters[r];
        i++;
        if (i == 3) {
            break;
        }
    }

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
    u8 mid = (max + min) >> 1;
    struct WarpData w = realWarps[mid][0];
    while (min < max && min <= mid && mid <= max && max < TOTAL_WARPS && min < TOTAL_WARPS) {
        if (w.mapGroup < warp->mapGroup) {
            min = mid + 1;
        } else if (w.mapGroup > warp->mapGroup) {
            max = mid - 1;
        } else if (w.mapNum < warp->mapNum) {
            min = mid + 1;
        } else if (w.mapNum > warp->mapNum) {
            max = mid - 1;
        } else if (w.warpId > warp->mapNum) {
            min = mid + 1;
        } else if (w.warpId < warp->warpId) {
            max = mid - 1;
        } else {
            break;
        }
        mid = (max + min) >> 1;
        w = realWarps[mid][0];
    }
    if (w.mapGroup != warp->mapGroup || w.mapNum != warp->mapNum || w.warpId != warp->warpId) {
        return;
    }
    w = realWarps[mid][1];
    warp->mapGroup = w.mapGroup;
    warp->mapNum = w.mapNum;
    warp->warpId = w.warpId;
    warp->x = w.x;
    warp->y = w.y;
}
