#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int fabo[10000];
    fabo[1] = 1;
    fabo[2] = 1;
    for(int i=3; i<10000; i++){
        fabo[i] = fabo[i-1] + fabo[i-2];
    }
    cout << fabo[n] << '\n';
}
