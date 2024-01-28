#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[101];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int maxx = -1;
    for(int i=1; i<n; i++){
        maxx = max(maxx, arr[i]- arr[i-1]);
    }
    cout << maxx << '\n';
}