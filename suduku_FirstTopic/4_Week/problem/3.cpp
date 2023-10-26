#include<iostream>
using namespace std;
int main(){
    string s;
    int count;
    int rec[1000] = {0};
    for(int k=0; k<2; k++){
        getline(cin, s);
        s+=' ';
        int len = s.length();
        int num = 0;
        count = 0;
        for(int i=0; i<len; i++){
            if(isdigit(s[i])){
                num*=10;
                num+=(s[i]-'0');
            }else{
                if(k==0)
                    rec[count++] = num;
                else   
                    rec[count++]+=num;
                num = 0;
            }    
        }
    }
    for(int i=0; i<count; i++){
        cout << rec[i] << " \n"[i==count-1];
    }
    return 0;
}