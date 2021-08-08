#include "Antelope.h"


Antelope::Antelope(World& world, Point* position, int age, Commentator* commentator)
	:Animal(world, position, ANTELOPE_LOOK, ANTELOPE_STRENGTH, ANTELOPE_INITIATIVE, age, ANTELOPE_RANGE,true,ANTELOPE,  commentator){
	this->flee_skill = ANTELOPE_FLEE_SKILL;
}

void Antelope::collision(Organism* rival, World* world) {

	int randomFactors = rand()%100;

	if (randomFactors > ANTELOPE_FLEE_SKILL) {
		Animal::collision(rival, world);
	}
	else {
		Direction dir = randDir();

		while(!this->isGoodDirection(dir,world,this->GetPosition()))
			dir = randDir();
		this->goInDir(dir, this->GetPosition(),world);
		Point* nextPoint = new Point(this->GetNextX(), this->GetNextY());

		if (world->isFree(nextPoint)) {
//			cout << "antelope has fled from this fight";
			world->moveOrganism(this, this->GetNextX(), this->GetNextY());
		}
		else {
			this->collision(world->findOrg(nextPoint), world);
		}

	}
}


