#include"player.h"

PLAYER_Player PLAYER_Create_Player()
{
    PLAYER_Player p = {-1,-1,-1,-1,-1,0,0,0,0,0,0,0};
    return p;
}

void PLAYER_Key_Down_Player(PLAYER_Player* p, int key)
{
    switch(key)
    {
        case SDL_SCANCODE_W:
            p->up = 1;
            break;
        case SDL_SCANCODE_S:
            p->down = 1;
            break;
        case SDL_SCANCODE_A:
            p->left = 1;
            break;
        case SDL_SCANCODE_D:
            p->right = 1;
            break;
    }
}

void PLAYER_Key_Up_Player(PLAYER_Player* p, int key)
{
    switch(key)
    {
        case SDL_SCANCODE_W:
            p->up = 0;
            break;
        case SDL_SCANCODE_S:
            p->down = 0;
            break;
        case SDL_SCANCODE_A:
            p->left = 0;
            break;
        case SDL_SCANCODE_D:
            p->right = 0;
            break;
    }
}

float anim_r_c = 0;
float anim_l_c = 0;

void PLAYER_Update_Player(PLAYER_Player* p)
{
    p->y_vel = 0;
    p->x_vel = 0;

    if(p->up&&!p->down){p->y_vel = -p->speed;}
    if(p->down&&!p->up){p->y_vel = p->speed;}
    if(p->left&&!p->right){p->x_vel = -p->speed;p->last=1;}
    if(p->right&&!p->left){p->x_vel = p->speed;p->last=0;}

    p->y += (int) (p->y_vel/60);
    p->x += (int) (p->x_vel/60);
    
    if(p->right&&!p->left){
        TOOLS_Play_Animation(rend, archer_right, &anim_r_c, 5, 1, 2, p->x,p->y,p->w,p->h);
    }
    else if(p->left&&!p->right){
        TOOLS_Play_Animation(rend, archer_left, &anim_l_c, 5, 1, 2, p->x,p->y,p->w,p->h);
    }
    else{
        if(p->last){
            TOOLS_Render_Image_From_Texture(rend, tex, &archer_left[0], p->x, p->y, p->w, p->h);
        }
        else{
            TOOLS_Render_Image_From_Texture(rend, tex, &archer_right[0], p->x, p->y, p->w, p->h);
        }
    }
}