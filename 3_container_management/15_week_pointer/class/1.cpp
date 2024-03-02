#include <iostream>
using namespace std;
int main(){
  int god = 127;
  int ntu = 112;
  int *ptr = &god;
  cout << "ptr: " << ptr << '\n';
  cout << "-------------------" << '\n';
  cout << "&ptr: " << &ptr << '\n';
  cout << "-------------------" << '\n';
  cout << "*ptr: " << *ptr << '\n';
}