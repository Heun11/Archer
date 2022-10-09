#include"tiles.h"

TOOLS_SDL_Image* archer_right[2];
TOOLS_SDL_Image* archer_left[2];
TOOLS_SDL_Image* bricks[9];
TOOLS_SDL_Image* woods[9];

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
}