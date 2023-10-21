#include<iostream>
#include<cstring>
using namespace std;
int main(){
    // strlen
    char input1[6]="hello";
    cout << strlen(input1);
    cout << '\n';

    //strcmp
    char input2[6]="world";
    char input3[6]="hello";
    cout << strcmp(input1, input2);
    cout << '\n';
    cout << strcmp(input1, input3);
    cout << '\n';

    //strcpy
    char check[3]="ya";
    cout << strcpy(input1, check);
    cout << '\n';

    //strcat
    cout << strcat(input1, input2);
    cout << '\n';
    return 0;
}