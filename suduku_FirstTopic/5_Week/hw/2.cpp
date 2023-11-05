#include<iostream>
using namespace std;

void posneg(int array[5][5], int result[2]){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(array[i][j]>0)
                result[1]++;
            else if(array[i][j]<0)
                result[0]++;
        }
    }
}

int main(){
    int i, j;
    int array[5][5];
    int result[2] = {0};
    for(i=0; i<5; i++){
        for(j = 0; j<5; j++){
            cin >> array[i][j];
        }
    } 
    posneg(array, result);
    cout << result[0] << '\n';
    cout << result[1] << '\n';
    return 0;
}