#ifndef GUARD_SHUFFLER_H
#define GUARD_SHUFFLER_H

#include "global.h"

#define TOTAL_WARPS 3

extern u16 realStarterMon[3];
extern struct WarpData realWarps[TOTAL_WARPS][2];
void Shuffle();
void RedirectShuffledWarp(struct WarpData *warp);

#endif // GUARD_SHUFFLER_H
