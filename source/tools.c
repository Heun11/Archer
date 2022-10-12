#include"tools.h"

int TOOLS_Random_Number(int start, int stop)
{
	if(SRAND_CALL!=-1){
		srand(time(0));
		SRAND_CALL = -1;
	}
	return (rand()%(stop-start+1))+start;
}

void get_error()
{
	printf("Error with sdl: %s\n", SDL_GetError());
	fflush(stdout);
	exit(0);
}

TOOLS_TileMap TOOLS_Load_TileMap_From_File_To_Array(char* filename)
{
	TOOLS_TileMap m;
	FILE* f;
	f = fopen(filename, "r");
	fscanf(f, "%d %d", &m.w, &m.h);
	m.l0 = malloc(m.w*m.h*sizeof(int));
	m.l1 = malloc(m.w*m.h*sizeof(int));
	m.l2 = malloc(m.w*m.h*sizeof(int));
	for(int i=0;i<m.h*m.w;i++){
		fscanf(f, "%d", &m.l0[i]);
	}
	for(int i=0;i<m.h*m.w;i++){
		fscanf(f, "%d", &m.l1[i]);
	}
	for(int i=0;i<m.h*m.w;i++){
		fscanf(f, "%d", &m.l2[i]);
	}
	fclose(f);
	return m;
}

void TOOLS_Free_Tilemap(TOOLS_TileMap* m)
{
	free(m->l0);
	free(m->l1);
	free(m->l2);
}

TOOLS_SDL_Image* TOOLS_SDL_Image_Load_From_Surface(SDL_Renderer* r, SDL_Surface* s, int s_x, int s_y, int s_w, int s_h)
{
	TOOLS_SDL_Image* i = malloc(sizeof(TOOLS_SDL_Image));
	i->src = malloc(sizeof(SDL_Rect));

	i->src->x = s_x;
	i->src->y = s_y;
	i->src->w = s_w;
	i->src->h = s_h;

	i->tex = SDL_CreateTextureFromSurface(r, s);
	//SDL_QueryTexture(image->tex, NULL, NULL, &image->src->w, &image->src->h);
	return i;
}

void TOOLS_SDL_Image_RenderCopy(SDL_Renderer* r, TOOLS_SDL_Image* i, int x, int y, int w, int h)
{
	SDL_RenderCopy(r, i->tex, i->src, &(SDL_Rect){x,y,w,h});
}

TOOLS_SDL_Image* TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(SDL_Renderer* r, SDL_Surface* s, int t_w, int t_h, int x, int y)
{
	//TOOLS_SDL_Image_Load_From_Surface(rend, tileset, 1+0*(TILE_SIZE_REAL+1),1+1*(TILE_SIZE_REAL+1),TILE_SIZE_REAL,TILE_SIZE_REAL), 
	return TOOLS_SDL_Image_Load_From_Surface(r, s, x*t_w, y*t_h, t_w, t_h);
}

void TOOLS_SDL_Text_RenderCopy(SDL_Renderer* r, TTF_Font* f, char* s, int x, int y, int w, int h, SDL_Color c)
{
	SDL_Surface* surf = TTF_RenderText_Solid(f, s, c);
	SDL_Texture* t = SDL_CreateTextureFromSurface(r, surf);
	SDL_FreeSurface(surf);
	SDL_RenderCopy(r, t, NULL, &(SDL_Rect){x, y, w, h});
	SDL_DestroyTexture(t);
}

int TOOLS_Collide_Rect(SDL_Rect r1, SDL_Rect r2)
{
	return r1.x<r2.x+r2.w &&
		r1.x+r1.w>r2.x &&
		r1.y<r2.y+r2.h &&
		r1.y+r1.h>r2.y;
}

void TOOLS_Play_Animation(SDL_Renderer* r, TOOLS_SDL_Image** images, float* anim_c, int fps, int anim_len, int x, int y, int w, int h)
{
	float n = (float)fps/60.0f;
	*anim_c+=n;
	if(*anim_c>=anim_len){
		*anim_c = 0;
	}
	TOOLS_SDL_Image_RenderCopy(r, images[(int)*anim_c], x, y, w, h);
}
