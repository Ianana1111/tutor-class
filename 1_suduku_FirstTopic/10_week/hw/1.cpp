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