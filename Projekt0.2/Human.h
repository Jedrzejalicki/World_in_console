#pragma once
#include"Animal.h"
#include"Direction.h"

#define HUMAN_LOOK 'H'
#define HUMAN_NAME "Human"
#define HUMAN_RANGE 1
#define HUMAN_STRENGTH 5
#define HUMAN_INITIATIVE 4
#define HUMAN_COOL_DOWN 6
#define HUMANS_HOW_MANY_LAST 2


class Human : 
	public Animal
{	
	Direction direction;
	int coolDown;
	int timeSpecialAbilitieLast;
	int round;
	bool specialAbilityGood;
public:
	Human(World& world, Point* position, int age, Commentator* commentator);
	void action(World* world) override;
	void setDirection(Direction dir);
	void changeStateOfSpecialAbility(bool x);
	void addRound();
	int GetRound();
	int GetCoolDown();
	int GetTimeSpecialAbilityLast();
	void restartCounter();
	void canSpecialAbilityBeOn(bool x);
	bool isSpecialAbilityGood();

};

