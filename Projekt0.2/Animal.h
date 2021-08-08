#ifndef ANIMAL_H
#define ANIMAL_H
#include "Organism.h"
#include"Direction.h"
#include"Commentator.h"
#include"Enums.h"
#define BREED_PROPABILITY 25
#include<string>

class Commentator;
class World;


class Animal : public Organism {
private:
    bool bred;
    Animals animal;
  
public:
  Commentator* commentator;
    Animal(World& world, Point* position, char look, int strength, int initiative, int age,int range,bool specialAbilities, Animals animal, Commentator* commentator);

    void action(World* world) override;
    void collision(Organism* rival, World* world) override;
    Animals getType();
    virtual ~Animal();
};

#endif