#include "organism.h"

organism::organism(){
    row = 0;
    col = 0;
    moved = false;
}

organism::organism(int r, int c){
    row = r;
    col = c;
    moved = false;
}

organism::organism(int r, int c, bool m){
    row = r;
    col = c;
    moved = m;
}

char organism::type(){
    return 'o';
}

void organism::print(){
    cout<<"o ";
}

void organism::move_to(organism *grid[MAX][MAX], loc here){
    int r = here.row;
    int c = here.col;
    grid[row][col] = nullptr;
    grid[r][c] = this;
    row = r;
    col = c;
}

loc* organism::find_blank(organism *grid[MAX][MAX], int& index){
    loc* empty_spots = new loc[8];
    loc* walker = empty_spots;
    for(int i=row-1; i<=row+1; i++){
        for(int j=col-1; j<=col+1; j++){
            if(grid[i][j]==nullptr){
                *walker = {i,j};
                walker++;
                index++;
            }
        }
    }
    return empty_spots;
}

void organism::move(organism* grid[MAX][MAX]){
    if(moved==false){
        //find empty spaces
        int index = -1;
        loc* empty_spots = this->find_blank(grid,index);
        //makes move
        if(index>=0){
            loc move_here = empty_spots[getRandom(0,index)];
            this->move_to(grid, move_here);
        }
        moved = true;
    }
}

void organism::unmove(){
    moved = false;
}
