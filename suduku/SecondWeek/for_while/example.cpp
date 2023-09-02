#include<iostream>

using namespace std;
int main(){
    for(int i=0; i<10; i++){
        for(int j=9-i; j>=0; j--){
            cout << ' ';
        }
        for(int j = i; j>=0; j--){
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}
