#include "App.h"
#include "../world/City.h"

Game::OnRender()
{
    /**************************************************************************
     * This will eventually be used more, once an FSM is added in to control
     * the game state. For now it just defers all rendering to the city.
     *************************************************************************/
    
    //Draw the Map
    currCity->OnRender();
}