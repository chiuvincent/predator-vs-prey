#ifndef FISH_H
#define FISH_H
#include "organism.h"

class fish: public organism
{
public:
    fish();
    fish(int r, int c);
    fish(int r, int c, bool m);
    virtual char type();

    void reproduce(organism *grid[MAX][MAX]);

    virtual void print();

    virtual void move(organism* grid[MAX][MAX]);


private:
    int steps;
};

#endif // FISH_H
