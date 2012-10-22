#include "RoadSegment.h"
#include "City.h"
#include "../app/Surface.h"

RoadSegment::RoadSegment(SDL_Surface* mainDisplay, SDL_Surface* myTiles, City* whatCity, int myX, int myY):
	Tile(mainDisplay,myTiles, myX, myY)
{
    type = TT_ROAD;
    
    connections = 0;
    
    myCity = whatCity;
}

RoadSegment::~RoadSegment()
{
    //
}

void RoadSegment::InitRoad()
{
    connections = 0;
    //Test what connections we have.
    if(myCity->GetTile(X - 1,Y) != NULL && myCity->GetTile(X - 1,Y)->type == TT_ROAD)
    {
	connections += LEFT;
    }
    if(myCity->GetTile(X + 1,Y) != NULL && myCity->GetTile(X + 1,Y)->type == TT_ROAD)
    {
	connections += RIGHT;
    }
    if(myCity->GetTile(X,Y - 1) != NULL && myCity->GetTile(X,Y - 1)->type == TT_ROAD)
    {
	connections += UP;
    }
    if(myCity->GetTile(X,Y + 1) != NULL && myCity->GetTile(X,Y + 1)->type == TT_ROAD)
    {
	connections += DOWN;
    }
    
    //Figure out what tile we should have.
    if(connections & LEFT)
    {
	if(connections & RIGHT)
	{
	    if(connections & UP)
	    {
		if(connections & DOWN)
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
	    else if(connections & DOWN)
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
	else if(connections & DOWN)
	{
	    if(connections & UP)
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
	else if(connections & UP)
	{
	    //Left, Up turn.
	    tileX = 2;
	    tileY = 2;
	}
    }
    else if(connections & RIGHT)
    {
	if(connections & UP)
	{
	    if(connections & DOWN)
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
	else if(connections & DOWN)
	{
	    //Right Down turn.
	    tileX = 1;
	    tileY = 1;
	}
	else
	{
	    tileX = 2;
	    tileY = 3;
	}
    }
    else
    {
	//Straight Up Down
	tileX = 1;
	tileY = 3;
    }
}

void RoadSegment::OnUpdate()
{
    //
}

void RoadSegment::OnRender()
{
    //Surface::OnDraw(Surf_Display,Surf_Entity,X,Y,0,Anim_Control.GetCurrentFrame() * Height,Width,Height);
    Surface::OnDraw(mainDisplay,tileSheet,
		    (X * tileSize),(Y * tileSize),
		    (tileX * tileSize)-tileSize,(tileY * tileSize)-tileSize,
		    tileSize,tileSize);
}
