#ifndef _APP_H_
#define _APP_H_

#include <SDL/SDL.h>
#include <iostream>

#include "Event.h"
#include "Surface.h"
#include "../world/Tile.h"
#include "../entities/Entity.h"
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
    
    void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
    
    //SDL_Surface* GetDisplay();
    
    //SDL_Surface* GetTileSheet(Tile::TILE_TYPE type);
};

#endif
