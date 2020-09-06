#include "global.h"
#include "shuffler.h"
#include "random.h"
#include "species.h"

static const u16 possibleStarters[41] = {
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

u16 realStarterMon[3] = 
{
    0,0,0
};

void Shuffle() {
    u8 i = 0;
    while (TRUE) {
        u16 r = Random() & 63;
        if (r > 41) {
            continue;
        }
        /*
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
        */
        realStarterMon[i] = possibleStarters[r];
        i++;
        if (i == 3) {
            break;
        }
    }
}
