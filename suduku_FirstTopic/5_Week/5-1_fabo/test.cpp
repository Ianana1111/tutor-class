#include<iostream>
using namespace std;

void swapp(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main(){
    int a, b;
    a = 3; 
    b = 4;
    swapp(a, b);
    cout << a << " " << b << '\n';
}