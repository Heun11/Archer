#include<stdio.h>
#include<math.h>

#include"main.h"

SDL_Renderer* rend;
SDL_Texture* tex;
TTF_Font* font;
int SCREEN_WIDTH;
int SCREEN_HEIGHT;

int main(int argc, char** argv)
{
	
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO)!=0){
		SDL_Quit();
		return 1;
	}
	
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	SCREEN_WIDTH = DM.w;
	SCREEN_HEIGHT = DM.h;
	Uint32 win_flags = SDL_WINDOW_FULLSCREEN_DESKTOP;
	// SDL_Window* win = SDL_CreateWindow("Archer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	SDL_Window* win = SDL_CreateWindow("Archer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, win_flags);
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
	SDL_SetRenderDrawBlendMode(rend, SDL_BLENDMODE_BLEND);
	
	SDL_Surface* tileset = IMG_Load("resources/archer-tileset-new.png");
	tex = SDL_CreateTextureFromSurface(rend, tileset);
	SDL_FreeSurface(tileset);

	TILES_Load_Tiles();

	PLAYER_Player player = PLAYER_Create_Player();
	int key;

	TTF_Init();
	font = TTF_OpenFont("resources/ancient.ttf", 100);
	SDL_Color text_color = {252, 3, 215};

	float elapsed = 1;
	char fps_str[10];

	int level_count = 0;

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
					key = event.key.keysym.scancode;
					PLAYER_Key_Down_Player(&player, key);
					switch(key){
						case SDL_SCANCODE_ESCAPE:
							run = 0;
							break;
						default:
							break;
					}
					break;
				case SDL_KEYUP:
					key = event.key.keysym.scancode;
					PLAYER_Key_Up_Player(&player, key);
					switch(key){
						default:
							break;
					}
					break;
			}
		}

		SDL_RenderClear(rend);
    	// SDL_SetRenderDrawColor(rend, 255, 0, 0, 255); // background color

		if(level_count==0){
			level_count = LEVELS_Menu();
		}
		else if(level_count==1){
			level_count = LEVELS_level_1(&player);
		}
		else{
			level_count = LEVELS_level_2(&player);
		}

		snprintf(fps_str, 10, "fps:%d", (int)(1.0f/elapsed));
		TOOLS_SDL_Text_RenderCopy(rend, font, fps_str, 10, 10, 100, 40, text_color);
		SDL_RenderPresent(rend);
	
		Uint64 end = SDL_GetPerformanceCounter();
		elapsed = (end - start) / (float)SDL_GetPerformanceFrequency();
		// printf("fps %f\n", 1.0f/elapsed);
		SDL_Delay(elapsed);
	}
	
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
	TTF_Quit();
	return 0;
}
