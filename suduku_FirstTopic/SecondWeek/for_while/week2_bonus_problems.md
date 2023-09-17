# 第二節課_BonusQuestions_answer
## For/While裡的第三題
:::warning
無矩陣版本，上課的時候再跟你說怎麼用矩陣寫
:::
```cpp=
#include<iostream>
using namespace std;
int main(){
    int a, b, c, d;
    while(cin >> a >> b >> c >> d){
        int max = -1, sum;
        //找最大值
        if(a >= b && a>=c && a>=d)
            max = a;
        else if(b >= a && b>=c && b>=d)
            max = b;
        else if(c >= a && c>=b && c>=d)
            max = c;
        else   
            max = d;
        
        int x = a, y = b;
        for(int i=0; i<3; i++){
            if(i==0)
                x = a, y = b;
            else if(i==1)
                x = sum = ((a*b)/y), y = c;
            else if(i==2)
                x = sum = ((sum*c)/y), y = d;
            while(x%y!=0){
                int rem = x%y;
                x = y;
                y = rem;
            }
        }
        x = ((sum*d)/y);
        cout << x/max << '\n';
    }
    return 0;
}
```
## questions的more
### 1. 
```cpp=
#include<iostream>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n ;i++){
        for(int j=1; j<=i; j++){
            cout << j;
        }
    }
    cout << '\n';
    return 0;
    
}
```
### 2.
:::warning
這題其實有點難歐，想點規律，用for去把規律做出來
:::
```cpp=
#include<iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> b >> a >> c; // a 是列數 b是行數 c是要找的值
    b--;
    int count = 0, sum = 0;  // 紀錄現在的量
    while(1){
        if(sum+a>=c){ // 如果sum+a大於等於c 代表現在檢查的這列確定會遇到c
            for(int i=0; i<=a; i++){
                if(sum+i == c){ 
                    cout << count+1 << ' ' << count + i << '\n';
                    return 0;
                }
            }
        }
        sum+=a;
        a--; //扣掉1 下次回圈加的就是少一的a
        if(sum+b>=c){
            for(int i=0; i<=b; i++){
                if(sum+i == c){
                    cout << count+i+1 << ' ' << count + 1<< '\n';
                    return 0;
                }
            }
        }
        sum+=b;
        b--;
        count++;
    }
    return 0;
}
```