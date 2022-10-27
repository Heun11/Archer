#include"particle.h"

void PARTICLE_Init_Particles(PARTICLE_Particles* ps, int src_x, int src_y, int size, int src_w, int src_h, int vxr[2], int vyr[2])
{
    ps->init = 1;
    ps->src_x = src_x;
    ps->src_y = src_y;
    ps->src_w = src_w;
    ps->src_h = src_h;
    ps->size = size;
    ps->vxr[0] = vxr[0];
    ps->vxr[1] = vxr[1]*20;
    ps->vyr[0] = vyr[0];
    ps->vyr[1] = vyr[1];
    ps->ps = malloc(size*sizeof(PARTICLE_Particle));
    for(int i=0;i<size;i++){
        ps->ps[i].x = src_x;
        ps->ps[i].y = src_y;
        ps->ps[i].w = src_w;
        ps->ps[i].h = src_h;
        ps->ps[i].l_t = 0.f;
        ps->ps[i].a = 0.f;
        ps->ps[i].vx = TOOLS_Random_Number(vxr[0],vxr[1]);
        ps->ps[i].vy = TOOLS_Random_Number(vyr[0],vyr[1]);
    }
}

void PARTICLE_Render_Smoke(PARTICLE_Particles* ps, int life_time)
{
    for(int i=0;i<ps->size;i++){
        ps->ps[i].y -= 80*elapsed*((float)TOOLS_Random_Number(1,50)/10.f);
        ps->ps[i].x += TOOLS_Random_Number(-200, 200)*elapsed;
        ps->ps[i].l_t += life_time/(1.f/elapsed);
        ps->ps[i].a += life_time/(1.f/elapsed)/life_time;
        if(ps->ps[i].l_t>=life_time){
            ps->ps[i].l_t = 0.f;
            ps->ps[i].x = 900;
            ps->ps[i].y = 800;
            ps->ps[i].a = 0.f;
        }
        SDL_SetRenderDrawColor(rend, 255, 255, 255, (int)(255-255*ps->ps[i].a));
        SDL_RenderFillRect(rend, &(SDL_Rect){ps->ps[i].x, ps->ps[i].y, ps->ps[i].w, ps->ps[i].h});
    }
}
