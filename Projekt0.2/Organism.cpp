#include "Organism.h"
Organism::Organism(World& world, Point* position, char look, int strength, int initiative,int age,int range, bool specialAbilities, bool aimal)
	: world(world)
{

	this->position = position;
	this->look = look;
	this->alive = true;
	this->strength = strength;
	this->initiative = initiative;
	this->age = age;
	this->specialAbilities =specialAbilities;
	this->range = range;
	this->animal = animal;
}



int Organism::GetInitiative() {
	return initiative;
}


int Organism::GetStrength() {
	return strength;
}


char Organism::draw() {
	return look;
}


Point* Organism::GetPosition() {
	if(this != NULL)
	return position;
}


void Organism::SetPosition(int x, int y) {
	position->x = x;
	position->y = y;
}

char Organism::GetLook() {
	return look;
}

void Organism::action(World* world) {

}

void Organism::collision(Organism* rival,World* world) {

}

int Organism::GetRange() {
	return range;
}

bool Organism::isAlive() {
	return alive;
}


void Organism::setAlivness(Organism* org) {
	org->alive = false;

}


int Organism::GetAge() {
	return age;
}


bool Organism::isGoodDirection(Direction dir, World* world, Point* point) {//checking if direction that organism is going, wont cause any errors
	bool check = 1;

	if (point->x == 0) {
		if (dir == UP) {
			check = 0;
		}
	}

	if (point->y == 0) {
		if (dir == LEFT) {
			check = 0;
		}
	}

	if (point->x == world->GetHeight()) {
		if (dir == DOWN) {
			check = 0;
		}
	}

	if (point->y == world->GetWidth()) {
		if (dir == RIGHT) {
			check = 0;
		}
	}
	if (point->y == 0 && point->x == 0) {
		if (dir == UP || dir == LEFT) {
			check = 0;
		}
	}
	if (point->x == 0 && point->y == world->GetWidth()) {
		if (dir == UP || dir == RIGHT) {
			check = 0;
		}
	}
	if (point->x == world->GetHeight() && point->y == world->GetWidth()) {
		if (dir == DOWN || dir == RIGHT) {
			check = 0;
		}
	}
	if (point->x == world->GetHeight() && point->y == 0) {
		if (dir == DOWN || dir == LEFT) {
			check = 0;
		}
	}
	if (dir == STAY)
		check = 0;
	return check;
}


void Organism::goInDir(Direction dir, Point* point, World* world) {//setting new coordinates depednig on choosen direction
	if (dir == UP) {
		if (nextX - range >= 0)
			nextX = point->x - range;
		else
			nextX = point->x - 1;
		nextY = point->y;
	}
	else if (dir == DOWN) {
		if (nextX + range <= world->GetHeight())
			nextX = point->x + range;
		else
			nextX = point->x + 1;
		nextY = point->y;
	}
	else if (dir == LEFT) {
		if (nextY - range >= 0)
			nextY = point->y - range;
		else
			nextY = point->y - 1;
		nextX = point->x;
	}
	else if (dir == RIGHT) {
		if (nextY + range <= world->GetWidth())
			nextY = point->y + range;
		else
			nextY = point->y + 1;
		nextX = point->x;
	}
}


bool Organism::isAnimal() {
	return animal;
}


int Organism::GetNextX() {
	return nextX;
}


int Organism::GetNextY() {
	return nextY;
}


void Organism::SetNextX(int x) {
	this->nextX = x;
}


void Organism::SetNextY(int y) {
	this->nextY = y;
}



void Organism::addAge() {
	this->age += 1;
}



void Organism::addToStrength(int x) {
	this->strength += x;
}


Organism::~Organism() {

}

