#include <iostream>
using namespace std;

int ans[10000];

void function(int *a, int *b, int n, int m){
  int i=0, j=0, count = 0;
  while(i!=n && j!=m){
    ans[count++] = a[i];
    ans[count++] = b[j];
    i++;
    j++; 
  }
  if(i==n && j==m)
    return;
  if(i==n){
    while(j!=m){
      ans[count++] = b[j];
      j++; 
    }
  }
  if(j==m){
    while(i!=n){
      ans[count++] = a[i];
      i++;
    }
  }
} 

int main(){
  int n, m;
  cin >> n >> m;
  int array_a[10000], array_b[10000];
  for(int i=0; i<n; i++)
    cin >> array_a[i];
  for(int i=0; i<m; i++)
    cin >> array_b[i];

  function(array_a, array_b, n, m);
  for(int i=0; i<(n+m); i++)
    cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}