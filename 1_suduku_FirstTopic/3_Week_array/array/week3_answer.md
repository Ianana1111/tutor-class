# 第三節課 questions 解答
## 第一題
```cpp=
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[10001];
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(a<=0)
            arr[i] = a;
        else
            arr[i] = 0;
    }
    for(int i=n-1; i>=0; i--){
        cout << arr[i] << '\n';
    }
    return 0;
}
```
## 第二題
```cpp=
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[1001];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n; i++){
        cout << arr[arr[i]] << '\n';
    }
    return 0;
}
```
## 第三題
```cpp=
#include<iostream>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    int arr[100001] = {0};
    for(int i=0; i<n ;i++){
        cin >> arr[i];
    }
    while(q--){
        int sum = 0;
        int a, b;
        cin >> a >> b;
        for(int i=a-1; i<b; i++){
            sum+=arr[i];
        }
        cout << sum << '\n';
    }
}
```
## 第四題
```cpp=
#include<iostream>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    int arr[101][101];
    for(int i=0; i<n ;i++){
        for(int j=0; j<q; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<q; i++){
        for(int j=0; j<n; j++){
            cout << arr[j][i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
```
## 挑戰題1（第三題的強化版）
:::info
利用前墜和技巧，以下實作方法為，假如今天有一個方陣如下  
1 2 3  
4 5 6  
7 8 9  
我們會記成一新矩陣如下  
1 2 6  
4 9 15  
7 1524  
如此一來，若要計算 (3,2) 到 (3,3)，只需要拿新矩陣中(3,3)的位子減去(3,1),，就會得到24-7=17  
如此可以減少計算時間 （詳細計算時間，之後會跟你說）

關鍵字：前墜和

:::
```cpp=
#include<iostream>
#include<cstring>
using namespace std;

int arr[502][100002];

int main(){
    memset(arr, 0, sizeof(arr));  //初始化，把整個二微陣列都變成0
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int a;
            cin >> a;
            arr[i][j] = arr[i][j-1] + a; //從11開始算，每次計算是，把前面一個數字的值加起來，實作前墜和
        }
    }
    while(m--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        for(int i=x1; i<=x2; i++){
            sum+=(arr[i][y2] - arr[i][y1-1]);  //因為每一排的數字，都會是前墜和，故計算為，一排一排去看，每一排就最後面的值減去最前面-1的值，再全部加起來
        }
        cout << sum << '\n';
    }
}
```
## 挑戰題2
:::info
把所有可能性都考慮過一次，就會覺得輕鬆很多了(?
:::
```cpp=
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x[100001], y[100001], capa[100001]={0}, stay[100001]={0};
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i] >> capa[i];
    }
    int m;
    cin >> m;
    while(m--){
        int xt, yt;
        cin >> xt >> yt;
        int min = 1e+9, rec = 0, tmp_x, tmp_y; 
        for(int i=0; i<n; i++){
            if(capa[i]<=0) continue;
            int tmp = abs(x[i]-xt) + abs(y[i]-yt);
            if(tmp < min){
                min = tmp;
                rec = i;
                tmp_x = x[i];
                tmp_y = y[i];
            }else if(tmp == min){
                if(x[i]<tmp_x || (x[i]==tmp_x && y[i]<tmp_y)){
                    rec = i;
                    tmp_x = x[i];
                    tmp_y = y[i];
                }
            }
        }
        capa[rec]--;
        stay[rec]++;
    }
    for(int i=0; i<n; i++){
        cout << stay[i] << '\n';
    }
    return 0;
}
```