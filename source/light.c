#include"light.h"

float LIGHT_Player_LightMap[361] = {
	0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 
	0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0061920100000934395f, 0.0506662505202744f, 0.08375430541829765f, 0.10419358352238337f, 0.11111111111111108f, 0.10419358352238337f, 0.08375430541829765f, 0.0506662505202744f, 0.0061920100000934395f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 
	0.0f, 0.0f, 0.0f, 0.0f, 0.04418608143970815f, 0.10419358352238337f, 0.15380298823734345f, 0.19109890119105355f, 0.21432579868161383f, 0.22222222222222215f, 0.21432579868161383f, 0.19109890119105355f, 0.15380298823734345f, 0.10419358352238337f, 0.04418608143970815f, 0.0f, 0.0f, 0.0f, 0.0f, 
	0.0f, 0.0f, 0.0f, 0.0571909584179366f, 0.13219448045481616f, 0.1987663832302246f, 0.25464400750007005f, 0.2972716310736934f, 0.3241374966335312f, 0.3333333333333333f, 0.3241374966335312f, 0.2972716310736934f, 0.25464400750007005f, 0.1987663832302246f, 0.13219448045481616f, 0.0571909584179366f, 0.0f, 0.0f, 0.0f, 
	0.0f, 0.0f, 0.04418608143970815f, 0.13219448045481616f, 0.21432579868161383f, 0.28854175139635013f, 0.35211645612829984f, 0.40164835476283284f, 0.43344227626746834f, 0.4444444444444445f, 0.43344227626746834f, 0.40164835476283284f, 0.35211645612829984f, 0.28854175139635013f, 0.21432579868161383f, 0.13219448045481616f, 0.04418608143970815f, 0.0f, 0.0f, 
	0.0f, 0.0061920100000934395f, 0.10419358352238337f, 0.1987663832302246f, 0.28854175139635013f, 0.37146063894529097f, 0.4444444444444445f, 0.5030960050000467f, 0.5418771527091488f, 0.5555555555555556f, 0.5418771527091488f, 0.5030960050000467f, 0.4444444444444445f, 0.37146063894529097f, 0.28854175139635013f, 0.1987663832302246f, 0.10419358352238337f, 0.0061920100000934395f, 0.0f, 
	0.0f, 0.0506662505202744f, 0.15380298823734345f, 0.25464400750007005f, 0.35211645612829984f, 0.4444444444444445f, 0.5285954792089683f, 0.5993831916151123f, 0.6486358155368468f, 0.6666666666666666f, 0.6486358155368468f, 0.5993831916151123f, 0.5285954792089683f, 0.4444444444444445f, 0.35211645612829984f, 0.25464400750007005f, 0.15380298823734345f, 0.0506662505202744f, 0.0f, 
	0.0f, 0.08375430541829765f, 0.19109890119105355f, 0.2972716310736934f, 0.40164835476283284f, 0.5030960050000467f, 0.5993831916151123f, 0.6857303194726455f, 0.7515480025000233f, 0.7777777777777778f, 0.7515480025000233f, 0.6857303194726455f, 0.5993831916151123f, 0.5030960050000467f, 0.40164835476283284f, 0.2972716310736934f, 0.19109890119105355f, 0.08375430541829765f, 0.0f, 
	0.0f, 0.10419358352238337f, 0.21432579868161383f, 0.3241374966335312f, 0.43344227626746834f, 0.5418771527091488f, 0.6486358155368468f, 0.7515480025000233f, 0.8428651597363228f, 0.888888888888889f, 0.8428651597363228f, 0.7515480025000233f, 0.6486358155368468f, 0.5418771527091488f, 0.43344227626746834f, 0.3241374966335312f, 0.21432579868161383f, 0.10419358352238337f, 0.0f, 
	0.0f, 0.11111111111111108f, 0.22222222222222215f, 0.3333333333333333f, 0.4444444444444445f, 0.5555555555555556f, 0.6666666666666666f, 0.7777777777777778f, 0.888888888888889f, 1.0f, 0.888888888888889f, 0.7777777777777778f, 0.6666666666666666f, 0.5555555555555556f, 0.4444444444444445f, 0.3333333333333333f, 0.22222222222222215f, 0.11111111111111108f, 0.0f, 
	0.0f, 0.10419358352238337f, 0.21432579868161383f, 0.3241374966335312f, 0.43344227626746834f, 0.5418771527091488f, 0.6486358155368468f, 0.7515480025000233f, 0.8428651597363228f, 0.888888888888889f, 0.8428651597363228f, 0.7515480025000233f, 0.6486358155368468f, 0.5418771527091488f, 0.43344227626746834f, 0.3241374966335312f, 0.21432579868161383f, 0.10419358352238337f, 0.0f, 
	0.0f, 0.08375430541829765f, 0.19109890119105355f, 0.2972716310736934f, 0.40164835476283284f, 0.5030960050000467f, 0.5993831916151123f, 0.6857303194726455f, 0.7515480025000233f, 0.7777777777777778f, 0.7515480025000233f, 0.6857303194726455f, 0.5993831916151123f, 0.5030960050000467f, 0.40164835476283284f, 0.2972716310736934f, 0.19109890119105355f, 0.08375430541829765f, 0.0f, 
	0.0f, 0.0506662505202744f, 0.15380298823734345f, 0.25464400750007005f, 0.35211645612829984f, 0.4444444444444445f, 0.5285954792089683f, 0.5993831916151123f, 0.6486358155368468f, 0.6666666666666666f, 0.6486358155368468f, 0.5993831916151123f, 0.5285954792089683f, 0.4444444444444445f, 0.35211645612829984f, 0.25464400750007005f, 0.15380298823734345f, 0.0506662505202744f, 0.0f, 
	0.0f, 0.0061920100000934395f, 0.10419358352238337f, 0.1987663832302246f, 0.28854175139635013f, 0.37146063894529097f, 0.4444444444444445f, 0.5030960050000467f, 0.5418771527091488f, 0.5555555555555556f, 0.5418771527091488f, 0.5030960050000467f, 0.4444444444444445f, 0.37146063894529097f, 0.28854175139635013f, 0.1987663832302246f, 0.10419358352238337f, 0.0061920100000934395f, 0.0f, 
	0.0f, 0.0f, 0.04418608143970815f, 0.13219448045481616f, 0.21432579868161383f, 0.28854175139635013f, 0.35211645612829984f, 0.40164835476283284f, 0.43344227626746834f, 0.4444444444444445f, 0.43344227626746834f, 0.40164835476283284f, 0.35211645612829984f, 0.28854175139635013f, 0.21432579868161383f, 0.13219448045481616f, 0.04418608143970815f, 0.0f, 0.0f, 
	0.0f, 0.0f, 0.0f, 0.0571909584179366f, 0.13219448045481616f, 0.1987663832302246f, 0.25464400750007005f, 0.2972716310736934f, 0.3241374966335312f, 0.3333333333333333f, 0.3241374966335312f, 0.2972716310736934f, 0.25464400750007005f, 0.1987663832302246f, 0.13219448045481616f, 0.0571909584179366f, 0.0f, 0.0f, 0.0f, 
	0.0f, 0.0f, 0.0f, 0.0f, 0.04418608143970815f, 0.10419358352238337f, 0.15380298823734345f, 0.19109890119105355f, 0.21432579868161383f, 0.22222222222222215f, 0.21432579868161383f, 0.19109890119105355f, 0.15380298823734345f, 0.10419358352238337f, 0.04418608143970815f, 0.0f, 0.0f, 0.0f, 0.0f, 
	0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0061920100000934395f, 0.0506662505202744f, 0.08375430541829765f, 0.10419358352238337f, 0.11111111111111108f, 0.10419358352238337f, 0.08375430541829765f, 0.0506662505202744f, 0.0061920100000934395f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 
	0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 
};

