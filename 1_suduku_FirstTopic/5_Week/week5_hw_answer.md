# 第五節課解答
### 第一題
```cpp=
#include<iostream>
using namespace std;

int max(int array[5][5]){
    int maxx = -1; // 用maxx去找最大值
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(array[i][j]>maxx) // 若現在走到的數字比maxx大，那就讓maxx 變成現在走到的
                maxx = array[i][j];
        }
    }
    return maxx;
}

int main(){
    int i, j;
    int array[5][5];
    for(i=0; i<5; i++){
        for(j = 0; j<5; j++){
            cin >> array[i][j];
        }
    } 
    cout << max(array) << '\n';
}
```
### 第二題
```cpp=
#include<iostream>
using namespace std;

void posneg(int array[5][2], int result[2]){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(array[i][j]>0)
                result[1]++;  // result[1] 用來存數字大於零的個數
            else if(array[i][j]<0)
                result[0]++; // result[0] 用來存數字小於零的個數
        }
    }
}

int main(){
    int i, j;
    int array[5][5];
    int result[2] = {0};
    for(i=0; i<5; i++){
        for(j = 0; j<5; j++){
            cin >> array[i][j];
        }
    } 
    posneg(array, result); // 進入function
    cout << result[0] << '\n';
    cout << result[1] << '\n';
    return 0;
}
```
:::info
接下來這兩題，實際寫的code都看起來蠻簡單，但其實需要一些思考歐，你只要懂遞迴在幹嘛，應該就沒問題了
:::
### 第三題
#### 留到下次寫！

```cpp=
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
```
### 第四題
```cpp=
#include <iostream>
using namespace std;

int recursion(int n){
    if(n==1)
        return 1;
    return n*recursion(n-1);
}

int main(){
    int n;
    cin >> n;
    cout << recursion(n) << '\n';
}
```
