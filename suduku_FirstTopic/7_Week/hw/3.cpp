#include<iostream>
using namespace std;

int rec[10000][10000];
void dp(){
    for(int i=0; i<1001; i++){
        rec[0][i] = 1;
        rec[i][0] = 1;
    }    
    for(int i=1; i<1001; i++){
        for(int j=1; j<1001; j++){
            rec[i][j] = rec[i-1][j] + rec[i][j-1];
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    dp();
    cout << rec[n][m] << '\n';
}