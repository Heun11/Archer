#include"levels.h"

struct LEVELS_level_render_info LEVELS_Get_Level_Render_Info(TOOLS_TileMap* map)
{
    struct LEVELS_level_render_info i; 
    i.n1 = SCREEN_WIDTH/SCREEN_HEIGHT;
    i.n2 = map->w/map->h;
    i.x_o = 0;
    i.y_o = 0;
    if(i.n2>i.n1){
        i.ts = SCREEN_WIDTH/map->w;
        i.y_o = SCREEN_HEIGHT/2-(map->h*i.ts)/2;
    }
    else{
        i.ts = SCREEN_HEIGHT/map->h;
        i.x_o = SCREEN_WIDTH/2-(map->w*i.ts)/2;
    }
    return i;
}

void LEVELS_Render_Level_From_Tilemap(TOOLS_TileMap* map, int off_x, int off_y, int tile_w, int tile_h)
{
    for(int i=0;i<map->h*map->w;i++){
        int x = i%map->w; 
        int y = i/map->w;
        int tile = map->l0[i];
        if(tile==1){
            TOOLS_SDL_Image_RenderCopy(rend, backBrick, off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
	}
    for(int i=0;i<map->h*map->w;i++){
        int x = i%map->w; 
        int y = i/map->w;
        int tile = map->l1[i];
        if(tile>=1 && tile<=9){
            TOOLS_SDL_Image_RenderCopy(rend, bricks[tile-1], off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
        if(tile>=10 && tile<=19){
            TOOLS_SDL_Image_RenderCopy(rend, woods[tile-9-1], off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
	}
    for(int i=0;i<map->h*map->w;i++){
        int x = i%map->w; 
        int y = i/map->w;
        int tile = map->l2[i];
        if(tile==1){
            TOOLS_SDL_Image_RenderCopy(rend, barrel, off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
        if(tile==2){
            TOOLS_SDL_Image_RenderCopy(rend, box, off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
        if(tile==3){
            TOOLS_SDL_Image_RenderCopy(rend, moss, off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
        if(tile==4){
            TOOLS_SDL_Image_RenderCopy(rend, chains, off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
        if(tile==5){
            TOOLS_SDL_Image_RenderCopy(rend, banner, off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
        if(tile==6){
            TOOLS_SDL_Image_RenderCopy(rend, doors[0], off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
	}
}


// LEVEL local variables
float anim_c1 = 0;
float anim_c2 = 0;

void LEVELS_level_1(Player* p)
{
    TOOLS_TileMap map = TOOLS_Load_TileMap_From_File_To_Array("resources/test.map");
    struct LEVELS_level_render_info info = LEVELS_Get_Level_Render_Info(&map);
    LEVELS_Render_Level_From_Tilemap(&map, info.x_o, info.y_o, info.ts, info.ts);

    // level code (player, usable objects)
	TOOLS_Play_Animation(rend, archer_right, &anim_c1, 5, 2, 100,400,info.ts,info.ts);
	TOOLS_Play_Animation(rend, archer_left, &anim_c2, 5, 2, 100,400+info.ts,info.ts,info.ts);

    TOOLS_Free_Tilemap(&map);
}