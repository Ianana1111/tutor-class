# 第八周解答

### 第一題
```cpp=
#include <iostream>
using namespace std;

int main(){
    int rec[10001] = {0};
    for(int i = 10; i < 10001; i++){
        int tmp = i, count = 1;
        int pre = tmp % 10; //先取得個位數字，用來跟之後的數字去比對
        tmp/=10; // 讓數字除10，繼續找新數字的個位數
        while(tmp > 0){
            int now = tmp % 10;  // 取得現在個位數的值
            tmp /= 10;
            if(now > pre){  // 和先前存好的前一個個位數字比對，若<=，代表符合題目要求，若>，則直接跳出迴圈，代表這個數字不符合題目要求
                count = 0;
                break;
            }
            pre = now;
        }
        rec[i] += (count+rec[i-1]); //加上前面紀錄過的值，以及這個數字所記錄的count
    }
    int input; 
    cin >> input;
    cout << rec[input] << '\n';
    return 0;
}
```

### 第二題
```cpp=
#include <iostream>
using namespace std;
#define MAX 100 //這個 MAX 可以隨便替換

int call_func(){
    static int x = 0; // 使用static 讓x只會被初始化一次
    x++;
    return x;
}

int main(){
    int ans = 0;
    for(int i=0; i<100; i++){
        int rec = call_func();
        ans += rec;  // 讓答案一次一次把從func得到的數字加起來
        cout << ans << '\n';
    }
    return 0;
}
```

### 第三題
:::info
我上課的時候會說，因為有點難解釋，嗚嗚
:::
```cpp=
#include <iostream>
using namespace std;

int ans[5];

void rec(int l, int x, int y, int st_x, int st_y){
    if(l==0){
        return;
    }
    int check[4] = {0};
 
    if(x >= st_x+l && y >= st_y+l)
        check[3] = 1;
    else if(x >= st_x+l && y < st_y+l)
        check[2] = 1;
    else if(x < st_x+l && y >= st_y+l)
        check[1] = 1;
    else
        check[0] = 1;
 
    int half = l/2;
 
    if(check[0]){
        ans[2]++;
        rec(half ,x, y, st_x, st_y);
    }else
        rec(half ,st_x + l-1, st_y + l-1, st_x, st_y);
 
    if(check[1]){
        ans[4]++;
        rec(half ,x, y, st_x, st_y + l);
    }else
        rec(half ,st_x + l-1, st_y + l, st_x, st_y + l);
 
    if(check[2]){
        ans[1]++;
        rec(half ,x, y, st_x + l, st_y);
    }else
        rec(half ,st_x + l, st_y + l-1, st_x + l, st_y);
 
    if(check[3]){
        ans[3]++;
        rec(half ,x, y, st_x + l, st_y + l);
    }else
        rec(half ,st_x + l, st_y + l, st_x + l, st_y + l);
}
 
int main()
{
    rec(2 , 3, 1, 0, 0);
    for(int i=1; i<=4; i++){
        cout << "number " << i << " " << ans[i] << '\n';
    }
    return 0;
}
```