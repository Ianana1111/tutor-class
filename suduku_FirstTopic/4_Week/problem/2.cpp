#include<iostream>
using namespace std;

bool check(string s){
    if(s.length()<8)
        return 0;
    int len = s.length();
    int flag[3]={0};
    for(int i=0; i<len; i++){
        if(isdigit(s[i]))
            flag[0]=1;
        if(isalpha(s[i])){
            if(s[i]>='a' && s[i]<='z')
                flag[1] = 1;
            else if(s[i]>='A' && s[i]<='Z')
                flag[2] = 1;
        }
    }
    for(int i=0; i<3; i++)
        if(flag[i]==0)
            return 0;
    return 1;
}
int main(){
    string s;
    cin >> s;
    bool flag = 1;
    flag = check(s);
    if(flag){
        string s1;
        cin >> s1;
        if(s1 == s)
            cout << "Succeeded!" << '\n';
        else 
            cout << "Failed!" << '\n';
    }else    
        cout << "Failed!" << '\n';
    return 0;
}