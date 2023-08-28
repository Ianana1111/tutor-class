#include<iostream>

using namespace std;

bool check(int arr[9][9], int pos, int rep){
    int x = pos/9, y = pos%9;
    //檢查行
    for(int i=0; i<9; i++){
        if(arr[x][i]==rep) return false;
    }
    //檢查列
    for(int i=0; i<9; i++){
        if(arr[i][y]==rep) return false;
    }
    //檢查正方形
    x = (x/3)*3, y = (y/3)*3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr[x+i][y+j]==rep) return false;
        }
    }
    return true;
}

void complete(int arr[9][9], int pos){
    if(pos==81){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << arr[i][j] << " \n"[j==8];
            }
        }
        return;
    }
    int x=pos/9, y=pos%9;
    if(arr[x][y]!=0) complete(arr, pos+1);
    else{
        for(int i=1; i<=9; i++){
            if(check(arr, pos, i)){
                arr[x][y] = i;
                complete(arr, pos+1);
            }
            arr[x][y]=0;
        }
    }
    return;
}

int main(){
    int arr[9][9];
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> arr[i][j];
        }
    }
    cout << '\n';
    complete(arr, 0);
    return 0;
}
