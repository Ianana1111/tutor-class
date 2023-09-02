#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[4];
    for(int i=0; i<3; i++) //輸入數字進陣列
        cin >> arr[i];
    sort(arr, arr+3, std::greater<int>()); //排序，使陣列由大到小排列

    //判斷是哪一種三角形
    if(arr[0]>=(arr[1]+arr[2]))
        cout << "No" << '\n';
    else if(arr[0]*arr[0] > arr[1]*arr[1] + arr[2]*arr[2])
        cout << "Obtuse" << '\n';
    else if(arr[0]*arr[0] == arr[1]*arr[1] + arr[2]*arr[2])
        cout << "Right" << '\n';
    else 
        cout << "Acute" << '\n';
    return 0;
}