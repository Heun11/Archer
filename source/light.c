#include"light.h"

void LIGHT_Kill_LightSource(LIGHT_LightSource* s)
{
    free(s->light_map);
}

void LIGHT_Add_LightMap_To_LightSource(LIGHT_LightSource* s, float* l_map)
{
    s->light_map = malloc(s->light_map_h*s->light_map_w*sizeof(float));
    for(int i=0;i<s->light_map_w*s->light_map_h;i++){
        s->light_map[i] = l_map[i];
    }
}

void LIGHT_Render_Light(LIGHT_LightSource* srcs, int srcs_len, int w, int h, int ts, int x_o, int y_o)
{
    float alpha = .2f;
    int o_x, o_y;
    for(int x = 0;x<w;x++){
        for(int y = 0;y<h;y++){
            alpha = .2f;
            for(int i=0;i<srcs_len;i++){
                o_x = (int)(srcs[i].light_map_w/2);
                o_y = (int)(srcs[i].light_map_h/2);
                if(x>=srcs[i].tile_x-o_x && x<=srcs[i].tile_x+o_x && y>=srcs[i].tile_y-o_y && y<=srcs[i].tile_y+o_y){
                    alpha = srcs[i].light_map[((o_y+y-srcs[i].tile_y)*srcs[i].light_map_w+(o_x+x-srcs[i].tile_x))];
                }
            }
            SDL_SetRenderDrawColor(rend, 0, 0, 0, (int)(255-255*alpha));
			SDL_RenderFillRect(rend, &(SDL_Rect){x_o+ts*x, y_o+ts*y, ts, ts});
        }
    }
}
