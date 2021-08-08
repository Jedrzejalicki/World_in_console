#pragma once
#include "Plant.h"
#define SOSNOWSKY_HOGWEED_LOOK '$'
#define SOSNOWSKY_HOGWEED_STRENGTH 10
#define SOSNOWSKY_HOGWEED_SOW_PROPABILITY 2
class Sosnowsky_hogweed :
    public Plant
{
public:
    Sosnowsky_hogweed(World& world, Point* position, int age, Commentator* commentator);
    void action(World* world) override;
    void collision(Organism* rival, World* world);
};

