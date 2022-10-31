#include"enemy.h"

void ENEMY_Init_Enemy(ENEMY_Enemy* e, int x, int y, int w, int h, int x_vel)
{
    if(e->init!=1){
        e->init = 1;
        e->x = x;
        e->y = y;
        e->r.x = x;
        e->r.y = y;
        e->r.w = w;
        e->r.h = h;
        e->last = 1;
        e->x_vel = x_vel;
        e->y_vel = 0;
        e->on_ground = 0;
        e->can_attack = 1;
    }
}

void ENEMY_Collision_Horizontal(ENEMY_Enemy* e, SDL_Rect t)
{
    if(TOOLS_Collide_Rect(e->r, t)){
        if(e->x_vel>0){
            e->x = (float)(t.x-e->r.w);
            e->r.x = (int)e->x;
            e->x_vel = 0;
        }
        else if(e->x_vel<0){
            e->x = (float)(t.x+t.w);
            e->r.x = (int)e->x;
            e->x_vel = 0;
        }
    }
}

void ENEMY_Collision_Vertical(ENEMY_Enemy* e, SDL_Rect t)
{
    if(TOOLS_Collide_Rect(e->r, t)){
        if(e->y_vel>0){
            e->y = (float)(t.y-e->r.h);
            e->r.y = (int)e->y;
            e->y_vel = 0;
            e->on_ground = 1;
        }
        else if(e->y_vel<0){
            e->y = (float)(t.y+t.h);
            e->r.y = (int)e->y;
            e->y_vel = 0;
        }
    }
}

void ENEMY_Update_Rat(ENEMY_Enemy* e, TOOLS_TileMap* m, int ts, int x_o, int y_o, LEVEL_Block* blocks, int* active_blocks, int blocks_len)
{
    if(e->x_vel==0){
        e->x_vel = 1+(-2*e->last);
    }

    e->y_vel += TS/2*elapsed;
    e->y += e->y_vel;
    e->r.y = (int)e->y;

    for(int i=0;i<m->h;i++){
        for(int j=0;j<m->w;j++){
            if(m->l1[i*m->w+j]>0){
                SDL_Rect t = {j*ts+x_o, i*ts+y_o, ts, ts};
                ENEMY_Collision_Vertical(e, t);
            }
        }
    }
    if(blocks!=NULL && active_blocks!=NULL){
        for(int i=0;i<blocks_len;i++){
            if(active_blocks[i]==1 && blocks[i].t>0){
                SDL_Rect t = {blocks[i].x*ts+x_o, blocks[i].y*ts+y_o, ts, ts};
                ENEMY_Collision_Vertical(e, t);
            }
        }
    }
    e->x += (e->x_vel*5*TS*elapsed);
    e->r.x = (int)e->x;

    for(int i=0;i<m->h;i++){
        for(int j=0;j<m->w;j++){
            if(m->l1[i*m->w+j]>0){
                SDL_Rect t = {j*ts+x_o, i*ts+y_o, ts, ts};
                ENEMY_Collision_Horizontal(e, t);
            }
        }
    }
    if(blocks!=NULL && active_blocks!=NULL){
        for(int i=0;i<blocks_len;i++){
            if(active_blocks[i]==1 && blocks[i].t>0){
                SDL_Rect t = {blocks[i].x*ts+x_o, blocks[i].y*ts+y_o, ts, ts};
                ENEMY_Collision_Horizontal(e, t);
            }
        }
    }

    if(e->x_vel<0){
        e->last = 0;
    }
    else if(e->x_vel>0){
        e->last = 1;
    }

    TOOLS_Render_Image_From_Texture(rend, tex, &rat[e->last], e->r.x, e->r.y, e->r.w, e->r.h);    
    SDL_RenderDrawRect(rend, &e->r);
}
