#include<stdio.h>
#include<math.h>

#include"sdl.h"
#include"tools.h"

SDL_Renderer* rend;

#include"main.h"

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
		TOOLS_SDL_Image_RenderCopy(rend, archer_right[1], 100+TILE_SIZE, 100, TILE_SIZE, TILE_SIZE);
		TOOLS_SDL_Image_RenderCopy(rend, archer_left[0], 100+TILE_SIZE*2, 100, TILE_SIZE, TILE_SIZE);
		TOOLS_SDL_Image_RenderCopy(rend, archer_left[1], 100+TILE_SIZE*3, 100, TILE_SIZE, TILE_SIZE);
		for(int i=0;i<9;i++){
			TOOLS_SDL_Image_RenderCopy(rend, bricks[i], 50+i*TILE_SIZE, 100+TILE_SIZE, TILE_SIZE, TILE_SIZE);
		}
		for(int i=0;i<9;i++){
			TOOLS_SDL_Image_RenderCopy(rend, woods[i], 50+i*TILE_SIZE, 100+TILE_SIZE+TILE_SIZE, TILE_SIZE, TILE_SIZE);
		}
		TOOLS_SDL_Image_RenderCopy(rend, backBrick, 50, 100+3*TILE_SIZE, TILE_SIZE, TILE_SIZE);
		TOOLS_SDL_Image_RenderCopy(rend, doors[0], 50+TILE_SIZE, 100+3*TILE_SIZE, TILE_SIZE, TILE_SIZE);
		TOOLS_SDL_Image_RenderCopy(rend, doors[1], 50+2*TILE_SIZE, 100+3*TILE_SIZE, TILE_SIZE, TILE_SIZE);
		TOOLS_SDL_Image_RenderCopy(rend, arrow[0], 50+3*TILE_SIZE, 100+3*TILE_SIZE, TILE_SIZE, TILE_SIZE);
		TOOLS_SDL_Image_RenderCopy(rend, arrow[1], 50+4*TILE_SIZE, 100+3*TILE_SIZE, TILE_SIZE, TILE_SIZE);
		TOOLS_SDL_Image_RenderCopy(rend, barrel, 50+5*TILE_SIZE, 100+3*TILE_SIZE, TILE_SIZE, TILE_SIZE);
		TOOLS_SDL_Image_RenderCopy(rend, create, 50+6*TILE_SIZE, 100+3*TILE_SIZE, TILE_SIZE, TILE_SIZE);
		TOOLS_SDL_Image_RenderCopy(rend, moss, 50+7*TILE_SIZE, 100+3*TILE_SIZE, TILE_SIZE, TILE_SIZE);
		for(int i=0;i<4;i++){
			TOOLS_SDL_Image_RenderCopy(rend, spikes[i], 50+i*TILE_SIZE, 100+TILE_SIZE*4, TILE_SIZE, TILE_SIZE);
		}
		TOOLS_SDL_Image_RenderCopy(rend, target[0], 50+5*TILE_SIZE, 100+TILE_SIZE*4, TILE_SIZE, TILE_SIZE);
		TOOLS_SDL_Image_RenderCopy(rend, target[1], 50+6*TILE_SIZE, 100+TILE_SIZE*4, TILE_SIZE, TILE_SIZE);
		TOOLS_SDL_Image_RenderCopy(rend, banner, 50+7*TILE_SIZE, 100+TILE_SIZE*4, TILE_SIZE, TILE_SIZE);
		TOOLS_SDL_Image_RenderCopy(rend, chains, 50+8*TILE_SIZE, 100+TILE_SIZE*4, TILE_SIZE, TILE_SIZE);
		TOOLS_SDL_Image_RenderCopy(rend, rat[0], 50+9*TILE_SIZE, 100+TILE_SIZE*4, TILE_SIZE, TILE_SIZE);
		TOOLS_SDL_Image_RenderCopy(rend, rat[1], 50+10*TILE_SIZE, 100+TILE_SIZE*4, TILE_SIZE, TILE_SIZE);
		
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
