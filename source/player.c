#include"player.h"

PLAYER_Player PLAYER_Create_Player()
{
    PLAYER_Player p = {.x=-1,.y=-1,.rect={-1,-1,-1,-1},.speed=-1,.x_vel=0,.y_vel=0,.gravity=-1,.jump_speed=-1,
        .on_ground=0,.last=0,.l=0,.r=0,.can_shoot=1,.arrow={-1,-1,-1,-1},.arrow_speed=-1};
    return p;
}

void PLAYER_Set_Player(PLAYER_Player* p, int ts, int x_o, int y_o, int x, int y)
{
    p->rect.w = ts;
    p->rect.h = ts;
    p->rect.x = x*ts+x_o;
    p->rect.y = y*ts+y_o;
    p->x = p->rect.x;
    p->y = p->rect.y;
    p->arrow.x = p->rect.x;
    p->arrow.y = p->rect.y;
    p->arrow.w = ts;
    p->arrow.h = ts;
    p->arrow_speed = ts/7;
    p->speed = (float)ts/15;
    p->gravity = (float)ts/90;
    p->jump_speed = -((float)ts/3.75f);
}

void PLAYER_Key_Down_Player(PLAYER_Player* p, int key)
{
    if(key==SDL_SCANCODE_A){
        p->l = 1;
        p->last = 1;
    }
    else if(key==SDL_SCANCODE_D){
        p->r = 1;
        p->last = 0;
    }

    if(key==SDL_SCANCODE_SPACE){
        if(p->on_ground){
            p->y_vel = p->jump_speed;
            p->on_ground = 0;
        }
    }

    if(key==SDL_SCANCODE_RETURN){
        if(p->can_shoot){
            p->can_shoot = 0;
            p->arrow.x = p->rect.x;
            p->arrow.y = p->rect.y;
            if(p->last){
                p->arrow_speed=-p->speed*2;
            }
            else{
                p->arrow_speed=p->speed*2;
            }
        }
    }
}

void PLAYER_Key_Up_Player(PLAYER_Player* p, int key)
{
    if(key==SDL_SCANCODE_A){
        p->l = 0;
    }
    else if(key==SDL_SCANCODE_D){
        p->r = 0;
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
                        p->x = (float)(t.x-p->rect.w);
                        p->rect.x = (int)p->x;
                    }
                    else if(p->x_vel<0){
                        p->x = (float)(t.x+t.w);
                        p->rect.x = (int)p->x;
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
                        p->y = (float)(t.y-p->rect.h);
                        p->rect.y = (int)p->y;
                        p->y_vel = 0;
                        p->on_ground = 1;
                    }
                    else if(p->y_vel<0){
                        p->y = (float)(t.y+t.h);
                        p->rect.y = (int)p->y;
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
    if(p->r&&!p->l){
        p->x_vel = 1;
    }
    else if(p->l&&!p->r){
        p->x_vel = -1;
    }
    else{
        p->x_vel = 0;
    }

    p->y_vel += p->gravity;
    p->y += p->y_vel;
    p->rect.y = (int)p->y;
    PLAYER_Collision_Vertical(p, m, ts, x_o, y_o);

    p->x += (p->x_vel*p->speed);
    p->rect.x = (int)p->x;
    PLAYER_Collision_Horizontal(p, m, ts, x_o, y_o);

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
    SDL_RenderDrawRect(rend, &p->rect);

    if(!p->can_shoot){
        p->arrow.x += p->arrow_speed;
        if(p->arrow_speed>0){
            TOOLS_Render_Image_From_Texture(rend, tex, &arrow[0], p->arrow.x, p->arrow.y, p->arrow.w, p->arrow.h);
        }
        else{
            TOOLS_Render_Image_From_Texture(rend, tex, &arrow[1], p->arrow.x, p->arrow.y, p->arrow.w, p->arrow.h);
        }
        SDL_RenderDrawRect(rend, &p->arrow);
        for(int i=0;i<m->h*m->w;i++){
            int x = i%m->w; 
            int y = i/m->w;     
            if(m->l1[i]>0){
                if(TOOLS_Collide_Rect(p->arrow, (SDL_Rect){x*ts+x_o, y*ts+y_o, ts, ts})){
                    p->can_shoot = 1;
                }
            }
        }
    }
}
