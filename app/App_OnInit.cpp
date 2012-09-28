#include "App.h"

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
    if((Surf_Display = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    {
	std::cout << "Display Create Failed." << std::endl;
	return false;
    }
    
    currCity = new City::City();
    if(!currCity->OnInit())
    {
	std::cout << "City Init failed." << std::endl;
	return false;
    }
}