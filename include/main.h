#ifndef MAIN_H
#define MAIN_H

#include"sdl.h"
#include"tools.h"
#include"stdio.h"
#include"stdlib.h"

#define TILE_SIZE_REAL 16

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

extern SDL_Renderer* rend;
extern SDL_Texture* tex;
extern TTF_Font* font;

#include"tiles.h"
#include"player.h"
#include"levels.h"

#endif