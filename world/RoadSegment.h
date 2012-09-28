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
    static enum ROAD_CONNECTIONS
    {
	LEFT	= 0x00,
	RIGHT	= 0x01,
	UP	= 0x02,
	DOWN	= 0x04
    };
    

    /* MEMBERS */
public:
    
private:
    unsigned short connections;

    /* CONSTRUCTORS */
public:
    RoadSegment(Game* mainGame, int myX, int myY);
    ~RoadSegment();
    
    /* METHODS */
public:
    void OnUpdate();
    void OnRender();
    
    
};

#endif