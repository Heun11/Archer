#include<stdio.h>
#include<math.h>

#include"sdl.h"
#include"tools.h"

SDL_Renderer* rend;

#include"main.h"

void render_tilemap(SDL_Renderer* r, TOOLS_TileMap* map, TOOLS_SDL_Image* bricks[9], TOOLS_SDL_Image* woods[9])
{
	for(int i=0;i<map->w;i++){
		for(int j=0;j<map->h;j++){
			int tile = map->m[i*map->w+j];
			if(tile>0){
				if(tile>8){
					TOOLS_SDL_Image_RenderCopy(r, woods[tile-10], TILE_SIZE*j, TILE_SIZE*i, TILE_SIZE, TILE_SIZE);
				}
				else{
					TOOLS_SDL_Image_RenderCopy(r, bricks[tile-1], TILE_SIZE*j, TILE_SIZE*i, TILE_SIZE, TILE_SIZE);
				}
			}
		}
	}
}

void level1(SDL_Renderer* r, TOOLS_SDL_Image* bricks[9], TOOLS_SDL_Image* woods[9])
{
	TOOLS_TileMap map = TOOLS_Load_TileMap_From_File_To_Array("resources/level1.map");
    render_tilemap(r, &map, bricks, woods);
}


int main(int argc, char** argv)
{
	
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO)!=0){
		SDL_Quit();
		return 1;
	}
	
	SDL_Window* win = SDL_CreateWindow("Archer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 640, 0);
	if(!win){
		SDL_Quit();
		return 1;
	}

	Uint32 render_flags = SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC;
	rend = SDL_CreateRenderer(win, -1, render_flags);
	if(!rend){
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}
	
	SDL_Surface* tileset = IMG_Load("resources/archer-tileset.png");
	TILES_Load_Tiles(tileset);
	SDL_FreeSurface(tileset);

	int run = 1;
	while(run){

		Uint64 start = SDL_GetPerformanceCounter();

		SDL_Event event;
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
					run = 0;
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.scancode){
						
						default:
							break;
					}
					break;
				case SDL_KEYUP:
					switch(event.key.keysym.scancode){
						
						default:
							break;
					}
					break;
			}
		}

		SDL_RenderClear(rend);

		TOOLS_SDL_Image_RenderCopy(rend, archer_right[0], 100, 100, TILE_SIZE, TILE_SIZE);

		// for(int i=0;i<9;i++){
		// 	TOOLS_SDL_Image_RenderCopy(rend, bricks[i], 50+i*TILE_SIZE, 100+TILE_SIZE, TILE_SIZE, TILE_SIZE);
		// }

		// for(int i=0;i<9;i++){
		// 	TOOLS_SDL_Image_RenderCopy(rend, woods[i], 50+i*TILE_SIZE, 100+TILE_SIZE+TILE_SIZE, TILE_SIZE, TILE_SIZE);
		// }

		level1(rend, bricks, woods);
		
		SDL_RenderPresent(rend);
	
		Uint64 end = SDL_GetPerformanceCounter();
		float elapsed = (end - start) / (float)SDL_GetPerformanceFrequency();
		//printf("fps %f\n", 1.0f/elapsed);
		SDL_Delay(elapsed);
		
	}
	
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
	TTF_Quit();
	return 0;
}
