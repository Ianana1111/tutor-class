#include<iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> b >> a >> c;
    b--;
    int count = 0, sum = 0;
    while(1){
        if(sum+a>=c){
            for(int i=0; i<=a; i++){
                if(sum+i == c){
                    cout << count+1 << ' ' << count + i << '\n';
                    return 0;
                }
            }
        }
        sum+=a;
        a--;
        if(sum+b>=c){
            for(int i=0; i<=b; i++){
                if(sum+i == c){
                    cout << count+i+1 << ' ' << count + 1<< '\n';
                    return 0;
                }
            }
        }
        sum+=b;
        b--;
        count++;
    }
    return 0;
}