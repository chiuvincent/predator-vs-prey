#include "shark.h"

shark::shark():organism(){
    steps = 0;
    starve = 0;
}

shark::shark(int r, int c):organism(r,c){
    steps = 0;
    starve = 0;
}

shark::shark(int r, int c, bool m):organism(r,c,m){
    steps = 0;
    starve = 0;
}

char shark::type(){
    return 's';
}

void shark::reproduce(organism *grid[MAX][MAX]){
    int index = -1;
    loc* empty_spots = this->find_blank(grid,index);
    if(index>=0){
        loc move_here = empty_spots[getRandom(0,index)];
        int r = move_here.row;
        int c = move_here.col;
        grid[r][c] = new shark(r,c,true);
        steps = 0;
    }
}

void shark::print(){
    char c = 232;
    cout<<c<<" ";
}

void shark::feed(organism *grid[MAX][MAX], loc here){
    int r = here.row;
    int c = here.col;
    grid[row][col] = nullptr;
    grid[r][c] = this;
    row = r;
    col = c;
    starve = 0;
    moved = true;
}

loc* shark::find_prey(organism *grid[MAX][MAX], int &index){
    loc* food = new loc[8];
    loc* walker = food;
    for(int i=row-1; i<=row+1; i++){
        for(int j=col-1; j<=col+1; j++){
            if(grid[i][j]&&grid[i][j]->type()=='f'){
                *walker = {i,j};
                walker++;
                index++;
            }
        }
    }
    return food;
}

void shark::move(organism *grid[MAX][MAX]){
    if(moved==false){
        steps++;
        //hunt
        int index = -1;
        loc* food = this->find_prey(grid,index);
        if(index>=0){
            loc eat_this = food[getRandom(0,index)];
            this->feed(grid,eat_this);
        }
        //regular movement
        else{
            organism::move(grid);
            starve++;
        }
    }
    if(starve>=3){
        grid[row][col] = nullptr;
    }
    if(steps>=8){
        this->reproduce(grid);
    }
}
