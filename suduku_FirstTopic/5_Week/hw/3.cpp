#include<iostream>
using namespace std;

int loop(int n){
    if(n==0)
        return 0;
    return n*n + loop(n-1);
}

int main(){
    int n;
    cin >> n;
    cout << loop(n) << '\n';

}