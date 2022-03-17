#ifndef WALL_H
#define WALL_H
#include <iostream>
#include "organism.h"

using namespace std;

class wall: public organism
{
public:
    wall();
    wall(int r, int c);
    virtual char type();

    virtual void print();

    virtual void move(organism* grid[MAX][MAX]);

private:

};

#endif // WALL_H
