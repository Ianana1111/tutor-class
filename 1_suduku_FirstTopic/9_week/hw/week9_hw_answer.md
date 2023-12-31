# 第九周解答

[TOC]

### 第一題
```cpp=
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[101];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int maxx = -1;
    for(int i=1; i<n; i++){
        maxx = max(maxx, arr[i]- arr[i-1]);
    }
    cout << maxx << '\n';
}
```

### 第二題
```cpp=
#include <iostream>
using namespace std;

int maxx = -1;

bool avali[102] = {false};
void find(int arr[102][2002], int rec_pos[102], int n, int num, int rec){
    // 當全部avali都變成true後，就做一次比較
    if(n == num){
        maxx = max(maxx, rec);
        return;
    }
    // backtracking，上課會講
    for(int i=1; i<=n; i++){
        if(!avali[i]){
            int count = 0, tmp[102] = {0};
            avali[i] = true;
            for(int j=0; j<rec_pos[i]; j++){
                if(avali[arr[i][j]] == false)
                    tmp[count++] = arr[i][j];
                avali[arr[i][j]] = true;
            }
            find(arr, rec_pos, n, num + 1 + count, rec+1);
            avali[i] = false;
            for(int j=0; j<count; j++){
                avali[tmp[j]] = false;
            }
        }
    }
    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    int arr[102][2002] = {{0}}; // 用來記錄那些寶石們互相相衝
    int rec_pos[102] = {0}; // 用來記錄寶石們相衝個數
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        arr[a][rec_pos[a]++] = b; 
        arr[b][rec_pos[b]++] = a;
    }
    find(arr, rec_pos, n, 0, 0);
    cout << maxx << '\n';
}
```

### 第三題
```cpp=
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
```

### 第四題
```cpp=
#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i = n; i <= m; i++){
        int arr[7] = {0}, num = i, count = 0;
        int div = 9*9*9*9;
        while(num > 0 || div>0){
            if(num < div && count == 0){
                div/=9;
                continue;
            }
            arr[count++] = (num/div);
            num %= div;
            div/=9;
        }
        // 檢查奇數
        bool flag = false;
        for(int j=0; j<count; j++){
            if(arr[j]%2 == 0){
                flag = true;
                break;
            }
        }
        // 檢查回文
        int mid = count/2, l = 0, r = count-1;
        // l 表示從arr最左邊開始往右， r表示從arr最右邊開始往左，每次就去比較數字一不一樣，若不一樣就直接跳出
        while(l <= r){
            if(arr[l]!=arr[r]){
                flag = true;
                break;
            }
            l++;
            r--;
        }
        if(!flag)
            ans++;
    }
    cout << ans << '\n';
}
```