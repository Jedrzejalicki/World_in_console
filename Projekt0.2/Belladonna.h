#pragma once
#include "Plant.h"

#define BELLADONNA_LOOK '#'
#define BELLADONNA_STRENGTH 99
#define BELLADONNA_SOW_PROPABILITY 6
class Belladonna :
    public Plant
{
public:
    Belladonna(World& world, Point* position, int age, Commentator* commentator);
    void collision(Organism* rival, World* world) override;
};

