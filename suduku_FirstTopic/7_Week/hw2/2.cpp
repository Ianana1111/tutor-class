#include <iostream>
using namespace std;

int climbing(int n){
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    return climbing(n-1) + climbing(n-2);
}

int main(){
    int n;
    cin >> n;
    int ans = climbing(n);
    cout << ans << '\n';
}