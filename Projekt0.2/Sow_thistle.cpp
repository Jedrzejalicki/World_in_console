#include "Sow_thistle.h"
Sow_thistle::Sow_thistle(World& world, Point* position, int age,Commentator* commentator) :
	Plant(world, position, SOW_THISTLE_LOOK, NULL, age, NULL, false, SOW_THISTLE, SOW_SOW_PROPABILITY,  commentator){
}

void Sow_thistle::action(World* world) {
	int check = 0;
	while (!this->spreadWithSucces() && check < 3) {
		Plant::action(world);
		check++;
	}
}