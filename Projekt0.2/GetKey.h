#pragma once
#include"Direction.h"
#include"World.h"
using namespace std;

class World;
class Getter
{
public:
	int option = 0;
	Direction dir;
	bool ability;
	void passDirection();
	World* world;

	Getter(World* world);
};

