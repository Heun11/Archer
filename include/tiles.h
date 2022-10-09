#ifndef TILES_H
#define TILES_H

#include"main.h"

extern TOOLS_SDL_Image* archer_right[2];
extern TOOLS_SDL_Image* archer_left[2];
extern TOOLS_SDL_Image* bricks[9];
extern TOOLS_SDL_Image* woods[9];
extern TOOLS_SDL_Image* backBrick;

void TILES_Load_Tiles(SDL_Surface* tileset);

#endif