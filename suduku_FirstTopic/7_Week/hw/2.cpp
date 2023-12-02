#include <iostream>
using namespace std;

int mem[10000][10000];
int visit[10000][10000];
int recursion(int n, int m){
    if(n==0 || m==0)
        return 1;
    if(visit[n][m])
        return mem[n][m];
    mem[n][m] = recursion(n-1, m) + recursion(n, m-1);
    visit[n][m] = 1;
    return mem[n][m];
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << recursion(n, m) << '\n';
}

// 0.多 不知道多少