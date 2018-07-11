#ifndef GUARD_DATA_COSTUME_MENU_TABLES_H
#define GUARD_DATA_COSTUME_MENU_TABLES_H

enum CostumeOverworldTags
{
    COSTUME_TAG_LOCKED = 9999,
// Main Characters
    COSTUME_TAG_RED,
    COSTUME_TAG_LEAF,
    COSTUME_TAG_ETHAN,
    COSTUME_TAG_KRIS,
    COSTUME_TAG_LYRA,
    COSTUME_TAG_BRENDAN,
    COSTUME_TAG_MAY,
    COSTUME_TAG_LUCAS,
    COSTUME_TAG_DAWN,
// Professors
    COSTUME_TAG_PROF_OAK,
    COSTUME_TAG_PROF_ELM,
    COSTUME_TAG_PROF_BIRCH,
    COSTUME_TAG_PROF_ROWAN,
// Rivals
    COSTUME_TAG_GARRY_OAK,
    COSTUME_TAG_SILVER,
    COSTUME_TAG_WALLY,
    COSTUME_TAG_BARRY,
// Villainous Teams
    COSTUME_TAG_ROCKET_M,
    COSTUME_TAG_ROCKET_F,
    COSTUME_TAG_ARCHER,
    COSTUME_TAG_ARIANA,
    COSTUME_TAG_PETREL,
    COSTUME_TAG_PROTON,
    COSTUME_TAG_GIOVANNI,
    COSTUME_TAG_AQUA_M,
    COSTUME_TAG_AQUA_F,
    COSTUME_TAG_MATT,
    COSTUME_TAG_SHELLEY,
    COSTUME_TAG_ARCHIE,
    COSTUME_TAG_MAGMA_M,
    COSTUME_TAG_MAGMA_F,
    COSTUME_TAG_COURTNEY,
    COSTUME_TAG_TABITHA,
    COSTUME_TAG_MAXIE,
    COSTUME_TAG_GALACTIC_M,
    COSTUME_TAG_GALACTIC_F,
    COSTUME_TAG_SATURN,
    COSTUME_TAG_MARS,
    COSTUME_TAG_JUPITER,
    COSTUME_TAG_CHARON,
    COSTUME_TAG_CYRUS,
// Gym Leaders
    COSTUME_TAG_MISTY,
// Elite 4 + Champions
    COSTUME_TAG_LANCE
};

