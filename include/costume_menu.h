#ifndef GUARD_COSTUME_MENU_H
#define GUARD_COSTUME_MENU_H

#define NONE 0
#define SCROLL_LEFT 1
#define SCROLL_RIGHT 2

#define NAME_WINDOW 0
#define DESCRIPTION_WINDOW 1
#define YES_NO_WINDOW 2
#define CONFIRMATION_WINDOW 3

struct Costume
{
    const u8 *name;
    u8 gender;
    u8 series;
    const u8 *description;
    u16 overworld;
    u16 fieldMove;
    u8 trainerFront;
    u8 trainerBack;
};

enum Series
{
    POKEMON,
};

#endif // GUARD_COSTUME_MENU_H
