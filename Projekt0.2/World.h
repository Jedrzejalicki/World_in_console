#ifndef WORLD_H
#define WORLD_H
#include"Organism.h"
#include "Point.h"
#include"Direction.h"
#include"Enums.h"
#include"Commentator.h"
#include<iostream>
#include<vector>

class Commentator;
class Organism;
class Animal;
class Human;

class Point;
	using namespace std;
	class World
	{
	private:
		int width;
		int height;
		int numberOfAnimals;
		int numberOfPlants;
		Organism*** world;
		vector<Organism*> org;
		Human* human;
		Commentator* commentator;
		void initializeAnimals();
		void initializePlants();


	public:

		World(int x, int y, int nOfA, int nOfP);
		void makeTurn();
		void drawWorld();
		Point* drawPoint();
		void addOrganism();
		void moveOrganism(Organism* org, int x, int y);
		int GetWidth();
		int GetHeight();
		int GetNumberOfAnimals();
		int GetNumberOfPlants();
		void placeOrganism(Organism* org);
		int isFree(Point* point);
		Organism* findOrg(Point* point);
		void killOrganism(Organism* org);
		void sortOrg();
		void setHumanDirection(Direction dir);
		void addNewAnimal(Animals animal, Point* point);
		void addNewPlant(Plants plant, Point* point);
		void turnOnHumanSpecialAbility();
		void createAnimal(Animals animal, Point* point, int i);
		void createPlant(Plants plant, Point* point,int i);

		~World();

	};

#endif
