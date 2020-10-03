#ifndef GUARD_COSTUME_MENU_H
#define GUARD_COSTUME_MENU_H

#define NONE 0
#define SCROLL_LEFT 1
#define SCROLL_RIGHT 2

#define NAME_WINDOW 0
#define DESCRIPTION_WINDOW 1
#define YES_NO_WINDOW 2
#define CONFIRMATION_WINDOW 3
#define COSTUME_CHANGE_WINDOW 4

#define LIST_STANDARD 0
#define LIST_MALE 1
#define LIST_FEMALE 2
#define LIST_UNLOCKED 3

struct Costume
{
    const u8 *name;
    u8 gender;
    u8 hidden;
    const u8 *description;
    u16 overworld;
    u16 fieldMove;
    u8 trainerFront;
    u8 trainerBack;
};

#endif // GUARD_COSTUME_MENU_H
