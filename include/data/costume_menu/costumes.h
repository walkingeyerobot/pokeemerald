#ifndef GUARD_DATA_COSTUMES_H
#define GUARD_DATA_COSTUMES_H

const struct Costume gCostumes[] =
{
// Main Characters
    [RED] = {
        .name = gText_CostumeName_Red,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Red,
        .overworld = EVENT_OBJ_GFX_RED,
        .fieldMove = EVENT_OBJ_GFX_RED_FIELD_MOVE,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [LEAF] = {
        .name = gText_CostumeName_Leaf,
        .gender = FEMALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Leaf,
        .overworld = EVENT_OBJ_GFX_LEAF,
        .fieldMove = EVENT_OBJ_GFX_LEAF_FIELD_MOVE,
        .trainerFront = TRAINER_PIC_LEAF,
        .trainerBack = TRAINER_BACK_PIC_LEAF,
    },
    [ETHAN] = {
        .name = gText_CostumeName_Ethan,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Ethan,
        .overworld = EVENT_OBJ_GFX_ETHAN,
        .fieldMove = EVENT_OBJ_GFX_ETHAN_FIELD_MOVE,
        .trainerFront = TRAINER_PIC_RUBY_SAPPHIRE_BRENDAN,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [KRIS] = {
        .name = gText_CostumeName_Kris,
        .gender = FEMALE,
        .hidden = TRUE,
        .description = gText_CostumeDescription_Kris,
        .overworld = EVENT_OBJ_GFX_KRIS,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RUBY_SAPPHIRE_MAY,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [LYRA] = {
        .name = gText_CostumeName_Lyra,
        .gender = FEMALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Lyra,
        .overworld = EVENT_OBJ_GFX_LYRA,
        .fieldMove = EVENT_OBJ_GFX_LYRA_FIELD_MOVE,
        .trainerFront = TRAINER_PIC_RUBY_SAPPHIRE_MAY,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [BRENDAN] = {
        .name = gText_CostumeName_Brendan,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Brendan,
        .overworld = EVENT_OBJ_GFX_BRENDAN,
        .fieldMove = EVENT_OBJ_GFX_BRENDAN,
        .trainerFront = TRAINER_PIC_BRENDAN,
        .trainerBack = TRAINER_BACK_PIC_BRENDAN,
    },
    [MAY] = {
        .name = gText_CostumeName_May,
        .gender = FEMALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_May,
        .overworld = EVENT_OBJ_GFX_MAY,
        .fieldMove = EVENT_OBJ_GFX_MAY,
        .trainerFront = TRAINER_PIC_MAY,
        .trainerBack = TRAINER_BACK_PIC_MAY,
    },
    [LUCAS] = {
        .name = gText_CostumeName_Lucas,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Lucas,
        .overworld = EVENT_OBJ_GFX_LUCAS,
        .fieldMove = EVENT_OBJ_GFX_LUCAS_FIELD_MOVE,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [DAWN] = {
        .name = gText_CostumeName_Dawn,
        .gender = FEMALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Dawn,
        .overworld = EVENT_OBJ_GFX_DAWN,
        .fieldMove = EVENT_OBJ_GFX_DAWN_FIELD_MOVE,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
// Professors
    [PROFESSOR_OAK] = {
        .name = gText_CostumeName_ProfessorOak,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_ProfessorOak,
        .overworld = EVENT_OBJ_GFX_PROF_OAK,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [PROFESSOR_ELM] = {
        .name = gText_CostumeName_ProfessorElm,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_ProfessorElm,
        .overworld = EVENT_OBJ_GFX_PROF_ELM,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [PROFESSOR_BIRCH] = {
        .name = gText_CostumeName_ProfessorBirch,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_ProfessorBirch,
        .overworld = EVENT_OBJ_GFX_PROF_BIRCH,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [PROFESSOR_ROWAN] = {
        .name = gText_CostumeName_ProfessorRowan,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_ProfessorRowan,
        .overworld = EVENT_OBJ_GFX_PROF_ROWAN,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
// Rivals
    [GARRY_OAK] = {
        .name = gText_CostumeName_GarryOak,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_GarryOak,
        .overworld = EVENT_OBJ_GFX_BLUE,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [SILVER] = {
        .name = gText_CostumeName_Silver,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Silver,
        .overworld = EVENT_OBJ_GFX_SILVER,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [WALLY] = {
        .name = gText_CostumeName_Wally,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Wally,
        .overworld = EVENT_OBJ_GFX_WALLY,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_WALLY,
        .trainerBack = TRAINER_BACK_PIC_WALLY,
    },
    [BARRY] = {
        .name = gText_CostumeName_Barry,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Barry,
        .overworld = EVENT_OBJ_GFX_BARRY,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
// Standard Trainers
// Villanous Teams
    [ROCKET_GRUNT_M] = {
        .name = gText_CostumeName_RocketGruntM,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_RocketGruntM,
        .overworld = EVENT_OBJ_GFX_ROCKET_GRUNT_M,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [ROCKET_GRUNT_F] = {
        .name = gText_CostumeName_RocketGruntF,
        .gender = FEMALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_RocketGruntF,
        .overworld = EVENT_OBJ_GFX_ROCKET_GRUNT_F,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [ROCKET_EXEC_ARCHER] = {
        .name = gText_CostumeName_Archer,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Archer,
        .overworld = EVENT_OBJ_GFX_ARCHER,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [ROCKET_EXEC_ARIANA] = {
        .name = gText_CostumeName_Ariana,
        .gender = FEMALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Ariana,
        .overworld = EVENT_OBJ_GFX_ARIANA,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [ROCKET_EXEC_PETREL] = {
        .name = gText_CostumeName_Petrel,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Petrel,
        .overworld = EVENT_OBJ_GFX_PETREL,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [ROCKET_EXEC_PROTON] = {
        .name = gText_CostumeName_Proton,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Proton,
        .overworld = EVENT_OBJ_GFX_PROTON,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [GIOVANNI] = {
        .name = gText_CostumeName_Giovanni,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Giovanni,
        .overworld = EVENT_OBJ_GFX_GIOVANNI,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [AQUA_GRUNT_M] = {
        .name = gText_CostumeName_AquaGruntM,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_AquaGruntM,
        .overworld = EVENT_OBJ_GFX_AQUA_GRUNT_M,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [AQUA_GRUNT_F] = {
        .name = gText_CostumeName_AquaGruntF,
        .gender = FEMALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_AquaGruntF,
        .overworld = EVENT_OBJ_GFX_AQUA_GRUNT_F,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_AQUA_GRUNT_F,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [AQUA_ADMIN_MATT] = {
        .name = gText_CostumeName_Matt,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Matt,
        .overworld = EVENT_OBJ_GFX_MATT,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_AQUA_ADMIN_M,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [AQUA_ADMIN_SHELLEY] = {
        .name = gText_CostumeName_Shelley,
        .gender = FEMALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Shelley,
        .overworld = EVENT_OBJ_GFX_SHELLEY,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [ARCHIE] = {
        .name = gText_CostumeName_Archie,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Archie,
        .overworld = EVENT_OBJ_GFX_ARCHIE,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_AQUA_LEADER_ARCHIE,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [MAGMA_GRUNT_M] = {
        .name = gText_CostumeName_MagmaGruntM,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_MagmaGruntM,
        .overworld = EVENT_OBJ_GFX_MAGMA_GRUNT_M,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [MAGMA_GRUNT_F] = {
        .name = gText_CostumeName_MagmaGruntF,
        .gender = FEMALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_MagmaGruntF,
        .overworld = EVENT_OBJ_GFX_MAGMA_GRUNT_F,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [MAGMA_ADMIN_COURTNEY] = {
        .name = gText_CostumeName_Courtney,
        .gender = FEMALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Courtney,
        .overworld = EVENT_OBJ_GFX_COURTNEY,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_MAGMA_ADMIN,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [MAGMA_ADMIN_TABITHA] = {
        .name = gText_CostumeName_Tabitha,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Tabitha,
        .overworld = EVENT_OBJ_GFX_TABITHA,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_MAGMA_ADMIN,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [MAXIE] = {
        .name = gText_CostumeName_Maxie,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Maxie,
        .overworld = EVENT_OBJ_GFX_MAXIE,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [GALACTIC_GRUNT_M] = {
        .name = gText_CostumeName_GalacticGruntM,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_GalacticGruntM,
        .overworld = EVENT_OBJ_GFX_GALACTIC_GRUNT_M,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [GALACTIC_GRUNT_F] = {
        .name = gText_CostumeName_GalacticGruntF,
        .gender = FEMALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_GalacticGruntF,
        .overworld = EVENT_OBJ_GFX_GALACTIC_GRUNT_F,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [COMMANDER_SATURN] = {
        .name = gText_CostumeName_Saturn,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Saturn,
        .overworld = EVENT_OBJ_GFX_SATURN,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [COMMANDER_MARS] = {
        .name = gText_CostumeName_Mars,
        .gender = FEMALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Mars,
        .overworld = EVENT_OBJ_GFX_MARS,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [COMMANDER_JUPITER] = {
        .name = gText_CostumeName_Jupiter,
        .gender = FEMALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Jupiter,
        .overworld = EVENT_OBJ_GFX_JUPITER,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [COMMANDER_CHARON] = {
        .name = gText_CostumeName_Charon,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Charon,
        .overworld = EVENT_OBJ_GFX_CHARON,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
    [CYRUS] = {
        .name = gText_CostumeName_Cyrus,
        .gender = MALE,
        .hidden = FALSE,
        .description = gText_CostumeDescription_Cyrus,
        .overworld = EVENT_OBJ_GFX_CYRUS,
        .fieldMove = EVENT_OBJ_GFX_RED,
        .trainerFront = TRAINER_PIC_RED,
        .trainerBack = TRAINER_BACK_PIC_RED,
    },
// Gym Leaders
// Elite 4 + Champions
// Misc characters
};
#endif //GUARD_DATA_COSTUMES_H