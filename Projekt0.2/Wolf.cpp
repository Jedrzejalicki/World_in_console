#include "Wolf.h"


Wolf::Wolf(World& world, Point* position,  int age, Commentator* commentator)
	:Animal(world, position, WOLF_LOOK, WOLF_STRENGTH, WOLF_INITIATIVE, age, WOLF_RANGE, false,WOLF, commentator) {
}

