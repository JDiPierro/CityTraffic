#include "App.h"
#include "../world/City.h"

void Game::OnRender()
{
    /**************************************************************************
     * This will eventually be used more, once an FSM is added in to control
     * the game state. For now it just defers all rendering to the city.
     *************************************************************************/
    
    //Draw the Map
    currCity->OnRender();
    SDL_Flip(Surf_Display);
}