#include "Belladonna.h"

Belladonna::Belladonna(World& world, Point* position, int age, Commentator* commentator):
	Plant(world, position, BELLADONNA_LOOK, BELLADONNA_STRENGTH, age, NULL, true, BELLADONA, BELLADONNA_SOW_PROPABILITY, commentator) {
}


void Belladonna::collision(Organism* rival, World* world) {
	world->killOrganism(this);
	world->killOrganism(rival);
}