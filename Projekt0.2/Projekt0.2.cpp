// Projekt0.2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include"Organism.h"
#include"World.h"
#include"Direction.h"
#include"GetKey.h"
#include<time.h>
#include <conio.h>

int main()
{
    srand(time(NULL));
    int x = 0;
    int y = 0;
    int numOfAm = 0;
    int numOfPl = 0;

    int option = 0;
    int quit = 0;
    Direction dir;

    cout << "----------------------------------Jumanji----------------------------------- "<<endl;
    cout << "Height(mininmum 10): ";
    cin >> y;
    while (y < 10) {
        cin >> y;
        cout << "incorrect number" << endl;
    }
    cout << endl;
    cout << "Width(mininmum 10): ";
    cin >> x;
    while (x < 10) {
        cin >> x;
        cout << "incorrect number" << endl;
    }
    cout << "Number of animals(" << 0 << " - " << x * y / 5 << " )";
    cin >> numOfAm;
    while (numOfAm > x * y / 5) {
        cin >> numOfAm;
        cout << "incorrect number" << endl;
    }
    cout << endl;
    cout << "Number of plants(" << 0 << " - " << x * y / 4 << " )";
    cin >> numOfPl;
    while (numOfPl > x * y / 4) {
        cin >> numOfPl;
        cout << "incorrect number" << endl;
    }
    cout << endl;
    cout << "Loading: " << endl;
    cout << "--------------------------------------------------------" << endl;
    World world(x, y, numOfAm, numOfPl);
    Getter* getter = new Getter(&world);
    world.addOrganism();
    world.drawWorld();
    cout << "H" << world.GetHeight() << endl;
    cout << "W" << world.GetWidth() << endl;
    getter->passDirection();

    while (!quit){
       
            getter->passDirection();
            world.setHumanDirection(getter->dir);
            world.makeTurn();

            getter->passDirection();
            
        
    }

}
