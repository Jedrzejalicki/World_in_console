#include"World.h"
#include"Animal.h"
#include"Wolf.h"
#include"Sheep.h"
#include"Fox.h"
#include"Antelope.h"
#include"Turtle.h"
#include"Sow_thistle.h"
#include"Belladonna.h"
#include"Grass.h"
#include"Human.h"
#include"Guarana.h"
#include"Sosnowsky_hogweed.h"
#include"initializeOrganisms.h"
#include <algorithm>
#include <tuple>
#include<stdlib.h>
World::World(int x, int y, int nOfA,int nOfP) {//Konstruktor œwiata
    this->height = y;
    this->width = x;
    this->numberOfAnimals = nOfA;
    this->numberOfPlants = nOfP;
    this->world = new Organism** [height];
    for (int i = 0; i < height; ++i)
        world[i] = new Organism*[width];


    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            world[i][j] = NULL;
        }
    }

    this->commentator = new Commentator;
}


void World::drawWorld() {

    cout << "----------------------------------Jumanji----------------------------------- " << endl;//konsoloa
    cout << "-------------------------------Jedrzej Alicki 184287-------------------------" << endl;
    cout << "  ";
    for (int i = 0; i < width; i++)
        cout << (char)(65 + i)<<"  ";//Upper part of world
    cout << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height; j++) {
            cout << i;//left part of world
            break;
        }
        for (int j = 0; j < width; j++) {
            if (world[i][j] == NULL)
                cout << " * ";//world
            else
                cout <<" "<< world[i][j]->GetLook()<<" ";
        }
        for (int j = 0; j < height; j++) {
            cout << i;//right part of world
            break;
        }
        cout << endl;

    }
    cout << "  ";
    for (int i = 0; i < width; i++)
        cout << (char)(65 + i) << "  ";
    cout << endl;//lower part of world
}


void World::placeOrganism(Organism* org) {
    Point* position = org->GetPosition();//setting pointer in 2D array to from NULL to specific organism
    world[position->x][position->y] = org;
}


void World::initializeAnimals() {
    for (int i = 0; i < numberOfAnimals; i++) {
        createAnimal(drawAnimalType(), drawPoint(), i + 1);//Making animals on begginig of the game
    }

  


}


void World::initializePlants() {
    for (int i = 0; i < numberOfPlants; i++) 
        createPlant(drawPlantType(), drawPoint(), i+1+numberOfAnimals);//making plants on begginig of the game
}


void World::addOrganism() {
    Point* point = new Point(0, 0);
    this->human = new Human(*this,point,10, this->commentator);//creating human
    

  
      /* this->org.push_back(new Sheep(*this, drawPoint(this),10));
    this->org.push_back(new Sheep(*this, drawPoint(this), 10));
    this->org.push_back(new Fox(*this, drawPoint(this), 10));
    this->org.push_back(new Wolf(*this, drawPoint(this), 10));
    this->org.push_back(new Turtle(*this, drawPoint(this), 10));
    this->org.push_back(new Sow_thistle(*this, drawPoint(this), 10));
    this->org.push_back(new Guarana(*this, drawPoint(this), 10));
    this->org.push_back(new Belladonna(*this, drawPoint(this), 10));
    this->org.push_back(new Sosnowsky_hogweed(*this, drawPoint(this), 10));*/
    cout << "numoOfAnim " << numberOfAnimals << endl;
    this->org.push_back(human);//pushing human to vector and placing him on map
    this->placeOrganism(human);
    initializeAnimals();
    initializePlants();

  
   
   



   /* for (int i = numberOfAnimals + 1; i < numberOfPlants+numberOfAnimals; i++)
        this->placeOrganism(this->org[i]);*/


}




void World::createAnimal(Animals animal, Point* point,int i) {
    //pushing new Animals to vector and placing them on map, animaltype is drawn 
    switch (animal) {
    case WOLF:
        this->org.push_back(new Wolf(*this, point, 0, this->commentator));
        this->placeOrganism(this->org[i]);
        break;
    case SHEEP:
        this->org.push_back(new Sheep(*this, point, 0, this->commentator));
        this->placeOrganism(this->org[i]);
        break;
    case FOX:
        this->org.push_back(new Fox(*this, point, 0, this->commentator));
        this->placeOrganism(this->org[i]);
        break;
    case TURTLE:
        this->org.push_back(new Turtle(*this, point, 0, this->commentator));
        this->placeOrganism(this->org[i]);
        break;
    case ANTELOPE:
        this->org.push_back(new Antelope(*this, point, 0, this->commentator));
        this->placeOrganism(this->org[i]);
        break;
  

    }
}



void World::createPlant(Plants plant, Point* point, int i) {
    //pushing new Plants to vector and placing them on map, planttype is drawn 
    switch (plant) {
    case GRASS:
        this->org.push_back(new Grass(*this, point, 0,this->commentator));
        this->placeOrganism(this->org[i]);
        break;
    case SOW_THISTLE:
        this->org.push_back(new Sow_thistle(*this, point, 0, this->commentator));
        this->placeOrganism(this->org[i]);
        break;
    case GUARANA:
        this->org.push_back(new Guarana(*this, point, 0, this->commentator));
        this->placeOrganism(this->org[i]);
        break;
    case BELLADONA:
        this->org.push_back(new Belladonna(*this, point, 0, this->commentator));
        this->placeOrganism(this->org[i]);
        break;
    case SOSNOWSKY_HOGWEED:
        this->org.push_back(new Sosnowsky_hogweed(*this, point, 0, this->commentator));
        this->placeOrganism(this->org[i]);
        break;

    }
}





