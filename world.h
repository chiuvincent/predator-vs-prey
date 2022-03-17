#ifndef WORLD_H
#define WORLD_H
#include <iostream>
#include "constants.h"
#include "organism.h"
#include "wall.h"
#include "fish.h"
#include "shark.h"

using namespace std;

class world
{
public:
    world();

    void step();

    void print();

private:
    organism* grid[MAX][MAX];
};

#endif // WORLD_H
