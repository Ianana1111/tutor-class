#include<iostream>
#include<string>
using namespace std;
int main(){
    string A = "hello";
    string B("world");
    cout << A << ' ' << B << '\n';

    char input1[5] = "nice";
    string C1 = input1;
    string C2(input1);
    cout << C1 << ' ' << C2 << '\n';

    string input2 = "job";
    string D1 = input2;
    string D2(input2);
    cout << D1 << ' ' << D2 << '\n';
    return 0;
}