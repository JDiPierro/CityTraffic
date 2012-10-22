#include "App.h"
#include "../world/RoadSegment.h"

bool Game::OnInit()
{
    /* 
     * SDL Initialization:
     */
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
	std::cout << "SDL Init Failed." << std::endl;
	return false;
    }
/*
 * Initialize Window:
 */
    if((Surf_Display = SDL_SetVideoMode(800, 576, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    {
	std::cout << "Display Create Failed." << std::endl;
	return false;
    }
    SDL_Surface* surf_Road = Surface::OnLoad("./gfx/roads.png");
    SDL_Surface* surf_Park = Surface::OnLoad("./gfx/park.png");
    
    currCity = new City(Surf_Display,surf_Road,surf_Park);
    if(!currCity->OnInit())
    {
	std::cout << "City Init failed." << std::endl;
	return false;
    }
    
    return true;
}