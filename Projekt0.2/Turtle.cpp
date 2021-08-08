#include "Turtle.h"


Turtle::Turtle(World& world, Point* position, int age, Commentator* commentator)
	:Animal(world, position, TURTLE_LOOK, TURTLE_STRENGTH, TURTLE_INITIATIVE, age, TURTLE_RANGE, true,TURTLE, commentator) {
	this->meditation_skill = TURTLE_MEDITATION_SKILL;
}


void Turtle::action(World* world) {
	int randomFactors = rand() % 100;
	if (randomFactors > this->meditation_skill)
		Animal::action(world);

}


void Turtle::collision(Organism* rival, World* world) {
	if (rival->GetStrength() > 5) {
		Animal::collision(rival, world);
//		cout << "attack on turtle was succesfull" << endl;
	}
	else {
//		cout << "attack on turtle was unsuccesfull"<<endl;
	}
}