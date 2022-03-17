#include "fish.h"

fish::fish():organism(){
    steps = 0;
}

fish::fish(int r, int c):organism(r,c){
    steps = 0;
}

fish::fish(int r, int c, bool m):organism(r,c,m){
    steps = 0;
}

char fish::type(){
    return 'f';
}

void fish::reproduce(organism *grid[MAX][MAX]){
    int index = -1;
    loc* empty_spots = this->find_blank(grid,index);
    if(index>=0){
        loc move_here = empty_spots[getRandom(0,index)];
        int r = move_here.row;
        int c = move_here.col;
        grid[r][c] = new fish(r,c,true);
        steps = 0;
    }
}

void fish::print(){
    char c = 248;
    cout<<c<<" ";
}

void fish::move(organism* grid[MAX][MAX]){
    if(moved==false){
        steps++;
        organism::move(grid);
    }
    if(steps>=3){
        this->reproduce(grid);
    }
}
