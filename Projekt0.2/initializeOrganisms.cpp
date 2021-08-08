#include "initializeOrganisms.h"
Animals drawAnimalType() {
	Animals randomAnimal = Animals(rand()%5);
	return randomAnimal;
}

Plants drawPlantType() {
	Plants randomPlant = Plants(rand() % 4);
	return randomPlant;
}