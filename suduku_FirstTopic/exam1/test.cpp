#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    int arr[102][102];
    int ans[102][102];
    cin >> n >> m;
    memset(arr, 0, sizeof(arr));
    //輸入
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    //處理
    for(int i=0; i<n; i++){ // x軸座標
        for(int j=0; j<m; j++){ // y軸座標
            int count = 0;
            for(int pi = 0; pi<3; pi++){  // x軸要跑的量
                for(int pj = 0; pj<3; pj++){ // y軸要跑的量
                    count += arr[i+pi][j+pj];
                }
            }
            ans[i+1][j+1] = count;
        }
    }
    //輸出
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << ans[i][j]-1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}