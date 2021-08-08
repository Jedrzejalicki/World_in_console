#include "Animal.h"

Animal::Animal(World& world, Point* position, char look, int strength, int initiative, int age,int range,bool specialAbilities, Animals animal, Commentator* commentator)//an
	:Organism(world, position, look, strength, initiative,age,range, specialAbilities,true)
{
	this->animal = animal;
	this->bred = false;
	this->commentator = commentator;
}


void Animal::action(World* world) {
	Point* point = this->GetPosition();
	Direction dir = randDir();//drawing direction that animal will move towards

	if (this->isAlive()) {//checking if animal is alive
		while (!isGoodDirection(dir,world,point))//chekinmg if direction wont casue any error by trying to move over border
		{
			dir = randDir();
		}

		Animal::goInDir(dir, point,world);

		Point* nextPoint =new Point(this->GetNextX(), this->GetNextY());//setting new cords

		if (world->isFree(nextPoint))
			world->moveOrganism(this, this->GetNextX(), this->GetNextY());//moving organism
		else {
			this->collision(world->findOrg(nextPoint),world);
		}
	}
}


void Animal::collision(Organism* rival, World* world)
{
	Point* rivalPosition = rival->GetPosition();
//	cout << "collison with  " << rival->GetLook() << "in "<< this->nextX << " " << this->nextY << endl;
	if (this->GetLook() != rival->GetLook()) {//checking if it is not the same species
		if (!rival->specialAbilities) {//if rival has special abilty his collision function is used
			if (this->GetStrength() >= rival->GetStrength()) {//if rival has bigger stregth current organims is defeated

				world->killOrganism(rival);
				world->moveOrganism(this, rivalPosition->x, rivalPosition->y);
				commentator->addToText(commentator->lookToString(this->GetLook()) + " killed " + commentator->lookToString(rival->GetLook()) + " in this round ");

			}
			else {
				world->killOrganism(this);//or opposite if current organism has bigger streght
				world->moveOrganism(rival, this->GetPosition()->x, this->GetPosition()->y);
				commentator->addToText(commentator->lookToString(rival->GetLook()) + " killed " + commentator->lookToString(this->GetLook()) + " in this round ");
			}

		}
		else
			rival->collision(this, world);
	}
	else {
		int randomFactors = rand()%100;//if it is the same species two animals are trying to breed
		if (randomFactors < BREED_PROPABILITY) {
			Direction dir = randDir();
			while (!this->isGoodDirection(dir, world, this->GetPosition()))
				dir = randDir();

			this->goInDir(dir, this->GetPosition(), world);
			Point* nextPoint = new Point(this->GetNextX(), this->GetNextY());
			if (world->isFree(nextPoint)) {
				world->addNewAnimal(this->animal, nextPoint);
				commentator->addToText(commentator->lookToString(this->GetLook()) + " was born in this round ");
			}
		}
	}
		
}

Animals Animal::getType() {
	return animal;
}





Animal::~Animal()
{
	delete this;
}
