/******************************************************************************
 * Abstract *
 * The base class for all other Tile types.
 *****************************************************************************/

#ifndef _TILE_H_
#define _TILE_H_

#include "../app/App.h"

class Tile
{
    /* UTIL */
public:
    enum TILE_TYPE
    {
	TT_NONE,
	TT_ROAD,
	TT_BUILDING,
	TT_PARK
    };
    //Size, in pixels, of each tile. They're square, so only 1 side is needed.
    static const int tileSize = 32;
    
    /* MEMBERS */
public:
    TILE_TYPE type;
    
protected:
    int X;	//X in TILES
    int Y;	//Y in
    int tileX, tileY;
    SDL_Surface* tileSheet;
    SDL_Surface* mainDisplay;
    
    /* CONSTRUCTORS */
public:
    Tile(SDL_Surface* surf_Display, SDL_Surface* surf_tiles, int initX, int initY);
    ~Tile();
    
    /* METHODS */
public:
    virtual void OnUpdate() = 0;
    virtual void OnRender() = 0;
    
    int GetX() { return X; }
    int GetY() { return Y; }
    
};

#endif