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
            TOOLS_Render_Image_From_Texture(rend, tex, &backBrick, off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
	}
    for(int i=0;i<map->h*map->w;i++){
        int x = i%map->w; 
        int y = i/map->w;
        int tile = map->l1[i];
        if(tile>=1 && tile<=9){
            TOOLS_Render_Image_From_Texture(rend, tex, &bricks[tile-1], off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
        if(tile>=10 && tile<=19){
            TOOLS_Render_Image_From_Texture(rend, tex, &woods[tile-9-1], off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
        if(tile>=20 && tile<=23){
            TOOLS_Render_Image_From_Texture(rend, tex, &woodBricks[tile-19-1], off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
	}
    for(int i=0;i<map->h*map->w;i++){
        int x = i%map->w; 
        int y = i/map->w;
        int tile = map->l2[i];
        if(tile==1){
            TOOLS_Render_Image_From_Texture(rend, tex, &barrel, off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
        if(tile==2){
            TOOLS_Render_Image_From_Texture(rend, tex, &box, off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
        if(tile==3){
            TOOLS_Render_Image_From_Texture(rend, tex, &moss, off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
        if(tile==4){
            TOOLS_Render_Image_From_Texture(rend, tex, &chains, off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
        if(tile==5){
            TOOLS_Render_Image_From_Texture(rend, tex, &banner, off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
        if(tile==6){
            TOOLS_Render_Image_From_Texture(rend, tex, &doors[0], off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
	}
}


void LEVELS_level_1(PLAYER_Player* player)
{
    TOOLS_TileMap map = TOOLS_Load_TileMap_From_File_To_Array("resources/level1.map");
    struct LEVELS_level_render_info info = LEVELS_Get_Level_Render_Info(&map);
    LEVELS_Render_Level_From_Tilemap(&map, info.x_o, info.y_o, info.ts, info.ts);

    if(player->rect.x==-1&&player->rect.y==-1&&player->rect.w==-1&&player->rect.h==-1){
        player->rect.w = info.ts;
        player->rect.h = info.ts;
        player->rect.x = 2*info.ts;
        player->rect.y = 2*info.ts;
        player->speed = (float)info.ts/15;
        player->gravity = (float)info.ts/90;
        player->jump_speed = -((float)info.ts/3.75f);
        // self.speed = block_size/15
        // self.gravity = block_size/90
        // self.jump_speed = -(block_size/3.75)
    }

    PLAYER_Update_Player(player, &map, info.ts, info.x_o, info.y_o);

    TOOLS_Free_Tilemap(&map);
}