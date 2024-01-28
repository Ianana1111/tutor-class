#include <iostream>
using namespace std;  

void selection_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[min] > arr[j])
                min = j;
        }
        swap(arr[min], arr[i]);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[1001] = {0};
    for(int i=0; i<n; i++)
        cin >> arr[i];

    selection_sort(arr, n);

    for(int i=0; i<n; i++)
        cout << arr[i] << " \n"[i==n-1];
    
    int ans = 1000001;
    int size = n-1;
    for (int i = 0; i <= size; i++) {
        int count = 0;
        count += arr[i];
        int j = i;
        while (arr[j+1] <= arr[i] && j+1<=size) j++;
        ans = min(ans, count+(size-j));
    }
    if(ans < size+1) cout << ans << '\n';
    else cout << size+1 << '\n';
}