void World::addNewAnimal(Animals animal, Point* point) {
    //function that is called when two animals are making baby, same rule as higher, without tracking current number in vector
    //sorry for two simmilar fucntion
    switch (animal) {
    case WOLF:
        this->org.push_back(new Wolf(*this, point, 0, this->commentator));
        break;
    case SHEEP:
        this->org.push_back(new Sheep(*this, point, 0, this->commentator));
        break;
    case FOX:
        this->org.push_back(new Fox(*this, point, 0, this->commentator));
    case TURTLE:
        this->org.push_back(new Turtle(*this, point, 0, this->commentator));
        break;
    case ANTELOPE:
        this->org.push_back(new Antelope(*this, point, 0, this->commentator));
        break;

    }
    
        this->placeOrganism(this->org[this->org.size() - 1]);

}


void World::addNewPlant(Plants plant, Point* point) {
    //same as addNewAnimal();
    switch (plant) {
    case GRASS:
        this->org.push_back(new Grass(*this, point, 0, this->commentator));
        break;
    case SOW_THISTLE:
        this->org.push_back(new Sow_thistle(*this, point, 0, this->commentator));
        break;
    case GUARANA:
        this->org.push_back(new Guarana(*this, point, 0, this->commentator));
        break;
    case BELLADONA:
        this->org.push_back(new Belladonna(*this, point, 0, this->commentator));
        break;
    case SOSNOWSKY_HOGWEED:
        this->org.push_back(new Sosnowsky_hogweed(*this, point, 0, this->commentator));
        break;

    }

        this->placeOrganism(this->org[this->org.size() - 1]);

}


void World::setHumanDirection(Direction dir) {
    this->human->setDirection(dir);
}


void World::moveOrganism(Organism* org,int x,   int y)
{ 
    Point* position = org->GetPosition();
    world[position->x][position->y] = NULL;
    world[x][y] = org;
    org->SetPosition(x, y);
    //transfering organism and setting his position, previous cell is NULL
}


Point* World::drawPoint() {
    Point* point = new Point;
    point->x = rand() % this->GetHeight();
    point->y = rand() % this->GetWidth();

    while (world[point->x][point->y]!=NULL) {
        point->x = rand()% (this->GetHeight()+1);
        point->y = rand()% (this->GetWidth()+1);
    }

    return point;
}

void World::makeTurn() {
    sortOrg();
    // making turn, callin action functions for each organism,
   

    for (int i = 0; i < this->org.size(); i++) {
        if (org[i]->isAlive()&& org[i]->GetAge()!=0) {
            system("CLS");

            org[i]->action(this);
              this->drawWorld();
            // cout << org[i]->GetLook() << " is movinge as " << i + 1 << endl;
        }

    }
    commentator->commentRound();//commentator is outputting everything he gathered in round

    for (int i = 0; i < this->org.size(); i++)
        org[i]->addAge();//adding age to organismsm each round

    //tracking human special ability, turning it off after 5 rounds,
   //and givig possibility to turn it on again after 5 rounds

    if (human->isAlive()) {
        if (human->specialAbilities) {
            human->addRound();
            human->canSpecialAbilityBeOn(false);
            if (human->GetRound() >= human->GetTimeSpecialAbilityLast()) {
                human->changeStateOfSpecialAbility(false);
                commentator->addToText("Purification has ended in this round");
                human->restartCounter();
                human->canSpecialAbilityBeOn(false);
            }
        }
        else{
            human->addRound();
            if (human->GetRound() >= 5) {
                human->canSpecialAbilityBeOn(true);
            }
            else
                human->canSpecialAbilityBeOn(false);
        }
    }


  
}

World::~World() {
    for (int i = 0; i < height; ++i)
        delete world[i];

    delete[] world;
}

void World::turnOnHumanSpecialAbility() {
    if (human->isSpecialAbilityGood()) {
        human->restartCounter();
        human->specialAbilities = true;
        commentator->addToText("Human is using purification, be aware all pathetic organisms");
        
    }
}

int World::GetHeight() {
    return height-1;
}


int World::GetWidth() {
    return width-1;
}


int World::isFree(Point* point) {//checking if cell is free, in some cases it is giving stack overflow error

    if (world[point->x][point->y] != NULL)
        return 0;
    else return 1;
}


Organism* World::findOrg(Point* point)
{
    return world[point->x][point->y];
}


void World::killOrganism(Organism* org) {
    world[org->GetPosition()->x][ org->GetPosition()->y] = NULL;
    org->setAlivness(org);
}

int World::GetNumberOfAnimals() {
    return numberOfAnimals;
}

int World::GetNumberOfPlants() {
    return numberOfPlants;
}

void World::sortOrg()
{//sorting vector by its initiative, in case of tie age has upperhand
    sort(org.begin(), org.end(), [](Organism* org1, Organism* org2) {
            int init1 = org1->GetInitiative();
            int init2 = org2->GetInitiative();
            int age1 = org1->GetAge();
            int age2 = org2->GetAge();
            return tie(init2, age2) < tie(init1, age1);
        });
}