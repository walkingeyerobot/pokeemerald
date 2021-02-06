static const u8 unknown_string[] = _("unknown");

static const struct TrainerMonNoItemDefaultMoves tt1Party[] = {
    {
    .iv = 0,
    .lvl = 1,
    .species = SPECIES_ZUBAT,
    },
    {
    .iv = 0,
    .lvl = 1,
    .species = SPECIES_GEODUDE,
    }
};
static const u8 tt1IntroText[] = _("test intro 1");
static const u8 tt1DefeatText[] = _("test defeat 1");
static const u8 tt1Name[] = _("TestGuy");
static const struct TrainerTemplate tt1 = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_HIKER,
    .trainerName = tt1Name,
    .partySize = 2,
    .party = {.NoItemDefaultMoves = tt1Party},
    .type1 = 0,
    .type2 = 0,
    .rarity = 0,
    .introText = tt1IntroText,
    .defeatText = tt1DefeatText,
    .graphicsId = OBJ_EVENT_GFX_LITTLE_BOY,
};


static const u8 ttNormalIntroText[] = _("My name is Norman so I legally have to\nuse Normal types.");
static const u8 ttNormalDefeatText[] = _("I hate being Norman.");
static const u8 ttNormalName[] = _("Norman");
static const struct TrainerTemplate ttNormal = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_GENTLEMAN,
    .trainerName = ttNormalName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_NORMAL,
    .type2 = 0,
    .rarity = 1,
    .introText = ttNormalIntroText,
    .defeatText = ttNormalDefeatText,
    .graphicsId = OBJ_EVENT_GFX_GENTLEMAN,
};


static const u8 ttFightingIntroText[] = _("Number one super guy!");
static const u8 ttFightingDefeatText[] = _("I got cancelled in 1976.");
static const u8 ttFightingName[] = _("HK Phooey");
static const struct TrainerTemplate ttFighting = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BLACK_BELT,
    .trainerName = ttFightingName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_FIGHTING,
    .type2 = 0,
    .rarity = 1,
    .introText = ttFightingIntroText,
    .defeatText = ttFightingDefeatText,
    .graphicsId = OBJ_EVENT_GFX_BLACK_BELT,
};


static const u8 ttFlyingIntroText[] = _("Toucan play at this game!");
static const u8 ttFlyingDefeatText[] = _("I guess birds really are sky garbage.");
static const u8 ttFlyingName[] = _("Robin");
static const struct TrainerTemplate ttFlying = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BIRD_KEEPER,
    .trainerName = ttFlyingName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_FLYING,
    .type2 = 0,
    .rarity = 1,
    .introText = ttFlyingIntroText,
    .defeatText = ttFlyingDefeatText,
    .graphicsId = OBJ_EVENT_GFX_FISHERMAN,
};


static const u8 ttPoisonIntroText[] = _("A hug without U is just toxic!");
static const u8 ttPoisonDefeatText[] = _("Get it because Hg is the chemical\nsymbol for mercury.");
static const u8 ttPoisonName[] = _("Venus");
static const struct TrainerTemplate ttPoison = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
    .trainerName = ttPoisonName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_POISON,
    .type2 = 0,
    .rarity = 1,
    .introText = ttPoisonIntroText,
    .defeatText = ttPoisonDefeatText,
    .graphicsId = OBJ_EVENT_GFX_AQUA_MEMBER_F,
};


static const u8 ttGroundIntroText[] = _("Have you been adding soil to my garden?");
static const u8 ttGroundDefeatText[] = _("The plot thickens.");
static const u8 ttGroundName[] = _("Harry");
static const struct TrainerTemplate ttGround = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_RUIN_MANIAC,
    .trainerName = ttGroundName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_GROUND,
    .type2 = 0,
    .rarity = 1,
    .introText = ttGroundIntroText,
    .defeatText = ttGroundDefeatText,
    .graphicsId = OBJ_EVENT_GFX_SCIENTIST_1,
};


static const u8 ttRockIntroText[] = _("ROCK and roll!");
static const u8 ttRockDefeatText[] = _("I am sad now.");
static const u8 ttRockName[] = _("Mike");
static const struct TrainerTemplate ttRock = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_HIKER,
    .trainerName = ttRockName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_ROCK,
    .type2 = 0,
    .rarity = 1,
    .introText = ttRockIntroText,
    .defeatText = ttRockDefeatText,
    .graphicsId = OBJ_EVENT_GFX_HIKER,
};

