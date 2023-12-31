#include<iostream>
using namespace std;

int call_function(){
    int x = 0;
    x++;
    return x;
}

int main(){
    for(int i=0; i<5; i++){
        int ans = call_function();
        cout << ans << '\n';
    }
}
