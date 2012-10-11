#include "../app/App.h"
#include "City.h"
#include "Tile.h"
#include "RoadSegment.h"
#include "../entities/Entity.h"

City::City(SDL_Surface* surf_Display, SDL_Surface* surf_RoadTiles)
{
    mainDisplay = surf_Display;
    roadTiles = surf_RoadTiles;
    //Populate the array with new tiles.
    for(int i = 0; i < MAX_X; i++)
    {
	for(int j = 0; j < MAX_Y; j++)
	{
	    
	    Tiles[i][j] = new RoadSegment(surf_Display,surf_RoadTiles,this, i,j);
	    
	    if(rand()%100 > 70)
	    {
		Tiles[i][j]->type = Tile::TT_NONE;
	    }
	}
    }
    
    //Initialize the road system
    for(int i = 0; i < MAX_X; i++)
    {
	for(int j = 0; j < MAX_Y; j++)
	{
	    RoadSegment* currSeg = (RoadSegment*)Tiles[i][j];
	    currSeg->InitRoad();
	}
    }
}

City::~City()
{
    for(int i = 0; i < MAX_X; i++)
    {
	for(int j = 0; j < MAX_Y; j++)
	{
	    if(Tiles[i][j]->type == Tile::TT_ROAD)
		delete Tiles[i][j];
	}
    }
    
    for(int i = 0 ; i < EntityList.size(); i++)
    {
	delete EntityList[i];
    }
    /*
    for(int i = 0 ; i < BuildingList.size(); i++)
    {
	delete BuildingList[i];
    }*/
}

bool City::OnInit()
{
    //TODO: This will be used to load City info from a file.
    return true;
}

void City::OnUpdate()
{
    //Draw Entities on top of the map.
    for(int i = 0; i < EntityList.size(); i++)
    {
	EntityList[i]->OnUpdate();
    }
}

void City::OnRender()
{
    /**************************************************************************
     * The Tiles array will only be used as a base to determine what's a road
     * and what's a building. If it's a road we'll store it directly in the
     * array since it's a 1x1 tile and just call it's update and render
     * functions from that array. Buildings may cover more than 1 tile
     * and therefore will be stored in a separate array and will be called
     * to render and update form there.
     *************************************************************************/
    
    //Draw Roads.
    for(int i = 0; i < City::MAX_X; i++)
    {
	for(int j = 0; j < City::MAX_Y; j++)
	{
	    if(Tiles[i][j]->type == Tile::TT_ROAD)
		Tiles[i][j]->OnRender();
	}
    }
    
    //Draw buildings:
    /*
    for(int i = 0 ; i < BuildingList.size(); i++)
    {
	BuildingList[i]->OnRender();
    }*/
    
    //Draw Entities on top of the map.
    for(int i = 0; i < EntityList.size(); i++)
    {
	EntityList[i]->OnRender();
    }
}
/*
void City::AddBuilding(Building* bld)
{
    for(int i = bld->GetX(); i < bld->GetX() + bld->GetWidth(); i++)
    {
	for(int j = bld->GetY(); j < bld->GetY() + bld->GetHeight(); j++)
	{
	    delete Tiles[i][j];
	    Tiles[i][j] = bld;
	}
    }
}
*/
Tile* City::GetTile(int x, int y)
{
    if( x < 0 || x >= MAX_X)
	return NULL;
    if(y < 0 || y >= MAX_Y)
	return NULL;
    return Tiles[x][y];
}

