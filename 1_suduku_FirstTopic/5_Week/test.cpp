#include<iostream>
#include<algorithm>
using namespace std;

bool check(int a){
    if(a==1)
        return true;
    else 
        return false;
}

int maxx(int a, int b){
    if(a>b)
        return a;
    else   
        return b;
    // return a > b? a : b;
}

char find_5_char(string s){
    return s[5];
}

void sort_arr(int tmp[]){
    sort(tmp, tmp+5);
    return;
}

int main(){
    cout << check(1) << '\n';
    cout << maxx(10, 9) << " " << max(10, 9) << '\n';
    cout << find_5_char("hellothere") << '\n';
    int tmp[5] = {5, 4, 3, 2, 1};
    sort_arr(tmp);
    for(int i=0; i<5; i++)
        cout << tmp[i] << " \n"[i==4];
}