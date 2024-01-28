#include<iostream>
using namespace std;

// 最大公因數
int gcd(int x, int y){  // x = ans1 = 2 , y = tmp1 = 3
    while(x%y!=0){  
        int rem = x%y;
        x = y;
        y = rem;
    }
    return y;
}

//算公倍數
int lcm(int ans1, int tmp1){  // ans1 = ans = 2 , tmp1 = arr[1] = 3
    return (ans1*tmp1)/gcd(ans1, tmp1);  // gcd(ans1, tmp1) = y
}

int main(){
    int arr[4] = {2, 3, 4 , 5};
    int ans = arr[0];
    for(int i=1; i<4; i++){
        ans = lcm(ans, arr[i]);  // ans = 2, arr[i] = 3
    }
    cout << ans << '\n';
}

// 2 4
// 2 * 4 / gcd(2, 4)

// 23 : lcm(  ans   ,   arr[i] )
// 15 : lcm(int ans1, int tmp1 ) int ans1 = ans, int tmp1 = arr[i]
// 16 : gcd(  ans1  ,    tmp1  )
// 5  : gcd( int x  ,   int y  ) int x = ans1, int y = tmp1













    // string s;
    // getline(cin, s);
    // int arr[10000] = {0};
    // s+=' ';
    // int len = s.length();
    // int num = 0, count = 0;
    // for(int i=0; i<len; i++){
    //     if(isdigit(s[i])){
    //         num*=10;
    //         num+=(s[i]-'0');
    //     }else{
    //         arr[count++] = num;
    //         num=0;
    //     }
    // }