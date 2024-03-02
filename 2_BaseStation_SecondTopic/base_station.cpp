#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> house;
int size;

bool find(int rad, int num_base){
    int total = rad*2;
    for(int i=0; i<size; i++){
        if(num_base>0){
            if(i==size-1) return true;
            num_base--;
            int now = house[i];
            while(i+1<size){
                i++;
                int tmp = house[i];
                if(total < tmp-now) {
                    i--;
                    break;
                }
            }
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int num_base, num_house;
        cin >> num_base >> num_house;
        size = num_house;
        while(num_house--){
            int c;
            cin >> c;
            house.push_back(c);
        }
        sort(house.begin(), house.end());
        int l = 0;
        double r = house[size-1] - house[0] + 1;
        int mid = 0;
        while(l != r-1){

            mid = (r+l)/2;
            bool check = find(mid, num_base);
            if(check) r = mid;
            else l = mid;
        }
        cout << r << '\n';
    }
    return 0;
}