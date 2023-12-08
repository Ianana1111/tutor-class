#include <iostream>
using namespace std;

int ans[5];
 
void rec(int l, int x, int y, int st_x, int st_y){
    if(l==0){
        return;
    }
    int check[4] = {0};
 
    if(x >= st_x+l && y >= st_y+l)
        check[3] = 1;
    else if(x >= st_x+l && y < st_y+l)
        check[2] = 1;
    else if(x < st_x+l && y >= st_y+l)
        check[1] = 1;
    else
        check[0] = 1;
 
    int half = l/2;
 
    if(check[0]){
        ans[2]++;
        rec(half ,x, y, st_x, st_y);
    }else
        rec(half ,st_x + l-1, st_y + l-1, st_x, st_y);
 
    if(check[1]){
        ans[4]++;
        rec(half ,x, y, st_x, st_y + l);
    }else
        rec(half ,st_x + l-1, st_y + l, st_x, st_y + l);
 
    if(check[2]){
        ans[1]++;
        rec(half ,x, y, st_x + l, st_y);
    }else
        rec(half ,st_x + l, st_y + l-1, st_x + l, st_y);
 
    if(check[3]){
        ans[3]++;
        rec(half ,x, y, st_x + l, st_y + l);
    }else
        rec(half ,st_x + l, st_y + l, st_x + l, st_y + l);
}
 
int main()
{
    rec(2 , 3, 1, 0, 0);
    for(int i=1; i<=4; i++){
        cout << "number " << i << " " << ans[i] << '\n';
    }
    return 0;
}