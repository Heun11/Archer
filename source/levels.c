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
        if(tile>=10 && tile<=18){
            TOOLS_Render_Image_From_Texture(rend, tex, &woods[tile-9-1], off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
        if(tile>=19 && tile<=22){
            TOOLS_Render_Image_From_Texture(rend, tex, &woodBricks[tile-18-1], off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
        }
        if(tile==23){
            TOOLS_Render_Image_From_Texture(rend, tex, &grid, off_x+x*tile_w, off_y+y*tile_h, tile_w, tile_h);
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

int LEVELS_Menu()
{
	TOOLS_SDL_Text_RenderCopy(rend, font, "Tu budu informacie o hre!", SCREEN_WIDTH/2-400, SCREEN_HEIGHT/7, 800, 300, (SDL_Color){176,27,27});
    SDL_Rect button = {SCREEN_WIDTH/2-200,SCREEN_HEIGHT/2,400,200};
	TOOLS_SDL_Text_RenderCopy(rend, font, "play!", button.x, button.y, button.w, button.h, (SDL_Color){255,255,255});

    int mouse_x, mouse_y, buttons;
    buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
    if(buttons & SDL_BUTTON(SDL_BUTTON_LEFT)){
        SDL_Rect mouse = {mouse_x-5, mouse_y-5, 10,10};
        if(TOOLS_Collide_Rect(mouse, button)){
            return 1;
        }
    }
    return 0;
}

int LEVELS_level_1(PLAYER_Player* player)
{
    TOOLS_TileMap map = TOOLS_Load_TileMap_From_File_To_Array("resources/level1.map");
    struct LEVELS_level_render_info info = LEVELS_Get_Level_Render_Info(&map);
    LEVELS_Render_Level_From_Tilemap(&map, info.x_o, info.y_o, info.ts, info.ts);

    static int target_shooted = 0;
    int blocks_len = 3;
    int gate_start = 0;
    int gate_len = 2;
    LEVEL_Block blocks[] = {
        {9,2,23},{9,3,23}
    };
    int active_blocks[] = {
        1,1
    };

    SDL_Rect target_r = {1*info.ts+info.x_o, 1*info.ts+info.y_o, info.ts, info.ts};
    TOOLS_Render_Image_From_Texture(rend, tex, &target[0], target_r.x, target_r.y, target_r.w, target_r.h);

    SDL_Rect doors_r = {13*info.ts+info.x_o, 2*info.ts+info.y_o, info.ts, info.ts};
    TOOLS_Render_Image_From_Texture(rend, tex, &doors[1], doors_r.x, doors_r.y, doors_r.w, doors_r.h);

    if(target_shooted){
        for(int i=gate_start;i<gate_start+gate_len;i++){
            active_blocks[i] = 0;
        }
    }
    for(int i=0;i<blocks_len;i++){
        if(active_blocks[i]==1 && blocks[i].t>0){
            LEVELS_Render_Tile(1, blocks[i].x, blocks[i].y, blocks[i].t, info.x_o, info.y_o, info.ts, info.ts);
        }
    }

    if((player->rect.x==-1&&player->rect.y==-1)||(player->rect.w!=info.ts&&player->rect.h!=info.ts)){
        PLAYER_Set_Player(player, info.ts, map.w, map.h, info.x_o, info.y_o, 1, 1);   
    }
    PLAYER_Update_Player(player, &map, info.ts, info.x_o, info.y_o, blocks, active_blocks, blocks_len);

    if(!player->can_shoot){
        if(TOOLS_Collide_Rect(player->arrow, target_r)){
            player->can_shoot = 1;
            target_shooted = 1;
        }
    }

    LIGHT_Light light = {map.w*2, map.h*2, info.ts/2, 3, 0, 0.f};
    light.srcs = malloc(light.s_len*sizeof(LIGHT_LightSource*));

    LIGHT_LightSource p_light = {(player->rect.x-info.x_o)/(info.ts/2)+1,(player->rect.y-info.y_o)/(info.ts/2),9,9};
    LIGHT_Add_LightMap_To_LightSource(&p_light, LIGHT_Player_LightMap);
    LIGHT_Add_LightSource_To_Light(&light, &p_light);

    LIGHT_LightSource t_light = {(target_r.x-info.x_o)/(info.ts/2)+1,(target_r.y-info.y_o)/(info.ts/2)+1,5,5};
    LIGHT_Add_LightMap_To_LightSource(&t_light, LIGHT_Torch_LightMap);
    LIGHT_Add_LightSource_To_Light(&light, &t_light);

    LIGHT_LightSource d_light = {(doors_r.x-info.x_o)/(info.ts/2),(doors_r.y-info.y_o)/(info.ts/2)+1,5,5};
    LIGHT_Add_LightMap_To_LightSource(&d_light, LIGHT_Torch_LightMap);
    LIGHT_Add_LightSource_To_Light(&light, &d_light);

    LIGHT_Render_Light(&light, info.x_o, info.y_o);
    LIGHT_Kill_Light(light);

    if(TOOLS_Collide_Rect(player->rect, doors_r)){
        target_shooted = 0;
        return 2;
    }

    TOOLS_Free_Tilemap(&map);
    return 1;
}

int LEVELS_level_2(PLAYER_Player* player)
{
    TOOLS_TileMap map = TOOLS_Load_TileMap_From_File_To_Array("resources/level2.map");
    struct LEVELS_level_render_info info = LEVELS_Get_Level_Render_Info(&map);
    LEVELS_Render_Level_From_Tilemap(&map, info.x_o, info.y_o, info.ts, info.ts);

    static int target_shooted = 0;
    int blocks_len = 3;
    int bridge_start = 0;
    int bridge_len = 3;
    LEVEL_Block blocks[] = {
        {7,5,10},{8,5,10},{9,5,10}
    };
    int active_blocks[] = {
        0,0,0
    };

    SDL_Rect target_r = {1*info.ts+info.x_o, 5*info.ts+info.y_o, info.ts, info.ts};
    TOOLS_Render_Image_From_Texture(rend, tex, &target[0], target_r.x, target_r.y, target_r.w, target_r.h);

    SDL_Rect doors_r = {2*info.ts+info.x_o, 3*info.ts+info.y_o, info.ts, info.ts};
    TOOLS_Render_Image_From_Texture(rend, tex, &doors[1], doors_r.x, doors_r.y, doors_r.w, doors_r.h);

    if((player->rect.x==-1&&player->rect.y==-1)||(player->rect.w!=info.ts&&player->rect.h!=info.ts)){
        PLAYER_Set_Player(player, info.ts, map.w, map.h, info.x_o, info.y_o, 2, 10);   
    }
    if(target_shooted){
        for(int i=bridge_start;i<bridge_len+bridge_start;i++){
            active_blocks[i] = 1;
            if(active_blocks[i]==1 && blocks[i].t>0){
                LEVELS_Render_Tile(1, blocks[i].x, blocks[i].y, blocks[i].t, info.x_o, info.y_o, info.ts, info.ts);
            }
        }
    }
    PLAYER_Update_Player(player, &map, info.ts, info.x_o, info.y_o, blocks, active_blocks, blocks_len);
    static ENEMY_Enemy rat;
    ENEMY_Init_Enemy(&rat, info.x_o+17*info.ts, info.y_o+5*info.ts, info.ts, info.ts, 1);
    ENEMY_Update_Rat(&rat, &map, info.ts, info.x_o, info.y_o, blocks, active_blocks, blocks_len);

    if(TOOLS_Collide_Rect(player->rect, rat.r)){
        player->dead = 1;
    }

    if(!player->can_shoot){
        if(TOOLS_Collide_Rect(player->arrow, target_r)){
            player->can_shoot = 1;
            target_shooted = 1;
        }
    }

    // static PARTICLE_Particles ps;
    // PARTICLE_Init_Particles(&ps, 900, 800, 30, 16, 16, (int[2]){-5,5}, (int[2]){50,80});
    // PARTICLE_Render_Smoke(&ps, 30, info.ts);

    LIGHT_Light light = {map.w*2, map.h*2, info.ts/2, 2, 0, 0.f};
    light.srcs = malloc(light.s_len*sizeof(LIGHT_LightSource*));

    LIGHT_LightSource p_light = {(player->rect.x-info.x_o)/(info.ts/2)+1,(player->rect.y-info.y_o)/(info.ts/2),9,9};
    LIGHT_Add_LightMap_To_LightSource(&p_light, LIGHT_Player_LightMap);
    LIGHT_Add_LightSource_To_Light(&light, &p_light);

    LIGHT_LightSource t_light = {(target_r.x-info.x_o)/(info.ts/2)+1,(target_r.y-info.y_o)/(info.ts/2)+1,5,5};
    LIGHT_Add_LightMap_To_LightSource(&t_light, LIGHT_Torch_LightMap);
    LIGHT_Add_LightSource_To_Light(&light, &t_light);

    LIGHT_Render_Light(&light, info.x_o, info.y_o);
    LIGHT_Kill_Light(light);

    TOOLS_Free_Tilemap(&map);

    if(TOOLS_Collide_Rect(player->rect, doors_r)){
        target_shooted = 0;
        rat.init = 0;
        return 3;
    }
    else if(player->dead){
        target_shooted = 0;
        rat.init = 0;
        return 0;
    }
    return 2;
}
