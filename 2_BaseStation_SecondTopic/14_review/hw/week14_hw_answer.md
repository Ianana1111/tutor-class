# 第十四周解答

### 第一題
**直接看講義就好囉**

### 第二題
```cpp=
#include<iostream>
using namespace std;
long long n, k, m, L=0, R=1e9+10, A[100005], B[100005], tmp[100005];

long long search(long long l, long long r, long long p){
	while(l<r){
		long long mid = (l+r)/2, cnt=0;
		for(long long i=0 ; i<n ; i++){
			// 先扣除 mid 天可以自己完成的工作量 用mid來確認天數是否可以弄成最小
			tmp[i] = k - A[i]*mid;
			if(tmp[i] > 0){
				// 剩下的全部外包
				cnt += tmp[i]/B[i];
				if(tmp[i] % B[i] > 0) cnt++;
			}
		}
		if(cnt > p) l = mid + 1;
		else r = mid;
	}
	return l;
}

int main(){
	cin>>n>>k>>m;
	for(long long i=0 ; i<n ; i++){
		cin>>A[i];
		R = min(R, A[i]);
	}
	for(long long i=0 ; i<n ; i++){
		cin>>B[i];
	}
	// 最大工作天數為 (工作份數K / 一天處理最小的工作量)
	R = k/R + 1;
	cout<<search(L, R, m)<<"\n";

	return 0;
}
```
![image](https://hackmd.io/_uploads/rkuzDMd2a.png)


1 2 3 4 5 6 7
x x x o o o o 