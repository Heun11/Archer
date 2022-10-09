#include"tiles.h"

TOOLS_SDL_Image* archer_right[2];
TOOLS_SDL_Image* archer_left[2];
TOOLS_SDL_Image* bricks[9];
TOOLS_SDL_Image* woods[9];
TOOLS_SDL_Image* backBrick;
TOOLS_SDL_Image* doors[2];
TOOLS_SDL_Image* arrow[2];
TOOLS_SDL_Image* barrel;
TOOLS_SDL_Image* create;
TOOLS_SDL_Image* moss;
TOOLS_SDL_Image* spikes[4];
TOOLS_SDL_Image* target[2];
TOOLS_SDL_Image* rat[2];
TOOLS_SDL_Image* banner;
TOOLS_SDL_Image* chains;

void TILES_Load_Tiles(SDL_Surface* tileset)
{
    archer_right[0] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 0, 0);
    archer_right[1] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 1, 0);
	
    archer_left[0] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 2, 0);
    archer_left[1] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 3, 0);
	
	bricks[0] =	TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 0, 1);
	bricks[1] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 1, 1);
	bricks[2] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 2, 1);
	bricks[3] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 3, 1);
	bricks[4] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 4, 1);
	bricks[5] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 0, 2);
	bricks[6] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 1, 2);
	bricks[7] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 2, 2);
	bricks[8] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 3, 2);

    woods[0] =TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 0, 3);
	woods[1] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 1, 3);
	woods[2] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 2, 3);
	woods[3] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 3, 3);
	woods[4] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 4, 3);
	woods[5] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 0, 4);
	woods[6] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 1, 4);
	woods[7] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 2, 4);
	woods[8] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 3, 4);

	backBrick = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 7, 3);

	doors[0] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 6, 0);
	doors[1] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 7, 0);

	arrow[0] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 4, 0);
	arrow[1] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 5, 0);

	barrel =  TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 5, 1);

	create =  TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 6, 1);

	moss =  TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 7, 1);

	spikes[0] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 4, 2);
	spikes[1] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 5, 2);
	spikes[2] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 6, 2);
	spikes[3] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 7, 2);

	target[0] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 5, 3);
	target[1] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 6, 3);

	rat[0] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 6, 4);
	rat[1] = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 7, 4);

	banner = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 4, 4);

	chains = TOOLS_SDL_Image_Load_Tile_From_Tileset_Surface(rend, tileset, TILE_SIZE_REAL, TILE_SIZE_REAL, 5, 4);
}