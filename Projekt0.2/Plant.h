#pragma once
#include "Organism.h"
#include"Direction.h"
#include"Enums.h"
#include"Commentator.h"
#include<string>

class World;
class Commentator;


class Plant :
    public Organism
{
private:
    int sowPropability;
    Plants plant;
    bool spreading;

public:
    Commentator* commentator;
    Plant(World& world, Point* position, char look, int strength, int age, int range, bool specialAbilities, Plants plant,int sowPropability, Commentator* commentator);
    void action(World* world) override;
    void collision(Organism* rival, World* world) override;
    bool spreadWithSucces();
    void setSpreading(bool x);
    ~Plant();
};

