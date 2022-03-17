#ifndef SHARK_H
#define SHARK_H
#include "organism.h"

class shark: public organism
{
public:
    shark();
    shark(int r, int c);
    shark(int r, int c, bool m);
    virtual char type();

    void reproduce(organism *grid[MAX][MAX]);

    virtual void print();

    void feed(organism* grid[MAX][MAX], loc here);
    loc* find_prey(organism* grid[MAX][MAX], int &index);

    virtual void move(organism *grid[MAX][MAX]);

private:
    int steps;
    int starve;
};

#endif // SHARK_H
