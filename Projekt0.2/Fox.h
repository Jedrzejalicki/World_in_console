#pragma once
#include "Animal.h"

#define FOX_LOOK 'F'
#define FOX_NAME "FOX"
#define FOX_RANGE 1
#define FOX_STRENGTH 3
#define FOX_INITIATIVE 7


class Fox :
    public Animal
{
public:
   Fox(World& world, Point* position, int age, Commentator* commentator);
   void action(World* world) override;
};