enum CostumeTrainerTags
{
// Main Characters
    COSTUME_TAG_T_RED = 11000,
    COSTUME_TAG_T_LEAF,
    COSTUME_TAG_T_ETHAN,
    COSTUME_TAG_T_KRIS,
    COSTUME_TAG_T_LYRA,
    COSTUME_TAG_T_BRENDAN,
    COSTUME_TAG_T_MAY,
    COSTUME_TAG_T_LUCAS,
    COSTUME_TAG_T_DAWN,
// Professors
    COSTUME_TAG_T_PROF_OAK,
    COSTUME_TAG_T_PROF_ELM,
    COSTUME_TAG_T_PROF_BIRCH,
    COSTUME_TAG_T_PROF_ROWAN,
// Rivals
    COSTUME_TAG_T_GARRY_OAK,
    COSTUME_TAG_T_SILVER,
    COSTUME_TAG_T_WALLY,
    COSTUME_TAG_T_BARRY,
// Villainous Teams
    COSTUME_TAG_T_ROCKET_M,
    COSTUME_TAG_T_ROCKET_F,
    COSTUME_TAG_T_ARCHER,
    COSTUME_TAG_T_ARIANA,
    COSTUME_TAG_T_PETREL,
    COSTUME_TAG_T_PROTON,
    COSTUME_TAG_T_GIOVANNI,
    COSTUME_TAG_T_AQUA_M,
    COSTUME_TAG_T_AQUA_F,
    COSTUME_TAG_T_MATT,
    COSTUME_TAG_T_SHELLEY,
    COSTUME_TAG_T_ARCHIE,
    COSTUME_TAG_T_MAGMA_M,
    COSTUME_TAG_T_MAGMA_F,
    COSTUME_TAG_T_COURTNEY,
    COSTUME_TAG_T_TABITHA,
    COSTUME_TAG_T_MAXIE,
    COSTUME_TAG_T_GALACTIC_M,
    COSTUME_TAG_T_GALACTIC_F,
    COSTUME_TAG_T_SATURN,
    COSTUME_TAG_T_MARS,
    COSTUME_TAG_T_JUPITER,
    COSTUME_TAG_T_CHARON,
    COSTUME_TAG_T_CYRUS,
// Gym Leaders
    COSTUME_TAG_T_MISTY,
// Elite 4 + Champions
    COSTUME_TAG_T_LANCE
};
const struct CompressedSpriteSheet sCostumeOverworldSpriteTable[NUMBER_OF_COSTUMES] =
{
// .data                       .size         .tag
    {gGraphics_Costume_Red,     512, COSTUME_TAG_RED},                  // (32x32/2) = 512 = 0x200
    {gGraphics_Costume_Lyra,    512, COSTUME_TAG_LYRA},
    {gGraphics_Costume_Lance,   512, COSTUME_TAG_LANCE},
    {gGraphics_Costume_Misty,   512, COSTUME_TAG_MISTY},
    {gGraphics_Costume_RocketM, 512, COSTUME_TAG_ROCKET_M},
    {gGraphics_Costume_RocketF, 512, COSTUME_TAG_ROCKET_F},
    {gGraphics_Costume_ProfOak, 512, COSTUME_TAG_PROF_OAK},
// duplicates
    {gGraphics_Costume_ProfOak, 512, COSTUME_TAG_PROF_OAK},
    {gGraphics_Costume_ProfOak, 512, COSTUME_TAG_PROF_OAK},
    {gGraphics_Costume_ProfOak, 512, COSTUME_TAG_PROF_OAK},
    {gGraphics_Costume_ProfOak, 512, COSTUME_TAG_PROF_OAK},
    {gGraphics_Costume_ProfOak, 512, COSTUME_TAG_PROF_OAK},
    {gGraphics_Costume_ProfOak, 512, COSTUME_TAG_PROF_OAK},
    {gGraphics_Costume_ProfOak, 512, COSTUME_TAG_PROF_OAK},
    {gGraphics_Costume_ProfOak, 512, COSTUME_TAG_PROF_OAK},
    {gGraphics_Costume_ProfOak, 512, COSTUME_TAG_PROF_OAK},
    {gGraphics_Costume_ProfOak, 512, COSTUME_TAG_PROF_OAK},
    {gGraphics_Costume_ProfOak, 512, COSTUME_TAG_PROF_OAK},
    {gGraphics_Costume_ProfOak, 512, COSTUME_TAG_PROF_OAK},
    {gGraphics_Costume_ProfOak, 512, COSTUME_TAG_PROF_OAK},
    {gGraphics_Costume_ProfOak, 512, COSTUME_TAG_PROF_OAK},
    {gGraphics_Costume_ProfOak, 512, COSTUME_TAG_PROF_OAK},
    {gGraphics_Costume_ProfOak, 512, COSTUME_TAG_PROF_OAK},
};

const struct CompressedSpritePalette sCostumeOverworldPaletteTable[NUMBER_OF_COSTUMES] =
{
    {gPalette_Costume_Red,     COSTUME_TAG_RED},
    {gPalette_Costume_Lyra,    COSTUME_TAG_LYRA},
    {gPalette_Costume_Lance,   COSTUME_TAG_LANCE},
    {gPalette_Costume_Misty,   COSTUME_TAG_MISTY},
    {gPalette_Costume_RocketM, COSTUME_TAG_ROCKET_M},
    {gPalette_Costume_RocketF, COSTUME_TAG_ROCKET_F},
    {gPalette_Costume_ProfOak, COSTUME_TAG_PROF_OAK},
// duplicates
    {gPalette_Costume_ProfOak, COSTUME_TAG_PROF_OAK},
    {gPalette_Costume_ProfOak, COSTUME_TAG_PROF_OAK},
    {gPalette_Costume_ProfOak, COSTUME_TAG_PROF_OAK},
    {gPalette_Costume_ProfOak, COSTUME_TAG_PROF_OAK},
    {gPalette_Costume_ProfOak, COSTUME_TAG_PROF_OAK},
    {gPalette_Costume_ProfOak, COSTUME_TAG_PROF_OAK},
    {gPalette_Costume_ProfOak, COSTUME_TAG_PROF_OAK},
    {gPalette_Costume_ProfOak, COSTUME_TAG_PROF_OAK},
    {gPalette_Costume_ProfOak, COSTUME_TAG_PROF_OAK},
    {gPalette_Costume_ProfOak, COSTUME_TAG_PROF_OAK},
    {gPalette_Costume_ProfOak, COSTUME_TAG_PROF_OAK},
    {gPalette_Costume_ProfOak, COSTUME_TAG_PROF_OAK},
};

