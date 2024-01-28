#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[j+1]) {
            swap(arr[j + 1], arr[j]);
            j--;
        }
    }
}

int main(){
    int n, arr[1001];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    // 在面對未排序的陣列，先排序，變成單調對列，就可以用二分搜去尋找要找的值
    insertion_sort(arr, n);
    int m;
    cin >> m;
    // 共有m次詢問
    while(m--){
        
        int tar;  // target
        cin >> tar;

        // 二分搜
        int l = 0, r = n-1;
        while( r - l > 1){
            int mid = (r + l)/2;
            if(tar < arr[mid])
                r = mid - 1;
            else    
                l = mid;
        }
       // 處理輸出
        if(r == l || tar < arr[r]){
            if(arr[l] == tar)
                cout << tar << '\n';
            else{
                if(l == 0){
                    cout << "no " << arr[l] << '\n'; 
                }else if(l == n-1){
                    cout << arr[l] << " no" << '\n'; 
                }else{
                    cout << arr[l] << " " << arr[l+1] << '\n'; 
                }
            }
        }else{
            if(arr[r] == tar)
                cout << tar << '\n';
            else{
                if(r == 0){
                    cout << "no " << arr[r] << '\n'; 
                }else if(r == n-1){
                    cout << arr[r] << " no" << '\n'; 
                }else{
                    cout << arr[r] << " " << arr[r+1] << '\n'; 
                }
            }
        }
    }
}