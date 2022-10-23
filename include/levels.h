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

int LEVELS_Menu();
int LEVELS_level_1(PLAYER_Player* p);
int LEVELS_level_2(PLAYER_Player* p);

#endif