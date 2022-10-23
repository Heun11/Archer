#ifndef LIGHT_H
#define LIGHT_H

typedef struct{
    int tile_x;
    int tile_y;
    int light_map_w;
    int light_map_h;
    float* light_map;
}LIGHT_LightSource;

#include"main.h"

void LIGHT_Kill_LightSource(LIGHT_LightSource* s);
void LIGHT_Add_LightMap_To_LightSource(LIGHT_LightSource* s, float* l_map);
void LIGHT_Render_Light(LIGHT_LightSource* srcs, int srcs_len, int w, int h, int ts, int x_o, int y_o);

#endif