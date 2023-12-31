#include <iostream>
#include <string>
using namespace std;

struct birthday{
    int year = 2023;
    int month = 10;
    int day = 30;
};

struct person{
    string name;
    int years_old;
    birthday birth;
    person(){
        name = "ian";
        years_old = 20;
    }
};

int main(){
    person new_person;
    cout << new_person.name << " " << new_person.years_old << '\n';
    new_person.name = "shelly";
    new_person.years_old = 30;
    cout << new_person.name << " " << new_person.years_old << '\n';
    
    cout << new_person.birth.year << " " << new_person.birth.month << " " << new_person.birth.day << '\n';
}