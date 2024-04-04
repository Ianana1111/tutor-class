#include <iostream>
using namespace std;

struct Person{
  string name;
  int ID;
  int birth;
  int gender;
  Person *spouse;
};

int main(){
  Person boy;
  Person *boy_pointer = &boy;

  Person *pointer = new Person;
  delete(pointer);

  Person girl;
  Person *girl_pointer = &girl;
  boy_pointer -> name = "ian";
  boy_pointer -> ID = 1;
  girl_pointer -> name = "KITTY";
  girl_pointer -> ID = 2;
  boy_pointer -> spouse = &girl;
  girl_pointer -> spouse = &boy;

  cout << boy_pointer -> spouse->ID << '\n';
}