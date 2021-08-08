#pragma once
#include "Animal.h"


#define WOLF_LOOK 'W'
#define WOLF_NAME "WOLF"
#define WOLF_RANGE 1
#define WOLF_STRENGTH 9
#define WOLF_INITIATIVE 5

class Commentator;
class Wolf : public Animal 
{

public:
	Wolf(World& world, Point* position, int age, Commentator* commentator);

};

