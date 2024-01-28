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
    int arr[5] = {5, 4, 3, 2, 1};
    insertion_sort(arr, 5);
    for(int i=0; i<5; i++)
        cout << arr[i] << ' ';
    cout << '\n';
    return 0;
}
