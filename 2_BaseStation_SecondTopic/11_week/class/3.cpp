#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
    	int key = arr[i]; 
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; 
    }
}
int main(){
    int arr[5] = {5, 4, 3, 2, 1};
    insertion_sort(arr, 5);
    for(int i=0; i<5; i++)
        cout << arr[i] << ' ';
    cout << '\n';
    return 0;
}
