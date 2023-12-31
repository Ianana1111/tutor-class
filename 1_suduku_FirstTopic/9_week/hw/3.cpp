#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int rec[102][102];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(i==0 || j==0)   
                rec[i][j] = 1;
            else    
                rec[i][j] += (rec[i-1][j] + rec[i][j-1]);
        }
    cout << rec[n-1][m-1] << '\n';
}