#ifndef _APP_H_
#define _APP_H_

#include <SDL/SDL.h>
#include <iostream>

#include "Event.h"
#include "../entities/Entity.h"
#include "../world/Tile.h"
#include "../world/City.h"

class Game : public Event
{
public:
    bool running;
    City* currCity;
    
    SDL_Surface* Surf_Display;
    
public:
    Game();
    
    void OnExecute();
    bool OnInit();
    
    void OnCleanup();
    void OnExit();
    
    void OnUpdate();
    void OnRender();
    void OnEvent(SDL_Event* Event);
    
    SDL_Surface* GetDisplay() { return Surf_Display; }
    SDL_Surface* GetTileSheet(Tile::TILE_TYPE type);
};

#endif
