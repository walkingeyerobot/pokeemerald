#ifndef GUARD_SHUFFLER_H
#define GUARD_SHUFFLER_H

#include "global.h"
#include "data.h"

#define TOTAL_WARPS 12
#define MAX_SAVED_TRAINERS 2
#define TOTAL_ROOMS 7
#define MAX_TRAINERS_PER_ROOM 2
#define MAX_TRAINER_ID TRAINER_GRUNT_PETALBURG_WOODS // 10
#define MAX_OBJECTS 10
#define MAX_WILDMON_ID 1
#define MAX_WILDMONS_PER_ROOM 2

union TrainerMon
{
    struct TrainerMonNoItemDefaultMoves NoItemDefaultMoves[6];
    struct TrainerMonNoItemCustomMoves NoItemCustomMoves[6];
    struct TrainerMonItemDefaultMoves ItemDefaultMoves[6];
    struct TrainerMonItemCustomMoves ItemCustomMoves[6];
};

extern u16 realStarterMon[3];
extern struct WarpData realWarps[TOTAL_WARPS][2];
extern struct MapEvents AdjustedMapEvents;
extern struct ObjectEventTemplate AdjustedTemplates[MAX_OBJECTS];
extern u16 CurrentAdjustedRoom;
extern u16 AdjustedWildMons[MAX_WILDMON_ID + 1][3];
void Shuffle();
void RedirectShuffledWarp(struct WarpData *warp);
struct Trainer RedirectTrainer(u16 index);
void AdjustTrainerSprite(u8 objNum, u16 trainerId);
void AdjustWildMonSprite(u8 objNum, u16 monId);

#endif // GUARD_SHUFFLER_H
