#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x[100001], y[100001], capa[100001]={0}, stay[100001]={0};
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i] >> capa[i];
    }
    int m;
    cin >> m;
    while(m--){
        int xt, yt;
        cin >> xt >> yt;
        int min = 1e+9, rec = 0, tmp_x, tmp_y; 
        for(int i=0; i<n; i++){
            if(capa[i]<=0) continue;
            int tmp = abs(x[i]-xt) + abs(y[i]-yt);
            if(tmp < min){
                min = tmp;
                rec = i;
                tmp_x = x[i];
                tmp_y = y[i];
            }else if(tmp == min){
                if(x[i]<tmp_x || (x[i]==tmp_x && y[i]<tmp_y)){
                    rec = i;
                    tmp_x = x[i];
                    tmp_y = y[i];
                }
            }
        }
        capa[rec]--;
        stay[rec]++;
    }
    for(int i=0; i<n; i++){
        cout << stay[i] << '\n';
    }
    return 0;
}