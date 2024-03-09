#include<iostream>
#include<algorithm>
using namespace std;
int n, m, arr[1000010];
int main(){
	cin>>n;
	for(int i=0 ; i<n ; i++){
		cin>>arr[i];
	}
	sort(arr, arr+n);
	cin>>m;
	for(int i=0, q ; i<m ; i++){
		cin>>q;
    cout << "upper_bound(arr, arr+n, q): " << *upper_bound(arr, arr+n, q) << '\n';
    cout << "lower_bound(arr, arr+n, q): " << *lower_bound(arr, arr+n, q) << '\n';
		cout<<upper_bound(arr, arr+n, q) - lower_bound(arr, arr+n, q)<<"\n";
	}
	return 0;
}