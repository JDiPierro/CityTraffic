#include "App.h"

Game::Game()
{
	running = true;
}

void Game::OnExecute()
{
    #define FPS 35 //TODO: Allow target framerate to be set.
		    //1 second
    Uint32 waittime = 1000.0f/FPS;
    Uint32 framestarttime = 0;
    Sint32 delaytime;

    if(OnInit() == false)
	abort();

    SDL_Event Event;

    while(running)
    {
	while(SDL_PollEvent(&Event))
	    OnEvent(&Event);

	OnUpdate();
	OnRender();
	delaytime = waittime - (SDL_GetTicks() - framestarttime);
	if(delaytime > 0)
	    SDL_Delay((Uint32)delaytime);
	framestarttime = SDL_GetTicks();
    }

    OnCleanup();

    exit(0);
}

int main(int argc, char* argv[])
{
    Game gameApp;

    gameApp.OnExecute();
}
