#include"light.h"

// float LIGHT_Player_LightMap[81] = {
//     .2f,.25f,.3f,.3f,.3f,.3f,.3f,.25f,.2f,
//     .23f,.8f,.8f,.8f,.8f,.8f,.8f,.8f,.25f,
//     .3f,.8f,.8f,.8f,.8f,.8f,.8f,.8f,.3f,
//     .3f,.8f,.8f,.8f,.8f,.8f,.8f,.8f,.3f,
//     .3f,.8f,.8f,.8f,.8f,.8f,.8f,.8f,.3f,
//     .3f,.8f,.8f,.8f,.8f,.8f,.8f,.8f,.3f,
//     .3f,.8f,.8f,.8f,.8f,.8f,.8f,.8f,.3f,
//     .25f,.8f,.8f,.8f,.8f,.8f,.8f,.8f,.25f,
//     .2f,.25f,.3f,.3f,.3f,.3f,.3f,.25f,.2f
// };

float LIGHT_Player_LightMap[81] = {
	0.2f, 0.2f, 0.3f, 0.4f, 0.4f, 0.4f, 0.3f, 0.2f, 0.2f, 
	0.2f, 0.3f, 0.4f, 0.5f, 0.5f, 0.5f, 0.4f, 0.3f, 0.2f, 
	0.3f, 0.4f, 0.5f, 0.7f, 0.7f, 0.7f, 0.5f, 0.4f, 0.3f, 
	0.4f, 0.5f, 0.7f, 0.8f, 0.9f, 0.8f, 0.7f, 0.5f, 0.4f, 
	0.4f, 0.5f, 0.7f, 0.9f, 1.0f, 0.9f, 0.7f, 0.5f, 0.4f, 
	0.4f, 0.5f, 0.7f, 0.8f, 0.9f, 0.8f, 0.7f, 0.5f, 0.4f, 
	0.3f, 0.4f, 0.5f, 0.7f, 0.7f, 0.7f, 0.5f, 0.4f, 0.3f, 
	0.2f, 0.3f, 0.4f, 0.5f, 0.5f, 0.5f, 0.4f, 0.3f, 0.2f, 
	0.2f, 0.2f, 0.3f, 0.4f, 0.4f, 0.4f, 0.3f, 0.2f, 0.2f, 
};

float LIGHT_Torch_LightMap[25] = {
    .2f,.5f,.5f,.5f,.2f,
    .5f,.75f,.8f,.75f,.5f,
    .5f,.8f,1.0f,.8f,.5f,
    .5f,.75f,.8f,.75f,.5f,
    .2f,.5f,.5f,.5f,.2f
};

void LIGHT_Add_LightMap_To_LightSource(LIGHT_LightSource* s, float* l_map)
{
    s->light_map = malloc(s->light_map_h*s->light_map_w*sizeof(float));
    for(int i=0;i<s->light_map_w*s->light_map_h;i++){
        s->light_map[i] = l_map[i];
    }
}

void LIGHT_Add_LightSource_To_Light(LIGHT_Light* l, LIGHT_LightSource* s)
{
    if(l->s_len_now<l->s_len){
        l->srcs[l->s_len_now] = s;
        l->s_len_now+=1;
    }
}

void LIGHT_Render_Light(LIGHT_Light* l, int x_o, int y_o)
{
    float alpha = l->default_l;
    float a = l->default_l;
    int o_x, o_y;
    for(int x = 0;x<l->w;x++){
        for(int y = 0;y<l->h;y++){
            alpha = l->default_l;
            for(int i=0;i<l->s_len_now;i++){
                o_x = (int)(l->srcs[i]->light_map_w/2);
                o_y = (int)(l->srcs[i]->light_map_h/2);
                if(x>=l->srcs[i]->tile_x-o_x && x<=l->srcs[i]->tile_x+o_x && y>=l->srcs[i]->tile_y-o_y && y<=l->srcs[i]->tile_y+o_y){
                    a = l->srcs[i]->light_map[((o_y+y-l->srcs[i]->tile_y)*l->srcs[i]->light_map_w+(o_x+x-l->srcs[i]->tile_x))];
                    if(a>alpha){
                        alpha = a;
                    }
                }
            }
            SDL_SetRenderDrawColor(rend, 0, 0, 0, (int)(255-255*alpha));
			SDL_RenderFillRect(rend, &(SDL_Rect){x_o+l->ts*x, y_o+l->ts*y, l->ts, l->ts});
        }
    }
}