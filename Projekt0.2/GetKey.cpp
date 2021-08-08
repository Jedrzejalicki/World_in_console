#include "GetKey.h"
#include"World.h"
#include<conio.h>

Getter::Getter(World* world) {
    this->world = world;
}
void Getter::passDirection() {
    int i = 0;
       option = _getch();
       switch (option) {
           case 72:
               dir = UP;
               break;
           case 80:
               dir = DOWN;
               break;
           case 77:
               dir = RIGHT;  // key right
               break;
           case 75:
               dir = LEFT;// key left
               break;
           case 0:
               dir = STAY;
               world->turnOnHumanSpecialAbility();
               break;
       }
}


