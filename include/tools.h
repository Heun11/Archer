#ifndef TOOLS_H
#define TOOLS_H

typedef struct{
	int w;
	int h;
	int* l0;
	int* l1;
	int* l2;
}TOOLS_TileMap;

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"sdl.h"
#include"main.h"

int SRAND_CALL;

#define ENDL '\n'

SDL_Rect TOOLS_Get_Image_Src(int x, int y, int t_w, int t_h);
void TOOLS_Render_Image_From_Texture(SDL_Renderer* rend, SDL_Texture* tex, SDL_Rect* src, int x, int y, int w, int h);

TOOLS_TileMap TOOLS_Load_TileMap_From_File_To_Array(char* filename);
void TOOLS_Free_Tilemap(TOOLS_TileMap* m);

void TOOLS_SDL_Text_RenderCopy(SDL_Renderer* r, TTF_Font* f, char* s, int x, int y, int w, int h, SDL_Color c);
int TOOLS_Random_Number(int start, int stop);
int TOOLS_Collide_Rect(SDL_Rect r1, SDL_Rect r2);
void TOOLS_Play_Animation(SDL_Renderer* r, SDL_Rect* images, float* anim_c, int fps, int start, int end, int x, int y, int w, int h);

void get_error();

#endif
