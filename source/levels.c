#include"levels.h"

struct LEVELS_level_render_info LEVELS_Get_Level_Render_Info(TOOLS_TileMap* map)
{
    float n1;
    float n2;
    struct LEVELS_level_render_info i; 
    n1 = (float)SCREEN_WIDTH/(float)SCREEN_HEIGHT;
    n2 = (float)map->w/(float)map->h;
    i.x_o = 0;
    i.y_o = 0;
    if(n2>n1){
        i.ts = SCREEN_WIDTH/map->w;
        i.y_o = SCREEN_HEIGHT/2-(map->h*i.ts)/2;
    }
    else{
        i.ts = SCREEN_HEIGHT/map->h;
        i.x_o = SCREEN_WIDTH/2-(map->w*i.ts)/2;
    }
    return i;
}

void LEVELS_Render_Tile(int l, int x, int y, int tile, int off_x, int off_y, int tile_w, int tile_h)
{
    if(l==0){
        if(tile==1){
            TOOLS_Render_Image_From_Texture(rend, tex, &backBrick, off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
	}
    if(l==1){
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
    if(l==2){
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

void LEVELS_Render_Level_From_Tilemap(TOOLS_TileMap* map, int off_x, int off_y, int tile_w, int tile_h)
{
    for(int i=0;i<map->h*map->w;i++){
        int x = i%map->w; 
        int y = i/map->w;
        int t0 = map->l0[i];
        int t1 = map->l1[i];
        int t2 = map->l2[i];
        LEVELS_Render_Tile(0, x, y, t0, off_x, off_y, tile_w, tile_h);
        LEVELS_Render_Tile(1, x, y, t1, off_x, off_y, tile_w, tile_h);
        LEVELS_Render_Tile(2, x, y, t2, off_x, off_y, tile_w, tile_h);
	}
}


void LEVELS_level_1(PLAYER_Player* player)
{
    TOOLS_TileMap map = TOOLS_Load_TileMap_From_File_To_Array("resources/level1.map");
    struct LEVELS_level_render_info info = LEVELS_Get_Level_Render_Info(&map);
    LEVELS_Render_Level_From_Tilemap(&map, info.x_o, info.y_o, info.ts, info.ts);

    static int target_shooted = 0;
    int bridge_len = 3;
    LEVEL_Block bridge[] = {
        {7,5,10},{8,5,10},{9,5,10}
    };

    if(player->rect.x==-1&&player->rect.y==-1&&player->rect.w==-1&&player->rect.h==-1){
        PLAYER_Set_Player(player, info.ts, info.x_o, info.y_o, 1, 8);   
    }
    if(target_shooted){
        PLAYER_Update_Player(player, &map, info.ts, info.x_o, info.y_o, bridge, bridge_len);
        for(int i=0;i<bridge_len;i++){
            if(bridge[i].t>0){
                LEVELS_Render_Tile(1, bridge[i].x, bridge[i].y, bridge[i].t, info.x_o, info.y_o, info.ts, info.ts);
            }
        }
    }
    else{
        PLAYER_Update_Player(player, &map, info.ts, info.x_o, info.y_o, NULL, bridge_len);
    }

    SDL_Rect target_r = {1*info.ts+info.x_o, 5*info.ts+info.y_o, info.ts, info.ts};
    TOOLS_Render_Image_From_Texture(rend, tex, &target[0], target_r.x, target_r.y, target_r.w, target_r.h);

    if(!player->can_shoot){
        if(TOOLS_Collide_Rect(player->arrow, target_r)){
            player->can_shoot = 1;
            target_shooted = 1;
        }
    }

    TOOLS_Free_Tilemap(&map);
}