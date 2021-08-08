#include "Sosnowsky_hogweed.h"
Sosnowsky_hogweed::Sosnowsky_hogweed(World& world, Point* position, int age, Commentator* commentator) :
	Plant(world, position, SOSNOWSKY_HOGWEED_LOOK, SOSNOWSKY_HOGWEED_STRENGTH, age, NULL, true, BELLADONA, SOSNOWSKY_HOGWEED_SOW_PROPABILITY, commentator) {
}


void Sosnowsky_hogweed::action(World* world) {
	Plant::action(world);

	if (this->isGoodDirection(UP, world, this->GetPosition())) {
		this->goInDir(UP, this->GetPosition(), world);
		Point* point = new Point(this->GetNextX(), this->GetNextY());
		if (!world->isFree(point)) {
			if(!world->findOrg(point)->isAnimal())
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


void Sosnowsky_hogweed::collision(Organism* rival, World* world) {
	world->killOrganism(this);
	world->killOrganism(rival);
}