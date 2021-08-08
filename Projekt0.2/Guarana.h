#pragma once
#include "Plant.h"

#define GUARANA_LOOK '@'
#define GUARANA_ABILITY 3
#define GUARANA_SOW_PROPABILITY 8
class Guarana :
    public Plant
{
public:
	Guarana(World& world, Point* position, int age,Commentator*commentator);
	void collision(Organism* rival, World* world);
};
 
