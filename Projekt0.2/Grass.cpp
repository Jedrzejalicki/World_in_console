	#include "Grass.h"

Grass::Grass(World& world, Point* position, int age,Commentator* commentator) :
	Plant(world, position, GRASS_LOOK, NULL, age, NULL, false, GRASS,SOW_PROPABILITY,  commentator) {
}
