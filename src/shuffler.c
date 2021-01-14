#include "global.h"
#include "shuffler.h"
#include "random.h"
#include "tinymt32.h"

#include "printf.h"
#include "mgba.h"

static const u16 possibleStarters[107] = {
    SPECIES_BULBASAUR,
    SPECIES_CHARMANDER,
    SPECIES_SQUIRTLE,
    SPECIES_CATERPIE,
    SPECIES_WEEDLE,
    SPECIES_PIDGEY,
    SPECIES_PICHU,
    SPECIES_NIDORAN_F,
    SPECIES_NIDORAN_M,
    SPECIES_CLEFFA,
    SPECIES_IGGLYBUFF,
    SPECIES_ZUBAT,
    SPECIES_ODDISH,
    SPECIES_POLIWAG,
    SPECIES_ABRA,
    SPECIES_MACHOP,
    SPECIES_BELLSPROUT,
    SPECIES_GEODUDE,
    SPECIES_GEODUDE_ALOLAN,
    SPECIES_MAGNEMITE,
    SPECIES_GASTLY,
    SPECIES_TYROGUE,
    SPECIES_RHYHORN,
    SPECIES_HAPPINY,
    SPECIES_HORSEA,
    SPECIES_ELEKID,
    SPECIES_MAGBY,
    SPECIES_EEVEE,
    SPECIES_PORYGON,
    SPECIES_DRATINI,
    SPECIES_CHIKORITA,
    SPECIES_CYNDAQUIL,
    SPECIES_TOTODILE,
    SPECIES_TOGEPI,
    SPECIES_MAREEP,
    SPECIES_AZURILL,
    SPECIES_HOPPIP,
    SPECIES_SWINUB,
    SPECIES_LARVITAR,
    SPECIES_TREECKO,
    SPECIES_TORCHIC,
    SPECIES_MUDKIP,
    SPECIES_WURMPLE,
    SPECIES_LOTAD,
    SPECIES_SEEDOT,
    SPECIES_RALTS,
    SPECIES_SLAKOTH,
    SPECIES_NINCADA,
    SPECIES_WHISMUR,
    SPECIES_ARON,
    SPECIES_BUDEW,
    SPECIES_TRAPINCH,
    SPECIES_DUSKULL,
    SPECIES_SPHEAL,
    SPECIES_BAGON,
    SPECIES_BELDUM,
    SPECIES_TURTWIG,
    SPECIES_MONFERNO,
    SPECIES_PIPLUP,
    SPECIES_STARLY,
    SPECIES_SHINX,
    SPECIES_BUDEW,
    SPECIES_GIBLE,
    SPECIES_SNIVY,
    SPECIES_TEPIG,
    SPECIES_OSHAWOTT,
    SPECIES_LILLIPUP,
    SPECIES_PIDOVE,
    SPECIES_ROGGENROLA,
    SPECIES_TIMBURR,
    SPECIES_TYMPOLE,
    SPECIES_SEWADDLE,
    SPECIES_VENIPEDE,
    SPECIES_SANDILE,
    SPECIES_GOTHITA,
    SPECIES_SOLOSIS,
    SPECIES_VANILLITE,
    SPECIES_KLINK,
    SPECIES_TYNAMO,
    SPECIES_LITWICK,
    SPECIES_AXEW,
    SPECIES_DEINO,
    SPECIES_CHESPIN,
    SPECIES_FENNEKIN,
    SPECIES_FROAKIE,
    SPECIES_FLETCHLING,
    SPECIES_SCATTERBUG,
    SPECIES_FLABEBE,
    SPECIES_HONEDGE,
    SPECIES_GOOMY,
    SPECIES_ROWLET,
    SPECIES_LITTEN,
    SPECIES_POPPLIO,
    SPECIES_PIKIPEK,
    SPECIES_GRUBBIN,
    SPECIES_BOUNSWEET,
    SPECIES_JANGMO_O,
    SPECIES_COSMOG,
    SPECIES_GROOKEY,
    SPECIES_SCORBUNNY,
    SPECIES_SOBBLE,
    SPECIES_ROOKIDEE,
    SPECIES_BLIPBUG,
    SPECIES_ROLYCOLY,
    SPECIES_HATENNA,
    SPECIES_IMPIDIMP,
    SPECIES_DREEPY
};

EWRAM_DATA u16 realStarterMon[3] = { 0, 0, 0 };

void Shuffle() {
    mgba_printf(MGBA_LOG_INFO, "hello from Shuffle()!");
    tinymt32_t tinymt;
    tinymt.mat1 = 0x8f7011ee;
    tinymt.mat2 = 0xfc78ff1f;
    tinymt.tmat = 0x3793fdff;
    int seed = Random32();
    tinymt32_init(&tinymt, seed);
    mgba_printf(MGBA_LOG_INFO, "seed: %u", seed);

    int r;
    for (int i = 0; i < 3; ) {
        r = tinymt32_generate_uint32(&tinymt) % 107;
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