static const u8 ttBugIntroText[] = _("You're buggin' me.");
static const u8 ttBugDefeatText[] = _("Buzz off.");
static const u8 ttBugName[] = _("Jeff");
static const struct TrainerTemplate ttBug = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BUG_CATCHER,
    .trainerName = ttBugName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_BUG,
    .type2 = 0,
    .rarity = 1,
    .introText = ttBugIntroText,
    .defeatText = ttBugDefeatText,
    .graphicsId = OBJ_EVENT_GFX_BUG_CATCHER,
};


static const u8 ttGhostIntroText[] = _("You're in for a spooktacular battle!");
static const u8 ttGhostDefeatText[] = _("My favorite holiday is actually\nCanadian Thanksgiving.");
static const u8 ttGhostName[] = _("Cathrine");
static const struct TrainerTemplate ttGhost = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_HEX_MANIAC,
    .trainerName = ttGhostName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_GHOST,
    .type2 = 0,
    .rarity = 1,
    .introText = ttGhostIntroText,
    .defeatText = ttGhostDefeatText,
    .graphicsId = OBJ_EVENT_GFX_HEX_MANIAC,
};


static const u8 ttSteelIntroText[] = _("Steel yourself.");
static const u8 ttSteelDefeatText[] = _("You steeled that victory from me.");
static const u8 ttSteelName[] = _("Steve");
static const struct TrainerTemplate ttSteel = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_NINJA_BOY,
    .trainerName = ttSteelName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_STEEL,
    .type2 = 0,
    .rarity = 1,
    .introText = ttSteelIntroText,
    .defeatText = ttSteelDefeatText,
    .graphicsId = OBJ_EVENT_GFX_NINJA_BOY,
};


static const u8 ttFireIntroText[] = _("Man it's a hot one.");
static const u8 ttFireDefeatText[] = _("Like seven inches from the midday\nsun.");
static const u8 ttFireName[] = _("Rob");
static const struct TrainerTemplate ttFire = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
    .trainerName = ttFireName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_FIRE,
    .type2 = 0,
    .rarity = 1,
    .introText = ttFireIntroText,
    .defeatText = ttFireDefeatText,
    .graphicsId = OBJ_EVENT_GFX_MAGMA_MEMBER_M,
};


static const u8 ttWaterIntroText[] = _("Splish splash!");
static const u8 ttWaterDefeatText[] = _("I'm just a small child.");
static const u8 ttWaterName[] = _("Tommy");
static const struct TrainerTemplate ttWater = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_TUBER_M,
    .trainerName = ttWaterName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_WATER,
    .type2 = 0,
    .rarity = 1,
    .introText = ttWaterIntroText,
    .defeatText = ttWaterDefeatText,
    .graphicsId = OBJ_EVENT_GFX_TUBER_M,
};


static const u8 ttGrassIntroText[] = _("I'm over-dew for a win!");
static const u8 ttGrassDefeatText[] = _("I'm terrible at this.");
static const u8 ttGrassName[] = _("Mary");
static const struct TrainerTemplate ttGrass = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
    .trainerName = ttGrassName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_GRASS,
    .type2 = 0,
    .rarity = 1,
    .introText = ttGrassIntroText,
    .defeatText = ttGrassDefeatText,
    .graphicsId = OBJ_EVENT_GFX_WOMAN_2,
};


static const u8 ttElectricIntroText[] = _("This is my shocked face.");
static const u8 ttElectricDefeatText[] = _("I'll have to charge you double for that.");
static const u8 ttElectricName[] = _("Jack");
static const struct TrainerTemplate ttElectric = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_GUITARIST,
    .trainerName = ttElectricName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_ELECTRIC,
    .type2 = 0,
    .rarity = 1,
    .introText = ttElectricIntroText,
    .defeatText = ttElectricDefeatText,
    .graphicsId = OBJ_EVENT_GFX_MAN_5,
};


static const u8 ttPsychicIntroText[] = _("You're doing fine, but how am I?");
static const u8 ttPsychicDefeatText[] = _("It's hard to find the happy medium.");
static const u8 ttPsychicName[] = _("Tina");
static const struct TrainerTemplate ttPsychic = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_PSYCHIC_F,
    .trainerName = ttPsychicName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_PSYCHIC,
    .type2 = 0,
    .rarity = 1,
    .introText = ttPsychicIntroText,
    .defeatText = ttPsychicDefeatText,
    .graphicsId = OBJ_EVENT_GFX_LASS,
};


