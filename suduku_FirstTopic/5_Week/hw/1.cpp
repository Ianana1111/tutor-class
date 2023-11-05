#include<iostream>
using namespace std;

int max(int array[5][5]){
    int maxx = -1;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(array[i][j]>maxx)
                maxx = array[i][j];
        }
    }
    return maxx;
}

int main(){
    int i, j;
    int array[5][5];
    for(i=0; i<5; i++){
        for(j = 0; j<5; j++){
            cin >> array[i][j];
        }
    } 
    cout << max(array) << '\n';
}