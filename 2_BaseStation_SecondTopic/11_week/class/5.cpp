#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> hi = {5, 4, 3, 2, 1};
    cout << "origin" << '\n';
    for(int i=0; i<5; i++)
        cout << hi[i] << " \n"[i==4];
    sort(hi.begin(), hi.end());
    cout << "after sorting" << '\n';
    for(int i=0; i<5; i++)
        cout << hi[i] << " \n"[i==4];
}