const struct SpriteTemplate sSpriteTemplate_Costumes[NUMBER_OF_COSTUMES] = 
{
//        .tileTag                 .paletteTag                   .oam                  .anims         .images        .affineAnims               .callback
    {COSTUME_TAG_RED,      COSTUME_TAG_RED,      &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_LYRA,     COSTUME_TAG_LYRA,     &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_LANCE,    COSTUME_TAG_LANCE,    &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_MISTY,    COSTUME_TAG_MISTY,    &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_ROCKET_M, COSTUME_TAG_ROCKET_M, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_ROCKET_F, COSTUME_TAG_ROCKET_F, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_PROF_OAK, COSTUME_TAG_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
// duplicates
    {COSTUME_TAG_PROF_OAK, COSTUME_TAG_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_PROF_OAK, COSTUME_TAG_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_PROF_OAK, COSTUME_TAG_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_PROF_OAK, COSTUME_TAG_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_PROF_OAK, COSTUME_TAG_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_PROF_OAK, COSTUME_TAG_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_PROF_OAK, COSTUME_TAG_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_PROF_OAK, COSTUME_TAG_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_PROF_OAK, COSTUME_TAG_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_PROF_OAK, COSTUME_TAG_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_PROF_OAK, COSTUME_TAG_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_PROF_OAK, COSTUME_TAG_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_PROF_OAK, COSTUME_TAG_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
    {COSTUME_TAG_PROF_OAK, COSTUME_TAG_PROF_OAK, &sOamData_CostumeSlots, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, UpdateSlotNumbers},
};

const struct CompressedSpriteSheet sCostumeTrainerSpriteTable[NUMBER_OF_COSTUMES] =
{
// .data                              .size        .tag
    {gTrainerFrontSprite_Red,          2048, COSTUME_TAG_T_RED},   // (64x64/2) = 2048 = 0x800
    {gTrainerFrontSprite_Lyra,         2048, COSTUME_TAG_T_LYRA},
    {gTrainerFrontSprite_Lance,        2048, COSTUME_TAG_T_LANCE},
    {gTrainerFrontSprite_Misty,        2048, COSTUME_TAG_T_MISTY},
    {gTrainerFrontSprite_RocketGruntM, 2048, COSTUME_TAG_T_ROCKET_M},
    {gTrainerFrontSprite_RocketGruntF, 2048, COSTUME_TAG_T_ROCKET_F},
    {gTrainerFrontSprite_ProfessorOak, 2048, COSTUME_TAG_T_PROF_OAK},
// duplicates
    {gTrainerFrontSprite_ProfessorOak, 2048, COSTUME_TAG_T_PROF_OAK},
    {gTrainerFrontSprite_ProfessorOak, 2048, COSTUME_TAG_T_PROF_OAK},
    {gTrainerFrontSprite_ProfessorOak, 2048, COSTUME_TAG_T_PROF_OAK},
    {gTrainerFrontSprite_ProfessorOak, 2048, COSTUME_TAG_T_PROF_OAK},
    {gTrainerFrontSprite_ProfessorOak, 2048, COSTUME_TAG_T_PROF_OAK},
    {gTrainerFrontSprite_ProfessorOak, 2048, COSTUME_TAG_T_PROF_OAK},
    {gTrainerFrontSprite_ProfessorOak, 2048, COSTUME_TAG_T_PROF_OAK},
    {gTrainerFrontSprite_ProfessorOak, 2048, COSTUME_TAG_T_PROF_OAK},
    {gTrainerFrontSprite_ProfessorOak, 2048, COSTUME_TAG_T_PROF_OAK},
    {gTrainerFrontSprite_ProfessorOak, 2048, COSTUME_TAG_T_PROF_OAK},
    {gTrainerFrontSprite_ProfessorOak, 2048, COSTUME_TAG_T_PROF_OAK},
    {gTrainerFrontSprite_ProfessorOak, 2048, COSTUME_TAG_T_PROF_OAK},
    {gTrainerFrontSprite_ProfessorOak, 2048, COSTUME_TAG_T_PROF_OAK},
};

const struct CompressedSpritePalette sCostumeTrainerPaletteTable[NUMBER_OF_COSTUMES] =
{
    {gPalette_Trainer_Red,     COSTUME_TAG_T_RED},
    {gPalette_Trainer_Lyra,    COSTUME_TAG_T_LYRA},
    {gPalette_Trainer_Lance,   COSTUME_TAG_T_LANCE},
    {gPalette_Trainer_Misty,   COSTUME_TAG_T_MISTY},
    {gPalette_Trainer_RocketM, COSTUME_TAG_T_ROCKET_M},
    {gPalette_Trainer_RocketF, COSTUME_TAG_T_ROCKET_F},
    {gPalette_Trainer_ProfOak, COSTUME_TAG_T_PROF_OAK},
// duplicates
    {gPalette_Trainer_ProfOak, COSTUME_TAG_T_PROF_OAK},
    {gPalette_Trainer_ProfOak, COSTUME_TAG_T_PROF_OAK},
    {gPalette_Trainer_ProfOak, COSTUME_TAG_T_PROF_OAK},
    {gPalette_Trainer_ProfOak, COSTUME_TAG_T_PROF_OAK},
    {gPalette_Trainer_ProfOak, COSTUME_TAG_T_PROF_OAK},
    {gPalette_Trainer_ProfOak, COSTUME_TAG_T_PROF_OAK},
    {gPalette_Trainer_ProfOak, COSTUME_TAG_T_PROF_OAK},
    {gPalette_Trainer_ProfOak, COSTUME_TAG_T_PROF_OAK},
    {gPalette_Trainer_ProfOak, COSTUME_TAG_T_PROF_OAK},
    {gPalette_Trainer_ProfOak, COSTUME_TAG_T_PROF_OAK},
    {gPalette_Trainer_ProfOak, COSTUME_TAG_T_PROF_OAK},
    {gPalette_Trainer_ProfOak, COSTUME_TAG_T_PROF_OAK},
};

const struct SpriteTemplate sSpriteTemplate_CostumesTrainers[NUMBER_OF_COSTUMES] = 
{
//        .tileTag                 .paletteTag                   .oam                  .anims         .images        .affineAnims               .callback
    {COSTUME_TAG_T_RED,      COSTUME_TAG_T_RED,      &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_LYRA,     COSTUME_TAG_T_LYRA,     &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_LANCE,    COSTUME_TAG_T_LANCE,    &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_MISTY,    COSTUME_TAG_T_MISTY,    &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_ROCKET_M, COSTUME_TAG_T_ROCKET_M, &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_ROCKET_F, COSTUME_TAG_T_ROCKET_F, &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_PROF_OAK, COSTUME_TAG_T_PROF_OAK, &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
// duplicates
    {COSTUME_TAG_T_PROF_OAK, COSTUME_TAG_T_PROF_OAK, &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_PROF_OAK, COSTUME_TAG_T_PROF_OAK, &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_PROF_OAK, COSTUME_TAG_T_PROF_OAK, &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_PROF_OAK, COSTUME_TAG_T_PROF_OAK, &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_PROF_OAK, COSTUME_TAG_T_PROF_OAK, &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_PROF_OAK, COSTUME_TAG_T_PROF_OAK, &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_PROF_OAK, COSTUME_TAG_T_PROF_OAK, &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_PROF_OAK, COSTUME_TAG_T_PROF_OAK, &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_PROF_OAK, COSTUME_TAG_T_PROF_OAK, &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_PROF_OAK, COSTUME_TAG_T_PROF_OAK, &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_PROF_OAK, COSTUME_TAG_T_PROF_OAK, &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_PROF_OAK, COSTUME_TAG_T_PROF_OAK, &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_PROF_OAK, COSTUME_TAG_T_PROF_OAK, &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
    {COSTUME_TAG_T_PROF_OAK, COSTUME_TAG_T_PROF_OAK, &sOamData_TrainerSprite, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, TrainerSpriteCallback},
};

#endif //GUARD_DATA_COSTUME_MENU_TABLES_H
