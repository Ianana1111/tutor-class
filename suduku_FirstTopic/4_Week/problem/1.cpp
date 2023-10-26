#include<iostream>
using namespace std;
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    s1+=' ';
    int n;
    cin >> n;
    string rec[100];
    string s;
    getline(cin, s);

    for(int i=0; i<n; i++){
        getline(cin, s);
        int pos = s.find(s2);
        s.insert(pos, s1);
        rec[i]=s;
    }
    for(int i=0; i<n; i++)
        cout << rec[i] << '\n';
    return 0;
}