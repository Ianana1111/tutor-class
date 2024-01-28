# 第十周解答
[toc]

### 第一題
```cpp=
#include <iostream>
using namespace std;
int arr[10][10], flag = 0;

bool check(int now, int pos){
    int x = now/9, y = now%9;
    for(int i=0; i<9; i++){
        if(arr[x][i] == pos) 
            return false;
        if(arr[i][y] == pos)
            return false;
    }
    for(int i = 3*(x/3); i<3*(x/3)+3; i++){
        for(int j = 3*(y/3); j<3*(y/3)+3; j++)
            if(arr[i][j] == pos)
                return false;
    }
    return true;
}

void sodu(int now){
    if(now==81){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << arr[i][j] << " \n"[j==8];
            }
        }
        flag = 1;
        return;
    }
    int x = now/9, y = now%9;
    if(arr[x][y] != 0)
        sodu(now + 1);
    for(int i=1; i<=9; i++){
        if(flag == 1)
            break;
        if(check(now, i)){
            arr[x][y] = i;
            sodu(now+1);
        }
        arr[x][y] = 0;
    }
    return;
}

int main(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> arr[i][j];
        }
    }
    sodu(0);
    return 0;
}
```
### 第二題
```cpp=
#include <iostream>
using namespace std;
int n, ans=0, put[100], visited[3][100];
void search(int now){
    if(now == n) ans++; 
    else for(int i=0; i<n; i++){
        if(!visited[0][i] && !visited[1][now+i] && !visited[2][now-i+n]){
        
            put[now] = i; 
            visited[0][i] = visited[1][now+i] = visited[2][now-i+n] = 1;
            search(now+1);
            visited[0][i] = visited[1][now+i] = visited[2][now-i+n] = 0; //改回來
        }
    }
}
int main(){
    cin >> n;
    search(0);
    cout << ans << '\n';
}
```

### 第三題
```cpp=
#include <iostream>
#include <string.h>
using namespace std;
char maze[102][102];
// 換成用陣紀錄四個方位，等等就可以直接用for迴圈去嘗試所有可能
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
```