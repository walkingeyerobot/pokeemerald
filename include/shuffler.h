#ifndef GUARD_SHUFFLER_H
#define GUARD_SHUFFLER_H

#include "global.h"
#include "data.h"

#define TOTAL_WARPS 12
#define MAX_SAVED_TRAINERS 2

union TrainerMon
{
    struct TrainerMonNoItemDefaultMoves NoItemDefaultMoves[6];
    struct TrainerMonNoItemCustomMoves NoItemCustomMoves[6];
    struct TrainerMonItemDefaultMoves ItemDefaultMoves[6];
    struct TrainerMonItemCustomMoves ItemCustomMoves[6];
};

extern u16 realStarterMon[3];
extern struct WarpData realWarps[TOTAL_WARPS][2];
void Shuffle();
void RedirectShuffledWarp(struct WarpData *warp);
struct Trainer RedirectTrainer(u16 index);

#endif // GUARD_SHUFFLER_H
