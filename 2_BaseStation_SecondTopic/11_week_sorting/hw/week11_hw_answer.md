# 第十一周解答

[TOC]

### 第一題
```cpp=
#include <iostream>
using namespace std;

void bubble(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1])
                swap(arr[j], arr[j+1]);
        }            
    }
}

int main(){
    int n;
    cin >> n;
    int arr[1001] = {0};
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bubble(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " \n"[i==n-1];
    }
}
```