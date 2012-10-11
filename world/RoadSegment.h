#ifndef _ROADSEGMENT_H_
#define _ROADSEGMENT_H__H_

#include "../app/App.h"
#include "Tile.h"
#include "City.h"

class RoadSegment : public Tile
{
    /* UTIL */
public:
    //This will be used in the constructor to decide what road tile to use.
    enum ROAD_CONNECTIONS
    {
	LEFT	= 0x01,
	RIGHT	= 0x02,
	UP	= 0x04,
	DOWN	= 0x08
    };
    

    /* MEMBERS */
public:
    
private:
    unsigned short connections;
    City* myCity;

    /* CONSTRUCTORS */
public:
    RoadSegment(SDL_Surface* surf_Display, SDL_Surface* surf_RoadTiles, City* whatCity, int myX, int myY);
    ~RoadSegment();
    
    /* METHODS */
public:
    void OnUpdate();
    void OnRender();
    void InitRoad();
    
};

#endif