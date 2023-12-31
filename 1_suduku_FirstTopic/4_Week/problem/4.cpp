#include<iostream>
using namespace std;
int main(){
    int ans[4]={0};
    char compare[10] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
    string s;
    getline(cin, s);
    int len = s.length();
    for(int i=0; i<len; i++){
        if(isdigit(s[i]))
            ans[0]++;
        if(isalpha(s[i])){
            ans[1]++;
            bool flag = 1;
            for(int j=0; j<10; j++){
                if(s[i]==compare[j]){
                    ans[2]++;
                    flag = 0;
                    break;
                }
            }
            if(flag)
                ans[3]++;

        }
    }
    for(int i=0; i<4; i++)
        cout << ans[i] << " \n"[i==3];
    return 0;
}