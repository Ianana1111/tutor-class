# 第七周_hw解答 pt2
[TOC]

:::warning
下面兩題我上課都會解釋一下
:::
### 第一題
```cpp=
#include <iostream>
using namespace std;
int step=0;
//(n, from, mid, to)
void hanoi(int n, char A, char B, char C){
    if(n == 1){
        //cout << A << " to " << C << '\n';
        step++;
    }
    else{
        hanoi(n-1, A, C, B);
        hanoi(1, A, B, C);
        hanoi(n-1, B, A, C);
    }
}
int main(){
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    cout << step << '\n';
}
```

### 第二題
:::info
可以稍微想一下，要求跨一步或兩步的話有幾種方式，再慢慢往後推看看
:::
```cpp=
#include <iostream>
using namespace std;

int climbing(int n){
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    return climbing(n-1) + climbing(n-2);
}

int main(){
    int n;
    cin >> n;
    int ans = climbing(n);
    cout << ans << '\n';
}
```