#ifndef PARTICLE_H
#define PARTICLE_H

typedef struct{
    int x;
    int y;
    int w;
    int h;
    float l_t;
    float a;
    int vx;
    int vy;
}PARTICLE_Particle;

typedef struct{
    int init;
    int src_x;
    int src_y;
    int src_w;
    int src_h;
    int size;
    PARTICLE_Particle* ps;
    int vxr[2];
    int vyr[2];
}PARTICLE_Particles;

/*  
    idea -> spravit iba particle struct a nejake toto upravujuce funkcie
    ale vzdy ked budes chciet particles tak si spravis vlastnu funkciu a
    napises to manualne, je to tak najlepsie asi 
*/

#include"main.h"

void PARTICLE_Init_Particles(PARTICLE_Particles* ps, int src_x, int src_y, int size, int src_w, int src_h, int v_x_r[2], int v_y_r[2]);
void PARTICLE_Render_Smoke(PARTICLE_Particles* ps, int life_time, int ts);

#endif