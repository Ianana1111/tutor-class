#include <iostream>
using namespace std;
int ans[1001];
void counting_sort(int arr[], int n) {
    int tmp[1001] = {0};
    for(int i=0; i<n; i++){
        tmp[arr[i]]++;
    }
    int count = 0;
    for(int i=0; i<1001; i++){
        if(tmp[i]!=0){
            while(tmp[i]--)
                ans[count++] = i;
        }
    }
}

int main(){
    int arr[5] = {5, 4, 1, 2, 1};
    counting_sort(arr, 5);
    for(int i=0; i<5; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
