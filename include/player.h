#ifndef PLAYER_H
#define PLAYER_H

typedef struct{
    int x;
    int y;
    int w;
    int h;
    int speed;
    int left;
    int right;
    int up;
    int down;
    int last;
    int x_vel;
    int y_vel;
}PLAYER_Player;

#include"main.h"

PLAYER_Player PLAYER_Create_Player();
void PLAYER_Key_Up_Player(PLAYER_Player* p, int key);
void PLAYER_Key_Down_Player(PLAYER_Player* p, int key);
void PLAYER_Update_Player(PLAYER_Player* p);

#endif