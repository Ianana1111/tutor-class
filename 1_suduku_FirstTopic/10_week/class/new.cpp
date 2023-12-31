#include <bits/stdc++.h>
using namespace std;

char maze[10][10];
int n, m;
void bt(int x, int y){
    // 終止條件
    if(x==n && y==m){
        cout << "-----------------" << '\n'; 
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout << maze[i][j] << ' ';
            }
            cout << '\n';
        }
        return;
    }
    if(maze[x][y+1]=='.' || maze[x][y+1]=='@'){
        maze[x][y+1] = '+';
        bt(x, y+1);
        maze[x][y+1] = '.';
    }
    if(maze[x][y-1]=='.' || maze[x][y-1]=='@'){
        maze[x][y-1] = '+';
        bt(x, y-1);
        maze[x][y-1] = '.';
    }
    if(maze[x+1][y]=='.' || maze[x+1][y]=='@'){
        maze[x+1][y] = '+';
        bt(x+1, y);
        maze[x+1][y] = '.';
    }
    if(maze[x-1][y]=='.' || maze[x-1][y]=='@'){
        maze[x-1][y] = '+';
        bt(x-1, y);
        maze[x-1][y] = '.';
    }
    return;
}

int main(){
    memset(maze, '*', sizeof(maze));
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> maze[i][j];
        }
    }
    maze[1][1] = '+';
    bt(1, 1);
    return 0;
}

// 4 4
// . . . *
// * . * *
// . . . *
// * * . @