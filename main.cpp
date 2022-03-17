/*
 * Author: Vincent Chiu
 * Project: Predator vs Prey
 * Purpose: Simulate a predator vs prey situation using inheritance
 * and virtual functions, predators must eat prey to survive, and
 * creatures reproduce after certain amount of steps
 */
#include <iostream>
#include <ctime>
#include "world.h"
#include "organism.h"
using namespace std;

int main()
{
    srand(time(0));
    world w;
    w.print();
    int count = 0;
    char c;
    do{
        count++;
        cin>>c;
        w.step();
        w.print();
        cout<<"generation "<<count<<endl;
    }while(c!='x');
    return 0;
}
