#ifndef LEVELS_H
#define LEVELS_H

struct LEVELS_level_render_info{
    int ts, y_o, x_o;
};

typedef struct{
    int x;
    int y;
    int t;
}LEVEL_Block;

#include"main.h"

void LEVELS_level_1(PLAYER_Player* p);

#endif