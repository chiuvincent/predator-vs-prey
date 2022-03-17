#include "world.h"

world::world(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            grid[i][j] = nullptr;
        }
    }
    //create wall
    for(int i=0; i<MAX; i++){
        grid[0][i] = new wall(0,i);
        grid[i][0] = new wall(i,0);
        grid[MAX-1][i] = new wall(MAX-1,i);
        grid[i][MAX-1] = new wall(i,MAX-1);
    }
    //100 preys
    for(int p=0; p<100; p++){
        int r;
        int c;
        do{
            r = getRandom(1,MAX-2);
            c = getRandom(1,MAX-2);
        }while(grid[r][c]!=nullptr);
        grid[r][c] = new fish(r,c);
    }
    //5 predators
    for(int p=0; p<5; p++){
        int r;
        int c;
        do{
            r = getRandom(1,MAX-2);
            c = getRandom(1,MAX-2);
        }while(grid[r][c]!=nullptr);
        grid[r][c] = new shark(r,c);
    }
}

void world::step(){
    //predators move first
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(grid[i][j]&&grid[i][j]->type()=='s'){
                grid[i][j]->move(grid);
            }
        }
    }
    //other organisms move second
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(grid[i][j]&&grid[i][j]->type()!='s'){
                grid[i][j]->move(grid);
            }
        }
    }
    //unmove all organism
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(grid[i][j]!=nullptr){
                grid[i][j]->unmove();
            }
        }
    }
}

void world::print(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(grid[i][j]==nullptr){
                cout<<"_ ";
            }
            else{
                grid[i][j]->print();
            }
        }
        cout<<endl;
    }
    cout<<"\n\n";
}
