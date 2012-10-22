/******************************************************************************
 * The City class is essentially a map. It's going to store a pointer to all
 * of the tiles that make up the city.
 * 
 * The X and Y variables can be changed on map creation to allow different
 * sized worlds.
 *****************************************************************************/

#ifndef _CITY_H_
#define _CITY_H_

#include "../app/App.h"
#include "Tile.h"
#include "../entities/Entity.h"

//Forward Declaration so the compiler stops pissing me off.
class Tile;

class City
{
public:
    /* UTIL */
    std::vector<Entity*> EntityList;
    //std::vector<Building*> BuildingList;
    
    enum DIRECTION {
	NORTH,
	SOUTH,
	EAST,
	WEST,
    };
    
    /* MEMBERS */
public:
    
    //TODO: Eventually change these to non-static.
    static const int MAX_X = 25;
    static const int MAX_Y = 18;
    Tile* Tiles[MAX_X][MAX_Y];
    
private:
    SDL_Surface* mainDisplay;
    SDL_Surface* roadTiles;
    SDL_Surface* parkTiles;

    /* CONSTRUCTORS */
public:
    City(SDL_Surface* surf_Display, SDL_Surface* surf_RoadTiles,SDL_Surface* surf_Park);
    ~City();
    
    /* METHODS */
public:
    bool OnInit();
    void OnUpdate();
    void OnRender();
    
    void MakeRoads();
    
    //void AddBuilding(Building* bld);
    Tile* GetTile(int x, int y);
    
private:
     bool PlaceRoad(std::vector< Tile* >* placed, int x, int y);
     void RefreshRoads();
};

#endif