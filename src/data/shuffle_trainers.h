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
static const u8 tt1Name[] = _("TT ONE");
static const struct TrainerTemplate tt1 = {
    .trainerClass = TRAINER_CLASS_HIKER,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_HIKER,
    .trainerName = &tt1Name,
    .party = {.NoItemDefaultMoves = tt1Party},
    .type1 = 0,
    .type2 = 0,
    .rarity = 0,
    .introText = &tt1IntroText,
    .defeatText = &tt1DefeatText,
    .graphicsId = OBJ_EVENT_GFX_LITTLE_BOY,
};


static const u8 tt2IntroText[] = _("test intro 2");
static const u8 tt2DefeatText[] = _("test defeat 2");
static const u8 tt2Name[] = _("TT TWO");
static const struct TrainerTemplate tt2 = {
    .trainerClass = TRAINER_CLASS_HIKER,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_HIKER,
    .trainerName = &tt2Name,
    .party = {},
    .type1 = TYPE_BUG,
    .type2 = 0,
    .rarity = 1,
    .introText = &tt2IntroText,
    .defeatText = &tt2DefeatText,
    .graphicsId = OBJ_EVENT_GFX_LITTLE_GIRL,
};

static const struct TrainerTemplate qTrainers[POSSIBLE_TRAINERS] = {
    tt1, tt2
};
