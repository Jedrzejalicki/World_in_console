#pragma once
#include "Animal.h"

#define SHEEP_LOOK 'S'
#define SHEEP_NAME "SHEEP"
#define SHEEP_RANGE 1
#define SHEEP_STRENGTH 4
#define SHEEP_INITIATIVE 4


class Sheep :
    public Animal
{
public:
    Sheep(World& world, Point* position, int age, Commentator* commentator);
};

