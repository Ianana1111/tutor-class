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