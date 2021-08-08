#include "Plant.h"

Plant::Plant(World& world, Point* position, char look, int strength, int age, int range, bool specialAbilities,Plants plant,int sowPropability, Commentator* commentator):
		Organism(world,position,look, strength,NULL,age,1,specialAbilities,true){
	this->spreading = false;
	this->commentator = commentator;
	this->plant = plant;
	this->sowPropability = sowPropability;
}


void Plant::action(World* world) {
	int randomFactors = rand() % 100;
	if (randomFactors < sowPropability&&this->spreading == false) {//checking if propability allowed to spread plant and if plant wasnt already spread
																	//Im allowing each plant to spread once because of ruined balance 
		Direction dir = randDir();

		while (!this->isGoodDirection(dir, world, this->GetPosition()))
			dir = randDir();

		this->goInDir(dir, this->GetPosition(), world);//doing simmilar stuff as animal action but instead of moving they are spreading
		Point* nextPoint = new Point(this->GetNextX(), this->GetNextY());
		if (world->isFree(nextPoint)) {
			//			cout << "antelope has fled from this fight";
			world->addNewPlant(this->plant, nextPoint);
			commentator->addToText(commentator->lookToString(this->GetLook()) + " has grown");
			this->spreading = true;
		}
	}
}
void Plant::collision(Organism* rival,World* world) {//collision simmilar to animal's
	Point* rivalPosition = rival->GetPosition();
	//	cout << "collison with  " << rival->GetLook() << "in "<< this->nextX << " " << this->nextY << endl;
		if (this->GetLook() != rival->GetLook()) {
			if (this->GetStrength() >= rival->GetStrength()) {

				world->killOrganism(rival);

				commentator->addToText(commentator->lookToString(this->GetLook()) + " killed " + commentator->lookToString(rival->GetLook()) + " in this round ");
			}
			else {
				world->killOrganism(this);
				world->moveOrganism(rival, this->GetPosition()->x, this->GetPosition()->y);
				commentator->addToText(commentator->lookToString(rival->GetLook()) + " ate " + commentator->lookToString(this->GetLook()) + " in this round ");
			}
		}
}

bool Plant::spreadWithSucces() {
	return spreading;
}

void Plant::setSpreading(bool x) {
	this->spreading = x;
}


Plant::~Plant() {
	delete this;
}