#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <vector>
#include "../app/App.h"

class Entity
{   
    
    /* MEMBERS */
public:
    
private:
    int x , y;
    int width, height; //In PIXELS
    bool crashed;
    
    //SDL_Surface* myTexture;
    //I'll eventually give the vehicles textures, but for now it's just boxes.
    SDL_Rect* myRect;
    
    
    /* CONSTRUCTORS */
public:
    Entity() {};
    ~Entity() {};
    
    /* METHODS */
public:
    
    void OnUpdate() {};
    void OnRender() {};
    void OnMove() {};
    
    void Collides(Entity* atFault) {}; //Because it's never your fault.
    
    bool CheckCarCrash(Entity* opp) {};
    //bool CheckBldCrash(Building* bld);
};

#endif