#ifndef _BUILDING_H_
#define _BUILDING_H_

#include "../app/App.h"
#include "Tile.h"

class Building : public Tile
{
    /* MEMBERS */
private:
    SDL_Surface* myTexture;
    int width; //Width in TILES, NOT pixels.
    int height; //Height in TILES, NOT pixels.

    /* CONSTRUCTORS */
public:
    Building();
    ~Building();
    
    /* METHODS */
public:
    void OnUpdate();
    void OnRender();
    
    int GetWidth() { return width; }
    int GetHeight() { return height; }
};

#endif