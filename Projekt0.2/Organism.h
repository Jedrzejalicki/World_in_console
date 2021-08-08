#pragma once
#include"World.h"
#include "Point.h"
#include"Direction.h"


class World;
class Point;


class Organism
{
private:
	int strength;
	int initiative;
	bool alive = 0;
	Point* position;
	char look;
	int age;
	int nextX;
	int nextY;
	int range;
	bool animal;
protected:
	World& world;

public:
	bool specialAbilities;

	Organism(World& world, Point* position, char look, int strength, int initiative, int age,int range, bool specialAbilities, bool animal);
	int GetStrength();
	int GetInitiative();
	Point* GetPosition();
	int GetNextY();
	int GetNextX();
	void SetNextY(int y);
	void SetNextX(int x);
	void SetPosition(int x, int y);
	void addToStrength(int x);
	char GetLook();
	bool isAlive();
	void setAlivness(Organism* org);
	int GetAge();
	int GetRange();
	void addAge();
	bool isGoodDirection(Direction dir, World* world, Point* point);
	char draw();
	bool isAnimal();
	

	virtual void action(World* world) = 0;
	virtual void collision(Organism* rival, World* world) = 0;
	void goInDir(Direction dir, Point* point, World* world);
	~Organism();


};

