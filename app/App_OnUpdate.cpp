#include "App.h"

void Game::OnUpdate()
{
    /**************************************************************************
     * This will eventually be used more, once an FSM is added in to control
     * the game state. For now it just defers all rendering to the city.
     *************************************************************************/
    
    //Update everything.
    currCity->OnUpdate();
}