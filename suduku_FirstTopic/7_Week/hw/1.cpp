#include <iostream>
using namespace std;

int recursion(int n, int m){
    if(n==0 || m==0)
        return 1;
    return recursion(n-1, m) + recursion(n, m-1);
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << recursion(n, m) << '\n';
}
// 跑7秒