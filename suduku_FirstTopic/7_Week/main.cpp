#include <iostream>
using namespace std;

int mem[10000] = {0};
bool visit[10000] = {false};
int fabo(int n){
    if(n==1 || n==2) 
        return 1;
    if(visit[n])
        return mem[n];
    mem[n] = fabo(n-1) + fabo(n-2);
    visit[n] = true;
    return mem[n];
}

int main(){
    int n;
    cin >> n;
    cout << fabo(n) << '\n';
}