#pragma once
#include "Animal.h"




#define TURTLE_LOOK 'T'
#define TURTLE_NAME "Turtle"
#define TURTLE_RANGE 1
#define TURTLE_STRENGTH 2
#define TURTLE_INITIATIVE 1
#define TURTLE_MEDITATION_SKILL 75


class Turtle :
    public Animal
{
private:
	int meditation_skill;
public:
	 Turtle(World& world, Point* position, int age, Commentator* commentator);
	 void action(World* world) override;
	 void collision(Organism* rival, World* world) override;
};

