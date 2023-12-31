#include <iostream>
using namespace std;
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
    	bool has_swap = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                has_swap = true; 
            }
        }
        if (!has_swap) 
        	break;
    }
}

int main(){
    int arr[5] = {5, 4, 3, 2, 1};
    bubble_sort(arr, 5);
    for(int i=0; i<5; i++)
        cout << arr[i] << ' ';
    cout << '\n';
    return 0;
}
