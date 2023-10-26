#include<iostream>
#include<cstring>
using namespace std;

int main(){
   char s[101];
   char ss[101];
   int m,n;
   cin >> s >> ss;
   cin >> m >> n;
   char ans[202] = "";  
   char tmp[101] = "";
   int count = 0;
   for(int i=0; i<m; i++){
      ans[count] = s[i];
      count++;
   } 
   for(int i=0; i<n; i++){
      ans[count] = ss[i];
      count++;
   } 
   for(int i=0; i<3; i++)
      cout << ans << '\n';
}