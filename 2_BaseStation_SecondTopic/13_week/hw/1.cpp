#include <iostream>
using namespace std;
int main(){
    int l, r, target;
    while( r-l > 1){
        int mid = (l+r)/2;
        if(target < mid)
            r = mid - 1;
        else
            l = mid;
    }
    // cout 的內容只是我想要讓你知道answer是甚麼而已
    if( r==l || target < r)
        cout << "the answer is " << l << '\n';
    else
        cout << "the answer is " << r << '\n';
}