#include <iostream>
#include <string.h>
using namespace std;
char maze[102][102];
int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};
int count = 0;
void find(int xnow, int ynow){
    if(xnow == 8 && ynow == 10){
        count++;
        return;
    }
    for(int i=0; i<4; i++){
        if(maze[xnow + x[i]][ynow + y[i]]=='.' || maze[xnow + x[i]][ynow + y[i]]=='G'){
            maze[xnow + x[i]][ynow + y[i]] = '#';
            find(xnow + x[i], ynow + y[i]);
            maze[xnow + x[i]][ynow + y[i]] = '.';
        }
    }
    return;
}


int main(){
    memset(maze, '#', sizeof(maze));
    for(int i=1; i<=8; i++){
        for(int j=1; j<=10; j++){
            cin >> maze[i][j];
        }
    }
    maze[1][1] = '#';
    find(1, 1);
    cout << count << '\n';
}
// s . . # # # # # # #
// # # . . # # # # # #
// # # . # # # . . . #
// # . . . # # . . . #
// . . # . . # . # . #
// # . # . # # . # . #
// # # # . . . . # . #
// # # # # # # . . . G