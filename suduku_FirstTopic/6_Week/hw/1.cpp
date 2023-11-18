#include<iostream>
#include<cmath>
using namespace std;

struct tri{
    int x;
    int y;
};

int main(){
    tri trian[3];
    int edge[3];
    int perimeter = 0;
    for(int i=0; i<3; i++){
        cin >> trian[i].x >> trian[i].y;
    }
    for(int i=0; i<3; i++){
        int edgex = (trian[((i+1)%3)].x-trian[i].x) * (trian[((i+1)%3)].x-trian[i].x);
        int edgey = (trian[((i+1)%3)].y-trian[i].y) * (trian[((i+1)%3)].y-trian[i].y);
        
        edge[i] = sqrt(edgex + edgey);
        perimeter += edge[i];
    }
    int half_peri = perimeter/2;
    //海龍公式
    int area = sqrt(half_peri*(half_peri-edge[0])*(half_peri-edge[1])*(half_peri-edge[2]));
    int count = 1;
    for(int i=0; i<3; i++){
        cout << '(' << count++ << ')'<< trian[i].x << ", " << trian[i].y << '\n';
    }
    cout << "Area: " << area << '\n';
    cout << "perimeter: " << perimeter << '\n';
    return 0;
}