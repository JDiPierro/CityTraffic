#include "Tile.h"

Tile::Tile(SDL_Surface* surf_Display, SDL_Surface* surf_tiles, int initX, int initY)
{
    
    type = TT_NONE;
    
    mainDisplay = surf_Display;
    tileSheet = surf_tiles;
    
    X = initX;
    Y = initY;
}

Tile::~Tile()
{

}