#ifndef GUARD_SHUFFLER_H
#define GUARD_SHUFFLER_H

#include "data.h"
#include "trade.h"

#define MAX_OBJECTS 10
#define POSSIBLE_STARTERS 108
#define POSSIBLE_TRAINERS 18
#define POSSIBLE_ITEMS 61
#define TOTAL_ROOMS 7
#define TOTAL_WARPS 12
#define MAT1 0x8f7011ee
#define MAT2 0xfc78ff1f
#define TMAT 0x3793fdff

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

struct TrainerTemplate {
    u8 partyFlags;
    u8 trainerClass; // No longer used for displaying class name but still controls the transition animation and some music.
    u8 encounterMusic_gender;
    u8 trainerPic;
    const u8* trainerName;
    u8 partySize;
    
    union TrainerMonPtr party;
    u8 type1;
    u8 type2;
    u8 rarity;

    const u8* introText;
    const u8* defeatText;
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
    const u8* introText;
    const u8* defeatText;
    const u8* name;
};

struct NPCTraderInfo {
    struct InGameTrade igt;
};

struct NPCInfo {
    u8 type;
    union {
        struct NPCTraderInfo trader;
        int placeholder_do_not_use;
    };
};

union ShuffledObject {
    struct ShuffledTrainerInfo t;
    struct WildMon wm;
    u16 itemId;
    struct NPCInfo npc;
};

struct RoomInfo {
    u16 id;
    u8 warpIds[4];
};

extern u16 realStarterMon[3];
#ifdef __wasm__
extern const u8 gSpeciesNames[][POKEMON_NAME_LENGTH + 1];
#endif

void Shuffle(u32 s);
void DeclareTrainer(u8 objNum);
const u8 *GetAdjustedTrainerIntroText(u16 objNum);
const u8 *GetAdjustedTrainerDefeatText(u16 objNum);
const u8 *GetAdjustedTrainerName(u16 index);
u16 GetAdjustedTrainerFlag(u16 objNum);
const struct Trainer *RedirectTrainer(u16 index);
void DeclareWildMon(u8 objNum);
u8 GetAdjustedWildMonLevel(u8 objNum);
u16 GetAdjustedWildMonSpecies(u8 objNum);
void NotifyShufflerChangedRoom();
void RedirectShuffledWarp(struct WarpData *warp);
void DeclareItem(u16 objNum);
u16 AdjustItem(u16 index);
u16 GetShuffledNPCType(void);
struct InGameTrade* GetShuffledInGameTrade(u16 index);
u16 GetNPCFlag(void);
u16 SetNPCFlag(void);
u16 ClearNPCFlag(void);
void DeclareNPC(u16 objNum);

#endif // GUARD_SHUFFLER_H
