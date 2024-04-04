#include <iostream>
#include <string>
using namespace std;

struct family{
  int age = 15;
  string name = "morgan";
  string mom = "mom";
  string dad = "dad";
};

int main(){
  string name = "morgan";
  int age = 15;

  family member;

  // int *thief = NULL;
  family *thief = NULL;
  thief = &member;

}