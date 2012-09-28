#include "RoadSegment.h"
#include "City.h"
#include <../Gradius/app/Surface.h>

RoadSegment::RoadSegment(Game* mainGame, int myX, int myY):
	Tile(mainGame, myX, myY)
{
    type = TT_ROAD;
    
    tileSheet = mainGame->GetTileSheet(type);
    
    connections = 0;
    
    //Test what connections we have.
    if(whatCity->GetTile(X - 1,Y) != nullptr && whatCity->GetTile(X - 1,Y)->type == TILE_TYPE::TT_ROAD)
    {
	connections += ROAD_CONNECTIONS::LEFT;
    }
    if(whatCity->GetTile(X + 1,Y) != nullptr && whatCity->GetTile(X + 1,Y)->type == TILE_TYPE::TT_ROAD)
    {
	connections += ROAD_CONNECTIONS::RIGHT;
    }
    if(whatCity->GetTile(X,Y - 1) != nullptr && whatCity->GetTile(X,Y - 1)->type == TILE_TYPE::TT_ROAD)
    {
	connections += ROAD_CONNECTIONS::UP;
    }
    if(whatCity->GetTile(X,Y + 1) != nullptr && whatCity->GetTile(X,Y + 1)->type == TILE_TYPE::TT_ROAD)
    {
	connections += ROAD_CONNECTIONS::DOWN;
    }
    
    //Figure out what tile we should have.
    if(connections & ROAD_CONNECTIONS::LEFT)
    {
	if(connections & ROAD_CONNECTIONS::RIGHT)
	{
	    if(connections & ROAD_CONNECTIONS::UP)
	    {
		if(connections & ROAD_CONNECTIONS::DOWN)
		{
		    //4-way
		    tileX = 1;
		    tileY = 4;
		}
		else
		{
		    //3-way Left, Right, Up
		    tileX = 3;
		    tileY = 1;
		    
		}
	    }
	    else if(connections & ROAD_CONNECTIONS::DOWN)
	    {
		//3-way Left, Right, Down
		tileX = 3;
		tileY = 3;
	    }
	    else
	    {
		//Straight left-right
		tileX = 2;
		tileY = 3;
	    }
	}
	else if(connections & ROAD_CONNECTIONS::DOWN)
	{
	    if(connections & ROAD_CONNECTIONS::UP)
	    {
		//3-way Left, Down, Up
		tileX = 3;
		tileY = 4;
	    }
	    else
	    {
		//Left Down turn.
		tileX = 2;
		tileY = 1;
	    }
	}
	else if(connections & ROAD_CONNECTIONS::UP)
	{
	    //Left, Up turn.
	    tileX = 2;
	    tileY = 2;
	}
    }
    else if(connections & ROAD_CONNECTIONS::RIGHT)
    {
	if(connections & ROAD_CONNECTIONS::UP)
	{
	    if(connections & ROAD_CONNECTIONS::DOWN)
	    {
		//3-way Up, Down, Right
		tileX = 3;
		tileY = 2;
	    }
	    else
	    {
		//Right Up Turn
		tileX = 1;
		tileY = 2;
	    }
	}
	else
	{
	    //Right Down turn.
	    tileX = 1;
	    tileY = 1;
	}
    }
    else
    {
	//Straight Up Down
	tileX = 1;
	tileY = 3;
    }
}

RoadSegment::~RoadSegment()
{
    //
}

void RoadSegment::OnUpdate()
{
    //
}

void RoadSegment::OnRender()
{
    //Surface::OnDraw(Surf_Display,Surf_Entity,X,Y,0,Anim_Control.GetCurrentFrame() * Height,Width,Height);
    Surface::OnDraw(mainDisplay,tileSheet,X * tileSize,Y * tileSize,tileX * tileSize,tileY * tileSize,tileSize,tileSize);
}
