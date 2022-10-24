#ifndef PARTICLE_H
#define PARTICLE_H

typedef struct{
    int x;
    int y;
}PARTICLE_Particle;

typedef struct{
    int src_x;
    int src_y;
    PARTICLE_Particle* ps;
}PARTICLE_Particles;

/*  
    idea -> spravit iba particle struct a nejake toto upravujuce funkcie
    ale vzdy ked budes chciet particles tak si spravis vlastnu funkciu a
    napises to manualne, je to tak najlepsie asi 
*/

#include"main.h"

#endif