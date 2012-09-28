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
#include "Building.h"

class City
{
    /* UTIL */
    std::vector<Entity*> EntityList;
    std::vector<Building*> BuildingList;
    
    /* MEMBERS */
public:
    
    //TODO: Eventually change these to non-static.
    static const int MAX_X = 40;
    static const int MAX_Y = 20;
    Tile* Tiles[MAX_X][MAX_Y];
    
private:
    Game* mainGame;

    /* CONSTRUCTORS */
public:
    City(Game* gamePtr);
    ~City();
    
    /* METHODS */
public:
    bool OnInit();
    void OnUpdate();
    void OnRender();
    
    void AddBuilding(Building* bld);
    Tile* GetTile(int x, int y);
};

#endif