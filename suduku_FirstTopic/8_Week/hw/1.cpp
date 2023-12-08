#include <iostream>
using namespace std;

int main(){
    int rec[10001] = {0};
    for(int i = 10; i < 10001; i++){
        int tmp = i, count = 1;
        int pre = tmp % 10;
        tmp/=10;
        while(tmp > 0){
            int now = tmp % 10;
            tmp /= 10;
            if(now > pre){
                count = 0;
                break;
            }
            pre = now;
        }
        rec[i] += (count+rec[i-1]);
    }
    int input; 
    cin >> input;
    cout << rec[input] << '\n';
    return 0;
}