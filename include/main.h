#ifndef MAIN_H
#define MAIN_H

#include"sdl.h"
#include"tools.h"

#define TILE_SIZE_REAL 16
#define TILE_SIZE 48

typedef struct{
    int x;
    int y;
    int w;
    int h;
    int left;
    int right;
    int up;
    int down;
}Player;

extern SDL_Renderer* rend;

#include"tiles.h"
#include"levels.h"

#endif