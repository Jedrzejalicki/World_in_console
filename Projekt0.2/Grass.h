#pragma once
#include "Plant.h"


#define GRASS_LOOK '+'
#define SOW_PROPABILITY 10
class Grass :
    public Plant
{
public:


        Grass(World& world, Point* position, int age, Commentator* commentator);
};

