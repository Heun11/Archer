#ifndef TILES_H
#define TILES_H

#include"main.h"

extern TOOLS_SDL_Image* archer_right[2];
extern TOOLS_SDL_Image* archer_left[2];
extern TOOLS_SDL_Image* bricks[9];
extern TOOLS_SDL_Image* woods[9];
extern TOOLS_SDL_Image* backBrick;
extern TOOLS_SDL_Image* doors[2];
extern TOOLS_SDL_Image* arrow[2];
extern TOOLS_SDL_Image* barrel;
extern TOOLS_SDL_Image* create;
extern TOOLS_SDL_Image* moss;
extern TOOLS_SDL_Image* spikes[4];
extern TOOLS_SDL_Image* target[2];
extern TOOLS_SDL_Image* rat[2];
extern TOOLS_SDL_Image* banner;
extern TOOLS_SDL_Image* chains;

void TILES_Load_Tiles(SDL_Surface* tileset);

#endif