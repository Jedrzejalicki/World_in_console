#include "Human.h"


Human::Human(World& world, Point* position, int age, Commentator* commentator)
	:Animal(world, position, HUMAN_LOOK, HUMAN_STRENGTH, HUMAN_INITIATIVE, age, HUMAN_RANGE, false,HUMAN,  commentator){
	this->coolDown = HUMAN_COOL_DOWN;
	this->timeSpecialAbilitieLast = HUMANS_HOW_MANY_LAST;
	this->specialAbilityGood = true;
}

void Human::setDirection(Direction dir) {

	this->direction = dir;
}


void Human::action(World* world) {
	if (!this->specialAbilities) {
		if (this->isGoodDirection(this->direction, world, this->GetPosition())) {
			this->goInDir(this->direction, this->GetPosition(), world);
			Point* nextPoint = new Point(GetNextX(), GetNextY());
			if (world->isFree(nextPoint))
				world->moveOrganism(this, GetNextX(), GetNextY());
			else {
				this->collision(world->findOrg(nextPoint), world);
			}
		}
		else {
			//		cout << "wrong Direction" << endl;
		}
	}
	else {
			if (this->isGoodDirection(this->direction, world, this->GetPosition())) {
				this->goInDir(this->direction, this->GetPosition(), world);
				Point* nextPoint = new Point(GetNextX(), GetNextY());
				if (world->isFree(nextPoint))
					world->moveOrganism(this, GetNextX(), GetNextY());
				else {
					this->collision(world->findOrg(nextPoint), world);
				}
			}
			else {
				//		cout << "wrong Direction" << endl;
			}
		




		if (this->isGoodDirection(UP, world, this->GetPosition())) {
			this->goInDir(UP, this->GetPosition(), world);
			Point* point = new Point(this->GetNextX(), this->GetNextY());
			if (!world->isFree(point)) {
				if (!world->findOrg(point)->isAnimal())
					world->killOrganism(world->findOrg(point));
			}
		}
		if (this->isGoodDirection(DOWN, world, this->GetPosition())) {
			this->goInDir(DOWN, this->GetPosition(), world);
			Point* point = new Point(this->GetNextX(), this->GetNextY());
			if (!world->isFree(point)) {
				if (!world->findOrg(point)->isAnimal())
					world->killOrganism(world->findOrg(point));
			}
		}
		if (this->isGoodDirection(LEFT, world, this->GetPosition())) {
			this->goInDir(LEFT, this->GetPosition(), world);
			Point* point = new Point(this->GetNextX(), this->GetNextY());
			if (!world->isFree(point)) {
				if (!world->findOrg(point)->isAnimal())
					world->killOrganism(world->findOrg(point));
			}
		}
		if (this->isGoodDirection(RIGHT, world, this->GetPosition())) {
			this->goInDir(RIGHT, this->GetPosition(), world);
			Point* point = new Point(this->GetNextX(), this->GetNextY());
			if (!world->isFree(point)) {
				if (!world->findOrg(point)->isAnimal())
					world->killOrganism(world->findOrg(point));
			}
		}

	}
		
}

void Human::changeStateOfSpecialAbility(bool x) {
	this->specialAbilities = x;
}


void Human::addRound() {
	this->round += 1;
}

int Human::GetCoolDown() {
	return coolDown;
}

int Human::GetRound() {
	return round;
}

int Human::GetTimeSpecialAbilityLast() {
	return timeSpecialAbilitieLast;
}


void Human::restartCounter() {
	this->round = 0;
}

void Human::canSpecialAbilityBeOn(bool x) {
	this->specialAbilityGood = x;
}


bool Human::isSpecialAbilityGood() {
	return specialAbilityGood;
}