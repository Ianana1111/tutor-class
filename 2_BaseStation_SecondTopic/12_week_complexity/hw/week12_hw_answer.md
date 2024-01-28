# 第十二周解答
### 第一題
![image](https://hackmd.io/_uploads/SyeJUGOFT.png)
----
1. **總共5 + 4 + (1+n) + n(1+m) + n + m*n + 2*m*n = "4nm+3n+10"**
2. **O(nm)**

### 第二題
:::info
這題看起來很難，但其實有個細節，只要你有注意到就一定會，希望你找的到:wink:
:::
```cpp=
#include <iostream>
using namespace std;

void selection_sort(double arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx]) 
      	min_idx = j;
      swap(arr[min_idx], arr[i]); 
  }
}

int main() {
    double crank[1001]={0};
    double wheel[1001]={0};
    int n, m; double p;
    cin >> n >> m >> p;
    
    p*=0.01;
    // 處理輸入
    for(int i=0; i<n; i++)
        cin >> crank[i];
    for(int i=0; i<m; i++)
        cin >> wheel[i];

    double record[1001]={0};
    int count = 0;
    // 把每一種配對的節奏記錄起來，稍後第39行會去判斷符不符合題目要求
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            record[count++] = double(wheel[j]/crank[i]);
        }
    }
    
    // 因為變速可以調任和速度，意味著可以直接sort好，再從小到大看可不可以達成題目敘述
    selection_sort(record, count);

    // 若後一個前後齒輪配對所形成的節奏與前一個配對的比例關係大於p，直接輸出要換齒輪，並return 0;
    for(int i=0; i<count-1; i++){
        if((record[i+1]/record[i])-1 > p){
            cout << "Time to change gears!" <<'\n';
            return 0;
        }
    }
    cout << "Ride on!" << '\n';
    return 0;
}
```