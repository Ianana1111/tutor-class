# 第六節課解答

### 第一題
```cpp=
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
    //輸入
    for(int i=0; i<3; i++){
        cin >> trian[i].x >> trian[i].y;
    }
    //計算周長
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
```
### 第二題
```cpp=
#include <iostream>
using namespace std;

struct tire{
    int area;
    int perimeter;
    int pressure;
};

struct light{
    int intensity;
    int range;
    int hert;
};

struct car{
    tire tire1;
    light light1;
    int price;
    int sold;
};

int main(){
    car porsche;
    cin >> porsche.tire1.area >> porsche.tire1.perimeter >> porsche.tire1.pressure;
    cin >> porsche.light1.intensity >> porsche.light1.range >> porsche.light1.hert;
    cin >> porsche.price >> porsche.sold;

    cout << porsche.tire1.area << ", " << porsche.tire1.perimeter << ", " << porsche.tire1.pressure << '\n';
    cout << porsche.light1.intensity << ", " << porsche.light1.range << ", " << porsche.light1.hert << '\n';
    cout << porsche.price << ", " << porsche.sold << '\n';
}
```