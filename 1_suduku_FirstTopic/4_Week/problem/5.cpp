#include<iostream>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    int ans[26] = {0};
    int len = s.length();
    for(int i=0; i<len; i++){
        if(isalpha(s[i])){
            if(s[i]>='a')
                ans[s[i]-'a']++;
            else    
                ans[s[i]-'A']++;
        }
    }
    for(int i=0; i<26; i++)
        cout << ans[i] << '\n';
    return 0;
}