static const u8 ttIceIntroText[] = _("ICE to meet you!");
static const u8 ttIceDefeatText[] = _("That wasn't very ICE of you.");
static const u8 ttIceName[] = _("Sam");
static const struct TrainerTemplate ttIce = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_POKEFAN_F,
    .trainerName = ttIceName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_ICE,
    .type2 = 0,
    .rarity = 1,
    .introText = ttIceIntroText,
    .defeatText = ttIceDefeatText,
    .graphicsId = OBJ_EVENT_GFX_POKEFAN_F,
};


static const u8 ttDragonIntroText[] = _("Quit DRAGON your feet and fight me.");
static const u8 ttDragonDefeatText[] = _("Dragons can't blow out birthday candles.");
static const u8 ttDragonName[] = _("Drake");
static const struct TrainerTemplate ttDragon = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_DRAGON_TAMER,
    .trainerName = ttDragonName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_DRAGON,
    .type2 = 0,
    .rarity = 1,
    .introText = ttDragonIntroText,
    .defeatText = ttDragonDefeatText,
    .graphicsId = OBJ_EVENT_GFX_MAN_3,
};


static const u8 ttDarkIntroText[] = _("I have a dark sense of humor.");
static const u8 ttDarkDefeatText[] = _("I can't see what's so funny.");
static const u8 ttDarkName[] = _("Donnie");
static const struct TrainerTemplate ttDark = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_POKEMANIAC,
    .trainerName = ttDarkName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_DARK,
    .type2 = 0,
    .rarity = 1,
    .introText = ttDarkIntroText,
    .defeatText = ttDarkDefeatText,
    .graphicsId = OBJ_EVENT_GFX_MANIAC,
};


static const u8 ttFairyIntroText[] = _("This is a fairly odd game, don't you think?");
static const u8 ttFairyDefeatText[] = _("No fairy-tale ending for me.");
static const u8 ttFairyName[] = _("Anabel");
static const struct TrainerTemplate ttFairy = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_SALON_MAIDEN_ANABEL,
    .trainerName = ttFairyName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_FAIRY,
    .type2 = 0,
    .rarity = 1,
    .introText = ttFairyIntroText,
    .defeatText = ttFairyDefeatText,
    .graphicsId = OBJ_EVENT_GFX_ANABEL,
};

#ifdef __wasm__
static const struct TrainerTemplate *qTrainers[POSSIBLE_TRAINERS] = {
    &ttNormal,
    &ttFighting,
    &ttFlying,
    &ttPoison,
    &ttGround,
    &ttRock,
    &ttBug,
    &ttGhost,
    &ttSteel,
    &ttFire,
    &ttWater,
    &ttGrass,
    &ttElectric,
    &ttPsychic,
    &ttIce,
    &ttDragon,
    &ttDark,
    &ttFairy
};
#else
static const struct TrainerTemplate qTrainers[POSSIBLE_TRAINERS] = {
    ttNormal,
    ttFighting,
    ttFlying,
    ttPoison,
    ttGround,
    ttRock,
    ttBug,
    ttGhost,
    ttSteel,
    ttFire,
    ttWater,
    ttGrass,
    ttElectric,
    ttPsychic,
    ttIce,
    ttDragon,
    ttDark,
    ttFairy
};
#endif

