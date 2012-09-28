#include "Tile.h"

Tile::Tile(App* mainGame, int initX, int initY)
{
    
    type = TT_NONE;
    
    mainDisplay = mainGame->GetDisplay();
    tileSheet = mainGame->GetTileSheet(type);
    
    X = initX;
    Y = initY;
}

Tile::~Tile()
{

}

void Tile::OnUpdate()
{
    //Pure Virtual
}

void Tile::OnRender()
{

    //NOTE: Could possible have 'empty' tiles render as just a green block, like a park or forest or something.
    //Pure Virtual
}
