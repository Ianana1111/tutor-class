#include<iostream>
using namespace std;
int main(){
    int arr[9] = {2000, 1000, 500, 100, 50, 10, 5, 1};
    int input;
    cin >> input;
    int count = 0;
    for(int i=0; i<9; i++){
        count += (input/arr[i]);
        input%=arr[i];
    }
    cout << count << '\n';
}