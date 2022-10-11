#include<stdio.h>
#include<math.h>

#include"main.h"

SDL_Renderer* rend;

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

	Player player = {0,0,TILE_SIZE,TILE_SIZE,0,0,0,0};

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

		LEVELS_level_1(&player);
		
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
