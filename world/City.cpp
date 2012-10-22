#include "../app/App.h"
#include "City.h"
#include "Tile.h"
#include "RoadSegment.h"
#include "Park.h"
#include "../entities/Entity.h"
#include <time.h>

//Forward declaration because fuck you compiler!
class Park;

City::City(SDL_Surface* surf_Display, SDL_Surface* surf_RoadTiles, SDL_Surface* surf_Park)
{
    mainDisplay = surf_Display;
    roadTiles = surf_RoadTiles;
    parkTiles = surf_Park;
    //Populate the array with new tiles.
    for(int i = 0; i < MAX_X; i++)
    {
	for(int j = 0; j < MAX_Y; j++)
	{
	    Tiles[i][j] = new Park(surf_Display, surf_Park, i,j);
	    
	    /* FILL WITH ROAD SEGMENTS
	    Tiles[i][j] = new RoadSegment(surf_Display,surf_RoadTiles,this, i,j);
	    
	    if(rand()%100 > 70)
	    {
		Tiles[i][j]->type = Tile::TT_NONE;
	    }
	    */
	}
    }
    
    MakeRoads();
    
    /*
    //Initialize the road system
    for(int i = 0; i < MAX_X; i++)
    {
	for(int j = 0; j < MAX_Y; j++)
	{
	    if(Tiles[i][j]->type == Tile::TT_ROAD)
	    {
		RoadSegment* currSeg = (RoadSegment*)Tiles[i][j];
		currSeg->InitRoad();
	    }
	}
    }*/
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
    /*for(int i = 0; i < EntityList.size(); i++)
    {
	EntityList[i]->OnUpdate();
    }*/
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
    /*for(int i = 0; i < EntityList.size(); i++)
    {
	EntityList[i]->OnRender();
    }*/
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

void City::MakeRoads()
{
    //srand( time( NULL ) );
    std::vector<Tile*> placed;
    int roads = 0;
    while(roads < 1)
    {
	//Choose a side to start on
	DIRECTION startDir = (DIRECTION)(rand() % (WEST + 1));
	
	//Choose a random starting coordinate
	int startX = 0;
	int startY = 0;
	if(startDir <= SOUTH)
	{
	    if(startDir == SOUTH)
		startY = MAX_Y-1;
	    startX = rand() % (MAX_X);
	}
	else
	{
	    if(startDir == EAST)
		startX = MAX_X-1;
	    startY = rand() % (MAX_Y);
	}
	
	//If the starting position is already a road, re-start the loop, generating new starting coords.
	if(Tiles[startX][startY]->type == Tile::TT_ROAD)
	    continue;
	
	// if not; make it one!
	Tiles[startX][startY] = new RoadSegment(mainDisplay,roadTiles,this, startX,startY);
	placed.push_back(Tiles[startX][startY]);
	
	bool cont = true;
	
	//Check the next tile in the appropriate direction
	switch(startDir)
	{
	    case NORTH:
		while(startY < MAX_Y && cont)
		{
		    startY++;
		    cont = PlaceRoad(&placed, startX, startY);
		}
		break;
	    case SOUTH:
		while(startY >= 0 && cont)
		{
		    startY--;
		    cont = PlaceRoad(&placed, startX, startY);
		}
		break;
	    case EAST:
		while(startX >= 0 && cont)
		{
		    startX--;
		    cont = PlaceRoad(&placed, startX, startY);
		}
		break;
	    case WEST:
		while(startX < MAX_X && cont)
		{
		    startX++;
		    cont = PlaceRoad(&placed, startX, startY);
		}
		break;
	}
	roads++;
    }
	//TODO: GIVE THIS AN ENDING CONDITION!
    /*for(int i = 0; i < placed.size(); i++)
    {
	RoadSegment* seg = (RoadSegment*)placed[i];
	seg->InitRoad();
    }
    placed.clear();*/
    RefreshRoads();
}

void City::RefreshRoads()
{
    for(int i = 0; i < MAX_X; i++)
    {
	for(int j = 0; j < MAX_Y; j++)
	{
	    if(Tiles[i][j]->type == Tile::TT_ROAD)
	    {
		RoadSegment* currSeg = (RoadSegment*)Tiles[i][j];
		currSeg->InitRoad();
	    }
	}
    }
}

bool City::PlaceRoad(std::vector<Tile*>* placed, int x, int y)
{
    int chanceTo4way = 50;
    
    bool rval = false;
    if(GetTile(x,y) != NULL)
    {
	if(GetTile(x,y)->type == Tile::TT_ROAD)
	{
	    if(rand() % (101) < chanceTo4way)
		rval = true;
	}
	else
	{
	    rval = true;
	}
	
	if(rval)
	{
	    Tiles[x][y] = new RoadSegment(mainDisplay,roadTiles,this, x,y);
	    placed->push_back(Tiles[x][y]);   
	}
    }
}