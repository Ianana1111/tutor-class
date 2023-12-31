#include <iostream>
using namespace std;
#define MAX 100 //這個 MAX 可以隨便替換

int call_func(){
    static int x = 0;
    x++;
    return x;
}

int main(){
    int ans = 0;
    for(int i=0; i<100; i++){
        int rec = call_func();
        ans += rec;
        cout << ans << '\n';
    }
    return 0;
}