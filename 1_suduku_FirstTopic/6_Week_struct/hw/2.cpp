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