#pragma once
#include "Animal.h"


#define ANTELOPE_LOOK 'A'
#define ANTELOPE_NAME "ANTELOPE"
#define ANTELOPE_RANGE 2
#define ANTELOPE_STRENGTH 4
#define ANTELOPE_INITIATIVE 4
#define ANTELOPE_FLEE_SKILL 50



class Antelope :
    public Animal
{
private:
    int flee_skill;
public:
    Antelope(World& world, Point* position, int age, Commentator* commentator);

    void collision(Organism* rival, World* world) override;
};

