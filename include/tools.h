#ifndef TOOLS_H
#define TOOLS_H

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"sdl.h"

int SRAND_CALL;

#define ENDL '\n'

typedef struct{
	SDL_Texture* tex;
	SDL_Rect* src;
}TOOLS_SDL_Image;

TOOLS_SDL_Image*  TOOLS_SDL_Image_Load_From_Surface(SDL_Renderer* r, SDL_Surface* s, int s_x, int s_y, int s_w, int s_h);
void TOOLS_SDL_Image_RenderCopy(SDL_Renderer* r, TOOLS_SDL_Image* i, int x, int y, int w, int h);
TOOLS_SDL_Image* TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(SDL_Renderer* r, SDL_Surface* s, int t_w, int t_h, int x, int y);

void TOOLS_SDL_Text_RenderCopy(SDL_Renderer* r, TTF_Font* f, char* s, int x, int y, int w, int h, SDL_Color c);

int TOOLS_Random_Number(int start, int stop);

typedef struct{
	int w;
	int h;
	int* m;
}TOOLS_TileMap;

TOOLS_TileMap TOOLS_Load_TileMap_From_File_To_Array(char* filename);

void get_error();

#endif
