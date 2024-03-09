#include <iostream>
using namespace std;

void function(int *a, int *b, int *c){
  int tmp = *a;
  *a = * c;
  *c = *b;
  *b = tmp;
}

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  function(&a, &b, &c);
  cout << a << " " << b  << " " << c << '\n';
}