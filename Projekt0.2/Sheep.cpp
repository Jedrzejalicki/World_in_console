#include "Sheep.h"

Sheep::Sheep(World& world, Point* position, int age, Commentator* commentator)
	:Animal(world, position, SHEEP_LOOK, SHEEP_STRENGTH, SHEEP_INITIATIVE, age, SHEEP_RANGE, false,SHEEP,  commentator){
}

