#include "wall.h"

wall::wall():organism(){

}

wall::wall(int r, int c):organism(r,c){

}

char wall::type(){
    return 'w';
}

void wall::print(){
    char c = 254;
    cout<<c<<" ";
}

void wall::move(organism *grid[MAX][MAX]){
    //wall never moves
}
