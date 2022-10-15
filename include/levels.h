#ifndef LEVELS_H
#define LEVELS_H

struct LEVELS_level_render_info{
    int n1, n2, ts, y_o, x_o;
};

#include"main.h"

/*
    Back layer:
    0 -> nic
    1 -> tehlove pozadie
    Ground layer:
    0 -> nic
    1-9 -> tehly
    10-19 -> dreva
    20-23 -> drevo tehla
    Decor layer:
    0 -> nic
    1 -> sud
    2 -> krabica
    3 -> mach
    4 -> retaze
    5 -> vlajka
    6 -> dvere (vchod (zavrete))
*/

void LEVELS_level_1(PLAYER_Player* p);

#endif