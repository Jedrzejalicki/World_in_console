#include "Fox.h"
#include "Direction.h"
#include"Organism.h"
#include"Enums.h"

Fox::Fox(World& world, Point* position, int age, Commentator* commentator)
	:Animal(world, position, FOX_LOOK, FOX_STRENGTH, FOX_INITIATIVE, age, FOX_RANGE,false, FOX,  commentator){
	
}


void Fox::action(World* world) {
	Point* point = this->GetPosition();
	Direction dir = randDir();




	while (!this->isGoodDirection(dir, world, point)) {
		dir = randDir();
	}
		if (dir == UP) {
			this->SetNextX(point->x - this->GetRange());
			this->SetNextY(point->y);
		}
		else if (dir == DOWN) {
			this->SetNextX(point->x + this->GetRange());
			this->SetNextY(point->y);
		}
		else if (dir == LEFT) {
			this->SetNextY(point->y - this->GetRange());
			this->SetNextX(point->x);
		}
		else if (dir == RIGHT) {
			this->SetNextY(point->y + this->GetRange());
			this->SetNextX(point->x);
		}

		Point* nextPoint = new Point(this->GetNextX(), this->GetNextY());

		if (world->isFree(nextPoint))
			world->moveOrganism(this, this->GetNextX(), this->GetNextY());
		else if(world->findOrg(nextPoint)->GetStrength() < this->GetStrength()) {
			this->collision(world->findOrg(nextPoint), world);
		}
		else {
			Fox::action(world);
		}
	
}