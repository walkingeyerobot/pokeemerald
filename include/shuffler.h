#ifndef GUARD_SHUFFLER_H
#define GUARD_SHUFFLER_H

#include "data.h"

#define MAX_OBJECTS 10
#define POSSIBLE_STARTERS 108
#define POSSIBLE_TRAINERS 2
#define TOTAL_ROOMS 6
#define MAT1 0x8f7011ee
#define MAT2 0xfc78ff1f
#define TMAT 0x3793fdff

struct TrainerTemplate {
    //u8 partyFlags;
    u8 trainerClass;
    u8 encounterMusic_gender;
    u8 trainerPic;
    u8* trainerName;
    //u16 items[4];
    //bool8 doubleBattle;
    //u32 aiFlags;
    //u8 partySize;
    
    union TrainerMonPtr party;
    u8 type1;
    u8 type2;
    u8 rarity;

    u8* introText;
    u8* defeatText;
    u16 graphicsId;
};

union TrainerMonParty {
    struct TrainerMonNoItemDefaultMoves NoItemDefaultMoves[6];
    struct TrainerMonNoItemCustomMoves NoItemCustomMoves[6];
    struct TrainerMonItemDefaultMoves ItemDefaultMoves[6];
    struct TrainerMonItemCustomMoves ItemCustomMoves[6];
};

struct WildMon {
    u8 type;
    union {
        struct TrainerMonNoItemDefaultMoves NoItemDefaultMoves;
        struct TrainerMonNoItemCustomMoves NoItemCustomMoves;
        struct TrainerMonItemDefaultMoves ItemDefaultMoves;
        struct TrainerMonItemCustomMoves ItemCustomMoves;
    };
};

struct ShuffledTrainerInfo {
    struct Trainer trainer;
    union TrainerMonParty party;
    u8* introText;
    u8* defeatText;
    u8* name;
};

union ShuffledObject {
    struct ShuffledTrainerInfo t;
    struct WildMon wm;
};

extern u16 realStarterMon[3];

void Shuffle();
void DeclareTrainer(u8 objNum);
const u8 *GetAdjustedTrainerIntroText(u16 objNum);
const u8 *GetAdjustedTrainerDefeatText(u16 objNum);
struct Trainer RedirectTrainer(u16 index);
const u8 *GetRedirectTrainerName(u16 index);
void DeclareWildMon(u8 objNum);
u8 GetAdjustedWildMonLevel(u8 objNum);
u16 GetAdjustedWildMonSpecies(u8 objNum);
void NotifyShufflerChangedRoom();

#endif // GUARD_SHUFFLER_H