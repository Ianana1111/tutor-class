#include <iostream>
using namespace std;

int max(int* iptr[], int n);
 
int main() {
    int n;
    int array[100];
    int* iptr[100];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> array[(i + 3) % n];
        iptr[i] = &(array[(i + 3) % n]);
    }
    cout << max(iptr, n) << "\n";
    return 0;
}

int max(int *iptr[], int n){
    int maxx = -1;
    for(int i=0; i<n; i++){
        if(*(iptr[i])>maxx)
            maxx = *(iptr[i]);
    }
    return maxx;
}