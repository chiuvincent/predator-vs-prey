#ifndef LOC_H
#define LOC_H
#include <iostream>

using namespace std;

struct loc{
    int row;
    int col;

    friend ostream& operator <<(ostream& outs, const loc& stuff);
};

#endif // LOC_H