float LIGHT_Torch_LightMap[225] = {
	0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 
	0.0f, 0.0f, 0.0f, 0.0f, 0.041685152500090084f, 0.09649209709474871f, 0.13103392424311142f, 0.14285714285714288f, 0.13103392424311142f, 0.09649209709474871f, 0.041685152500090084f, 0.0f, 0.0f, 0.0f, 0.0f, 
	0.0f, 0.0f, 0.0f, 0.08526796608102157f, 0.16700687216495708f, 0.23069074183792804f, 0.27156864091531646f, 0.2857142857142857f, 0.27156864091531646f, 0.23069074183792804f, 0.16700687216495708f, 0.08526796608102157f, 0.0f, 0.0f, 0.0f, 
	0.0f, 0.0f, 0.08526796608102157f, 0.19187796435823135f, 0.2857142857142857f, 0.36112343500006006f, 0.41098491062604847f, 0.42857142857142855f, 0.41098491062604847f, 0.36112343500006006f, 0.2857142857142857f, 0.19187796435823135f, 0.08526796608102157f, 0.0f, 0.0f, 
	0.0f, 0.041685152500090084f, 0.16700687216495708f, 0.2857142857142857f, 0.39390847326867356f, 0.48492124636228723f, 0.5482460485473744f, 0.5714285714285714f, 0.5482460485473744f, 0.48492124636228723f, 0.39390847326867356f, 0.2857142857142857f, 0.16700687216495708f, 0.041685152500090084f, 0.0f, 
	0.0f, 0.09649209709474871f, 0.23069074183792804f, 0.36112343500006006f, 0.48492124636228723f, 0.5959389821791157f, 0.68056171750003f, 0.7142857142857142f, 0.68056171750003f, 0.5959389821791157f, 0.48492124636228723f, 0.36112343500006006f, 0.23069074183792804f, 0.09649209709474871f, 0.0f, 
	0.0f, 0.13103392424311142f, 0.27156864091531646f, 0.41098491062604847f, 0.5482460485473744f, 0.68056171750003f, 0.7979694910895578f, 0.8571428571428571f, 0.7979694910895578f, 0.68056171750003f, 0.5482460485473744f, 0.41098491062604847f, 0.27156864091531646f, 0.13103392424311142f, 0.0f, 
	0.0f, 0.14285714285714288f, 0.2857142857142857f, 0.42857142857142855f, 0.5714285714285714f, 0.7142857142857142f, 0.8571428571428571f, 1.0f, 0.8571428571428571f, 0.7142857142857142f, 0.5714285714285714f, 0.42857142857142855f, 0.2857142857142857f, 0.14285714285714288f, 0.0f, 
	0.0f, 0.13103392424311142f, 0.27156864091531646f, 0.41098491062604847f, 0.5482460485473744f, 0.68056171750003f, 0.7979694910895578f, 0.8571428571428571f, 0.7979694910895578f, 0.68056171750003f, 0.5482460485473744f, 0.41098491062604847f, 0.27156864091531646f, 0.13103392424311142f, 0.0f, 
	0.0f, 0.09649209709474871f, 0.23069074183792804f, 0.36112343500006006f, 0.48492124636228723f, 0.5959389821791157f, 0.68056171750003f, 0.7142857142857142f, 0.68056171750003f, 0.5959389821791157f, 0.48492124636228723f, 0.36112343500006006f, 0.23069074183792804f, 0.09649209709474871f, 0.0f, 
	0.0f, 0.041685152500090084f, 0.16700687216495708f, 0.2857142857142857f, 0.39390847326867356f, 0.48492124636228723f, 0.5482460485473744f, 0.5714285714285714f, 0.5482460485473744f, 0.48492124636228723f, 0.39390847326867356f, 0.2857142857142857f, 0.16700687216495708f, 0.041685152500090084f, 0.0f, 
	0.0f, 0.0f, 0.08526796608102157f, 0.19187796435823135f, 0.2857142857142857f, 0.36112343500006006f, 0.41098491062604847f, 0.42857142857142855f, 0.41098491062604847f, 0.36112343500006006f, 0.2857142857142857f, 0.19187796435823135f, 0.08526796608102157f, 0.0f, 0.0f, 
	0.0f, 0.0f, 0.0f, 0.08526796608102157f, 0.16700687216495708f, 0.23069074183792804f, 0.27156864091531646f, 0.2857142857142857f, 0.27156864091531646f, 0.23069074183792804f, 0.16700687216495708f, 0.08526796608102157f, 0.0f, 0.0f, 0.0f, 
	0.0f, 0.0f, 0.0f, 0.0f, 0.041685152500090084f, 0.09649209709474871f, 0.13103392424311142f, 0.14285714285714288f, 0.13103392424311142f, 0.09649209709474871f, 0.041685152500090084f, 0.0f, 0.0f, 0.0f, 0.0f, 
	0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 
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
    for(int x = 0;x<l->w+2;x++){
        for(int y = 0;y<l->h+2;y++){
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