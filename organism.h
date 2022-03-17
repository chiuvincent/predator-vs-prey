#ifndef ORGANISM_H
#define ORGANISM_H
#include <iostream>
#include "constants.h"
#include "loc.h"

using namespace std;

class organism
{
public:
    organism();
    organism(int r, int c);
    organism(int r, int c, bool m);
    virtual char type();

    virtual void print();

    void move_to(organism* grid[MAX][MAX], loc here);
    loc* find_blank(organism* grid[MAX][MAX], int &index);

    virtual void move(organism* grid[MAX][MAX]);
    void unmove();

protected:
    int row;
    int col;
    bool moved;
};

#endif // ORGANISM_H