static const int TrainerMonTypes[19][20] = {
    [TYPE_NORMAL] = {
        SPECIES_PIDGEY,
        SPECIES_RATTATA,
        SPECIES_SPEAROW,
        SPECIES_JIGGLYPUFF,
        SPECIES_MEOWTH,
        SPECIES_FARFETCHD,
        SPECIES_DODUO,
        SPECIES_LICKITUNG,
        SPECIES_CHANSEY,
        SPECIES_KANGASKHAN,
        SPECIES_TAUROS,
        SPECIES_DITTO,
        SPECIES_EEVEE,
        SPECIES_PORYGON,
        SPECIES_SNORLAX,
        SPECIES_SENTRET,
        SPECIES_HOOTHOOT,
        SPECIES_AIPOM,
        SPECIES_GIRAFARIG,
        SPECIES_DUNSPARCE
    },
    [TYPE_FIGHTING] = {
        SPECIES_MANKEY,
        SPECIES_MACHOP,
        SPECIES_FARFETCHD_GALARIAN,
        SPECIES_HITMONLEE,
        SPECIES_HITMONCHAN,
        SPECIES_ZAPDOS_GALARIAN,
        SPECIES_HERACROSS,
        SPECIES_HITMONTOP,
        SPECIES_COMBUSKEN,
        SPECIES_MAKUHITA,
        SPECIES_MEDITITE,
        SPECIES_RIOLU,
        SPECIES_CROAGUNK,
        SPECIES_TIMBURR,
        SPECIES_THROH,
        SPECIES_SAWK,
        SPECIES_SCRAGGY,
        SPECIES_MIENFOO,
        SPECIES_COBALION,
        SPECIES_TERRAKION
    },
    [TYPE_FLYING] = {
        SPECIES_PIDGEY,
        SPECIES_SPEAROW,
        SPECIES_ZUBAT,
        SPECIES_FARFETCHD,
        SPECIES_DODUO,
        SPECIES_SCYTHER,
        SPECIES_AERODACTYL,
        SPECIES_ARTICUNO,
        SPECIES_ARTICUNO_GALARIAN,
        SPECIES_ZAPDOS,
        SPECIES_ZAPDOS_GALARIAN,
        SPECIES_MOLTRES,
        SPECIES_MOLTRES_GALARIAN,
        SPECIES_HOOTHOOT,
        SPECIES_LEDYBA,
        SPECIES_NATU,
        SPECIES_HOPPIP,
        SPECIES_YANMA,
        SPECIES_MURKROW,
        SPECIES_GLIGAR
    },
    [TYPE_POISON] = {
        SPECIES_BULBASAUR,
        SPECIES_WEEDLE,
        SPECIES_EKANS,
        SPECIES_NIDORAN_M,
        SPECIES_NIDORAN_F,
        SPECIES_ZUBAT,
        SPECIES_ODDISH,
        SPECIES_VENONAT,
        SPECIES_BELLSPROUT,
        SPECIES_TENTACOOL,
        SPECIES_GRIMER,
        SPECIES_GRIMER_ALOLAN,
        SPECIES_GASTLY,
        SPECIES_KOFFING,
        SPECIES_SPINARAK,
        SPECIES_QWILFISH,
        SPECIES_BUDEW,
        SPECIES_GULPIN,
        SPECIES_SEVIPER,
        SPECIES_STUNKY
    },
    [TYPE_GROUND] = {
        SPECIES_SANDSHREW,
        SPECIES_DIGLETT,
        SPECIES_DIGLETT_ALOLAN,
        SPECIES_GEODUDE,
        SPECIES_ONIX,
        SPECIES_CUBONE,
        SPECIES_RHYHORN,
        SPECIES_WOOPER,
        SPECIES_GLIGAR,
        SPECIES_SWINUB,
        SPECIES_PHANPY,
        SPECIES_LARVITAR,
        SPECIES_NINCADA,
        SPECIES_NUMEL,
        SPECIES_TRAPINCH,
        SPECIES_BARBOACH,
        SPECIES_BALTOY,
        SPECIES_GROUDON,
        SPECIES_GIBLE,
        SPECIES_HIPPOPOTAS
    },
    [TYPE_ROCK] = {
        SPECIES_GEODUDE,
        SPECIES_GEODUDE_ALOLAN,
        SPECIES_ONIX,
        SPECIES_RHYHORN,
        SPECIES_OMANYTE,
        SPECIES_KABUTO,
        SPECIES_AERODACTYL,
        SPECIES_SUDOWOODO,
        SPECIES_SHUCKLE,
        SPECIES_CORSOLA,
        SPECIES_LARVITAR,
        SPECIES_NOSEPASS,
        SPECIES_ARON,
        SPECIES_LUNATONE,
        SPECIES_SOLROCK,
        SPECIES_LILEEP,
        SPECIES_ANORITH,
        SPECIES_RELICANTH,
        SPECIES_REGIROCK,
        SPECIES_CRANIDOS
    },
    [TYPE_BUG] = {
        SPECIES_CATERPIE,
        SPECIES_WEEDLE,
        SPECIES_PARAS,
        SPECIES_VENONAT,
        SPECIES_SCYTHER,
        SPECIES_PINSIR,
        SPECIES_LEDYBA,
        SPECIES_SPINARAK,
        SPECIES_PINECO,
        SPECIES_SHUCKLE,
        SPECIES_HERACROSS,
        SPECIES_WURMPLE,
        SPECIES_SURSKIT,
        SPECIES_NINCADA,
        SPECIES_VOLBEAT,
        SPECIES_ANORITH,
        SPECIES_KRICKETOT,
        SPECIES_BURMY,
        SPECIES_COMBEE,
        SPECIES_SKORUPI
    },
    [TYPE_GHOST] = {
        SPECIES_GASTLY,
        SPECIES_MISDREAVUS,
        SPECIES_CORSOLA_GALARIAN,
        SPECIES_SABLEYE,
        SPECIES_SHUPPET,
        SPECIES_DUSKULL,
        SPECIES_DRIFLOON,
        SPECIES_SPIRITOMB,
        SPECIES_ROTOM,
        SPECIES_GIRATINA,
        SPECIES_YAMASK,
        SPECIES_YAMASK_GALARIAN,
        SPECIES_FRILLISH,
        SPECIES_LITWICK,
        SPECIES_GOLETT,
        SPECIES_HONEDGE,
        SPECIES_PHANTUMP,
        SPECIES_PUMPKABOO,
        SPECIES_HOOPA,
        SPECIES_SANDYGAST
    },
    [TYPE_STEEL] = {
        SPECIES_SANDSHREW_ALOLAN,
        SPECIES_DIGLETT_ALOLAN,
        SPECIES_MEOWTH_GALARIAN,
        SPECIES_MAGNEMITE,
        SPECIES_SKARMORY,
        SPECIES_MAWILE,
        SPECIES_ARON,
        SPECIES_BELDUM,
        SPECIES_REGISTEEL,
        SPECIES_JIRACHI,
        SPECIES_SHIELDON,
        SPECIES_BRONZOR,
        SPECIES_DIALGA,
        SPECIES_HEATRAN,
        SPECIES_FERROSEED,
        SPECIES_KLINK,
        SPECIES_STUNFISK_GALARIAN,
        SPECIES_PAWNIARD,
        SPECIES_DURANT,
        SPECIES_COBALION
    },
    [TYPE_FIRE] = {
        SPECIES_CHARMANDER,
        SPECIES_VULPIX,
        SPECIES_GROWLITHE,
        SPECIES_PONYTA,
        SPECIES_MAGBY,
        SPECIES_MOLTRES,
        SPECIES_CYNDAQUIL,
        SPECIES_SLUGMA,
        SPECIES_HOUNDOUR,
        SPECIES_ENTEI,
        SPECIES_HO_OH,
        SPECIES_TORCHIC,
        SPECIES_NUMEL,
        SPECIES_TORKOAL,
        SPECIES_GROUDON_PRIMAL,
        SPECIES_CHIMCHAR,
        SPECIES_HEATRAN,
        SPECIES_VICTINI,
        SPECIES_TEPIG,
        SPECIES_PANSEAR
    },
    [TYPE_WATER] = {
        SPECIES_SQUIRTLE,
        SPECIES_PSYDUCK,
        SPECIES_POLIWAG,
        SPECIES_TENTACOOL,
        SPECIES_SLOWPOKE,
        SPECIES_SEEL,
        SPECIES_SHELLDER,
        SPECIES_KRABBY,
        SPECIES_HORSEA,
        SPECIES_GOLDEEN,
        SPECIES_STARYU,
        SPECIES_MAGIKARP,
        SPECIES_LAPRAS,
        SPECIES_OMANYTE,
        SPECIES_KABUTO,
        SPECIES_TOTODILE,
        SPECIES_CHINCHOU,
        SPECIES_WOOPER,
        SPECIES_QWILFISH,
        SPECIES_REMORAID
    },
    [TYPE_GRASS] = {
        SPECIES_BULBASAUR,
        SPECIES_ODDISH,
        SPECIES_PARAS,
        SPECIES_BELLSPROUT,
        SPECIES_EXEGGCUTE,
        SPECIES_TANGELA,
        SPECIES_CHIKORITA,
        SPECIES_HOPPIP,
        SPECIES_SUNKERN,
        SPECIES_CELEBI,
        SPECIES_TREECKO,
        SPECIES_LOTAD,
        SPECIES_SEEDOT,
        SPECIES_SHROOMISH,
        SPECIES_BUDEW,
        SPECIES_CACNEA,
        SPECIES_LILEEP,
        SPECIES_TROPIUS,
        SPECIES_TURTWIG,
        SPECIES_CHERUBI
    },
    [TYPE_ELECTRIC] = {
        SPECIES_PICHU,
        SPECIES_GEODUDE_ALOLAN,
        SPECIES_MAGNEMITE,
        SPECIES_VOLTORB,
        SPECIES_ELEKID,
        SPECIES_ZAPDOS,
        SPECIES_CHINCHOU,
        SPECIES_MAREEP,
        SPECIES_RAIKOU,
        SPECIES_ELECTRIKE,
        SPECIES_PLUSLE,
        SPECIES_MINUN,
        SPECIES_SHINX,
        SPECIES_PACHIRISU,
        SPECIES_ROTOM,
        SPECIES_BLITZLE,
        SPECIES_EMOLGA,
        SPECIES_JOLTIK,
        SPECIES_TYNAMO,
        SPECIES_STUNFISK
    },
    [TYPE_PSYCHIC] = {
        SPECIES_ABRA,
        SPECIES_PONYTA_GALARIAN,
        SPECIES_SLOWPOKE,
        SPECIES_SLOWPOKE_GALARIAN,
        SPECIES_DROWZEE,
        SPECIES_EXEGGCUTE,
        SPECIES_MIMEJR,
        SPECIES_MR_MIME_GALARIAN,
        SPECIES_SMOOCHUM,
        SPECIES_ARTICUNO_GALARIAN,
        SPECIES_MEWTWO,
        SPECIES_MEW,
        SPECIES_NATU,
        SPECIES_UNOWN,
        SPECIES_WYNAUT,
        SPECIES_GIRAFARIG,
        SPECIES_LUGIA,
        SPECIES_CELEBI,
        SPECIES_RALTS,
        SPECIES_MEDITITE
    },
    [TYPE_ICE] = {
        SPECIES_SANDSHREW_ALOLAN,
        SPECIES_VULPIX_ALOLAN,
        SPECIES_MR_MIME_GALARIAN,
        SPECIES_SMOOCHUM,
        SPECIES_LAPRAS,
        SPECIES_ARTICUNO,
        SPECIES_SNEASEL,
        SPECIES_SWINUB,
        SPECIES_DELIBIRD,
        SPECIES_SNORUNT,
        SPECIES_SPHEAL,
        SPECIES_REGICE,
        SPECIES_SNOVER,
        SPECIES_DARUMAKA_GALARIAN,
        SPECIES_VANILLITE,
        SPECIES_CUBCHOO,
        SPECIES_CRYOGONAL,
        SPECIES_KYUREM,
        SPECIES_AMAURA,
        SPECIES_BERGMITE
    },
    [TYPE_DRAGON] = {
        SPECIES_DRATINI,
        SPECIES_BAGON,
        SPECIES_LATIAS,
        SPECIES_LATIOS,
        SPECIES_RAYQUAZA,
        SPECIES_GIBLE,
        SPECIES_DIALGA,
        SPECIES_PALKIA,
        SPECIES_GIRATINA,
        SPECIES_AXEW,
        SPECIES_DRUDDIGON,
        SPECIES_DEINO,
        SPECIES_RESHIRAM,
        SPECIES_ZEKROM,
        SPECIES_KYUREM,
        SPECIES_TYRUNT,
        SPECIES_GOOMY,
        SPECIES_NOIBAT,
        SPECIES_ZYGARDE,
        SPECIES_TURTONATOR
    },
    [TYPE_DARK] = {
        SPECIES_RATTATA_ALOLAN,
        SPECIES_MEOWTH_ALOLAN,
        SPECIES_GRIMER_ALOLAN,
        SPECIES_MURKROW,
        SPECIES_SNEASEL,
        SPECIES_HOUNDOUR,
        SPECIES_POOCHYENA,
        SPECIES_ZIGZAGOON_GALARIAN,
        SPECIES_NUZLEAF,
        SPECIES_SABLEYE,
        SPECIES_CARVANHA,
        SPECIES_ABSOL,
        SPECIES_STUNKY,
        SPECIES_SPIRITOMB,
        SPECIES_DARKRAI,
        SPECIES_PURRLOIN,
        SPECIES_SANDILE,
        SPECIES_SCRAGGY,
        SPECIES_ZORUA,
        SPECIES_PAWNIARD
    },
    [TYPE_FAIRY] = {
        SPECIES_CLEFFA,
        SPECIES_IGGLYBUFF,
        SPECIES_MIMEJR,
        SPECIES_TOGEPI,
        SPECIES_AZURILL,
        SPECIES_SNUBBULL,
        SPECIES_RALTS,
        SPECIES_MAWILE,
        SPECIES_COTTONEE,
        SPECIES_FLABEBE,
        SPECIES_SPRITZEE,
        SPECIES_SWIRLIX,
        SPECIES_DEDENNE,
        SPECIES_CARBINK,
        SPECIES_KLEFKI,
        SPECIES_XERNEAS,
        SPECIES_DIANCIE,
        SPECIES_CUTIEFLY,
        SPECIES_MORELULL,
        SPECIES_MIMIKYU
    },
};
