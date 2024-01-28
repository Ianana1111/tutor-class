#include <iostream>
using namespace std;

int n;
void find(int step){
    if(n == step){
        // show final answer, etc...
        return;
    }
    // do something
    find(step + 1);
    // reverse
}

int main(){
    find(0);
}