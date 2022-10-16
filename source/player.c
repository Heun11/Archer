#include"player.h"

PLAYER_Player PLAYER_Create_Player()
{
    PLAYER_Player p = {.rect={-1,-1,-1,-1},.speed=-1,.x_vel=0,.y_vel=0,.gravity=-1,.jump_speed=-1,.on_ground=0,.last=0};
    return p;
}

void PLAYER_Key_Down_Player(PLAYER_Player* p, int key)
{
    if(key==SDL_SCANCODE_A){
        p->x_vel = -1;
        p->last = 1;
    }
    else if(key==SDL_SCANCODE_D){
        p->x_vel = 1;
        p->last = 0;
    }

    if(key==SDL_SCANCODE_SPACE){
        if(p->on_ground==1){
            p->y_vel = p->jump_speed;
            p->on_ground = 0;
        }
    }
}

void PLAYER_Key_Up_Player(PLAYER_Player* p, int key)
{
    if(key==SDL_SCANCODE_A){
        p->x_vel = 0;
    }
    else if(key==SDL_SCANCODE_D){
        p->x_vel = 0;
    }
}

void PLAYER_Collision_Horizontal(PLAYER_Player* p, TOOLS_TileMap* m, int ts, int x_o, int y_o)
{
    for(int i=0;i<m->h;i++){
        for(int j=0;j<m->w;j++){
            if(m->l1[i*m->w+j]>0){
                SDL_Rect t = {j*ts+x_o, i*ts+y_o, ts, ts};
                if(TOOLS_Collide_Rect(p->rect, t)){
                    if(p->x_vel>0){
                        p->rect.x = t.x-p->rect.w;
                    }
                    else if(p->x_vel<0){
                        p->rect.x = t.x+t.w;
                    }
                }
            }
        }
    }
}

void PLAYER_Collision_Vertical(PLAYER_Player* p, TOOLS_TileMap* m, int ts, int x_o, int y_o)
{
    for(int i=0;i<m->h;i++){
        for(int j=0;j<m->w;j++){
            if(m->l1[i*m->w+j]>0){
                SDL_Rect t = {j*ts+x_o, i*ts+y_o, ts, ts};
                if(TOOLS_Collide_Rect(p->rect, t)){
                    if(p->y_vel>0){
                        p->rect.y = t.y-p->rect.h;
                        p->y_vel = 0;
                        p->on_ground = 1;
                    }
                    else if(p->y_vel<0){
                        p->rect.y = t.y+t.h;
                        p->y_vel = 0;
                    }
                }
            }
        }
    }
}

float anim_r_c = 0;
float anim_l_c = 0;

void PLAYER_Update_Player(PLAYER_Player* p, TOOLS_TileMap* m, int ts, int x_o, int y_o)
{
    // p->y_vel = 0;
    // p->x_vel = 0;

    // // if(p->up&&!p->down){p->y_vel = -p->speed;}
    // // if(p->down&&!p->up){p->y_vel = p->speed;}
    // // if(p->left&&!p->right){p->x_vel = -p->speed;p->last=1;}
    // // if(p->right&&!p->left){p->x_vel = p->speed;p->last=0;}

    // p->rect.y += (int) (p->y_vel/60);
    // p->rect.x += (int) (p->x_vel/60);
    
    // if(p->right&&!p->left){
    //     TOOLS_Play_Animation(rend, archer_right, &anim_r_c, 5, 1, 2, p->rect.x,p->rect.y,p->rect.w,p->rect.h);
    // }
    // else if(p->left&&!p->right){
    //     TOOLS_Play_Animation(rend, archer_left, &anim_l_c, 5, 1, 2, p->rect.x,p->rect.y,p->rect.w,p->rect.h);
    // }
    // else{
    //     if(p->last){
    //         TOOLS_Render_Image_From_Texture(rend, tex, &archer_left[0], p->rect.x, p->rect.y, p->rect.w, p->rect.h);
    //     }
    //     else{
    //         TOOLS_Render_Image_From_Texture(rend, tex, &archer_right[0], p->rect.x, p->rect.y, p->rect.w, p->rect.h);
    //     }
    // }

    p->y_vel += p->gravity;
    p->rect.y += (int) p->y_vel;
    PLAYER_Collision_Vertical(p, m, ts, x_o, y_o);

    p->rect.x += (int) (p->x_vel*p->speed);
    PLAYER_Collision_Horizontal(p, m, ts, x_o, y_o);

    // TOOLS_Render_Image_From_Texture(rend, tex, &barrel, p->rect.x, p->rect.y, p->rect.w, p->rect.h);

    if(p->x_vel>0){
        TOOLS_Play_Animation(rend, archer_right, &anim_r_c, 5, 1, 2, p->rect.x,p->rect.y,p->rect.w,p->rect.h);
    }
    else if(p->x_vel<0){
        TOOLS_Play_Animation(rend, archer_left, &anim_l_c, 5, 1, 2, p->rect.x,p->rect.y,p->rect.w,p->rect.h);
    }
    else{
        if(p->last){
            TOOLS_Render_Image_From_Texture(rend, tex, &archer_left[0], p->rect.x, p->rect.y, p->rect.w, p->rect.h);
        }
        else{
            TOOLS_Render_Image_From_Texture(rend, tex, &archer_right[0], p->rect.x, p->rect.y, p->rect.w, p->rect.h);
        }
    }
}