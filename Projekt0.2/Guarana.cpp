#include "Guarana.h"
#include"Animal.h"
Guarana::Guarana(World& world, Point* position, int age,Commentator* commentator) :
	Plant(world, position, GUARANA_LOOK, NULL, age, NULL, true, GUARANA,GUARANA_SOW_PROPABILITY,  commentator) {
}


void Guarana::collision(Organism* rival, World* world) {
		rival->addToStrength(GUARANA_ABILITY);
		Plant::collision(rival,world);
}
