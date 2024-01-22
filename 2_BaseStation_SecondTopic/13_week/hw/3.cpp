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
            if(l == 0 || l == n-1){
                cout << arr[l] << '\n'; 
            }else{
                if(abs(arr[l]-tar) == abs(arr[l+1]-tar))
                    cout << arr[l] << " " << arr[l+1] << '\n';
                else if(abs(arr[l]-tar) > abs(arr[l+1]-tar))
                    cout << arr[l+1] << '\n';
                else    
                    cout << arr[l] << '\n';
            }
        }else{
            if(r == 0 || r == n-1){
                cout << arr[r] << '\n'; 
            }else{
                if(abs(arr[r]-tar) == abs(arr[r+1]-tar))
                    cout << arr[r] << " " << arr[r+1] << '\n';
                else if(abs(arr[r]-tar) > abs(arr[r+1]-tar))
                    cout << arr[r+1] << '\n';
                else    
                    cout << arr[r] << '\n';
            }
        }
    }
} 