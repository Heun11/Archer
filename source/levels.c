#include"levels.h"

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

void LEVELS_level_1(Player* p)
{
    TOOLS_TileMap map = TOOLS_Load_TileMap_From_File_To_Array("resources/level1.map");
    int tile_w = TILE_SIZE;
    int tile_h = TILE_SIZE;
    LEVELS_Render_Level_From_Tilemap(&map, 0, 0, tile_w, tile_h);
    TOOLS_Free_Tilemap(&map);
}