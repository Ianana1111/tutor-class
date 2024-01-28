#include<iostream>
using namespace std;

int i = 10;
int call_function(int n, int m){
    int i = 0;
    return i + n + m;
}

int main(){
    int n, m;
    cin >> n >> m;
    int ans = call_function(n, m);
    cout << ans << '\n';
    cout << i << '\n';
}