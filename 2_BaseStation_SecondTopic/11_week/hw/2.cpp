#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n){
    for(int i=1; i<n; i++){
        int j = i;
        while(j-1>=0 && arr[j-1] > arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }    
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    int arr[1001] = {0};
    for(int i=0; i<n; i++)
        cin >> arr[i];
    insertion_sort(arr, n);
    cout << arr[k-1] << '\n';
    return 0;
}