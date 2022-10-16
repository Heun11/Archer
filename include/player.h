#ifndef PLAYER_H
#define PLAYER_H

#include"sdl.h"

typedef struct{
    SDL_Rect rect;
    // int left;
    // int right;
    // int up;
    // int down;
    int last;
    float x_vel;
    float y_vel;
    float speed;
    float gravity;
    float jump_speed;
    int on_ground;

}PLAYER_Player;

#include"main.h"

PLAYER_Player PLAYER_Create_Player();
void PLAYER_Key_Up_Player(PLAYER_Player* p, int key);
void PLAYER_Key_Down_Player(PLAYER_Player* p, int key);
void PLAYER_Update_Player(PLAYER_Player* p, TOOLS_TileMap* m, int ts, int x_o, int y_o);

#endif