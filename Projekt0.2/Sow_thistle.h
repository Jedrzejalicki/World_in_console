#pragma once
#include "Plant.h"
#define SOW_THISTLE_LOOK '/'
#define SOW_SOW_PROPABILITY 10
class Sow_thistle :
	public Plant
{
public:
	Sow_thistle(World& world, Point* position, int age, Commentator* commentator);
	void action(World* world) override;
};

