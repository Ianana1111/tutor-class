#### 第十五周解答

[toc]

### 第一題

:::success
第一題的部分 明天上課會教你怎麼使用
:::
```cpp=
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
		cout<<upper_bound(arr, arr+n, q) - lower_bound(arr, arr+n, q)<<"\n";
	}
	return 0;
}
```

### 第二題
```cpp=
#include <iostream>
using namespace std;

int max(int* iptr[], int n);
 
int main() {
    int n;
    int array[100];
    int* iptr[100];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> array[(i + 3) % n];
        iptr[i] = &(array[(i + 3) % n]);
    }
    cout << max(iptr, n) << "\n";
    return 0;
}

int max(int *iptr[], int n){
    int maxx = -1;
    for(int i=0; i<n; i++){
        if(*(iptr[i])>maxx)
            maxx = *(iptr[i]);
    }
    return maxx;
}
```