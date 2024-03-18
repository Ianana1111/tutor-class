# 16周解答

[toc]

### 第一題
```cpp=
#include <iostream>
using namespace std;

int ans[10000];
a[] = 1 2 3 4 5
b[] = 6 7 8 9 10
ans[] = 
void function(int *a, int *b, int n, int m){
  int i=0, j=0, count = 0;
  while(i!=n && j!=m){
    // 這必須小心
    ans[count++] = a[i];
    ans[count++] = b[j];
    i++;
    j++; 
  }
  if(i==n && j==m)
    return;
  if(i==n){
    while(j!=m){
      ans[count++] = b[j];
      j++; 
    }
  }
  if(j==m){
    while(i!=n){
      ans[count++] = a[i];
      i++;
    }
  }
} 

int main(){
  int n, m;
  cin >> n >> m;
  int array_a[10000], array_b[10000];
  for(int i=0; i<n; i++)
    cin >> array_a[i];
  for(int i=0; i<m; i++)
    cin >> array_b[i];

  function(array_a, array_b, n, m);
  for(int i=0; i<(n+m); i++)
    cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}
```

### 第二題
```cpp=
#include <iostream>
using namespace std;

void function(int *a, int *b, int *c){
  int tmp = *a;
  *a = * c;
  *c = *b;
  *b = tmp;
}

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  function(&a, &b, &c);
  cout << a << " " << b  << " " << c << '\n';
}
```

### 第三題

```cpp=
#include <stdio.h>
#include <stdlib.h>

int evaluate_f(int *iptr[], int n, int *index){
  int max = -1;
  for(int i=0; i<n; i++){
    if(4*iptr[i][0] - 6*iptr[i][1] > max){
      *index = i;
      max = 4*iptr[i][0] - 6*iptr[i][1];
    }
  }
  return max;
}
	 
int main(){
	int a[] = { 9, 7 };
  int b[] = { 3, 2 };
	int c[] = { 3, 2 };
  int d[] = { 9, 7 };
	int *iptr[] = { a, b, c, d };
  int max, index;
	max = evaluate_f(iptr, 4, &index);
  printf("%d %d\n", max, index);
}

```

### 第四題

```cpp=
#include <iostream>
using namespace std;

void prepare_array(int buffer[], int *array[], int row, int column[]){
  int count = 0;
  for(int i=0; i<row; i++){
    for(int j=0; j<column[i]; j++){
      array[i] = &buffer[count++]; 
    }
  }
  return;
}

int main() {
    int row = 4;
    int column[4] = {10, 20, 30, 10};
    int *array[50];
    int buffer[10000];
    prepare_array(buffer, array, row, column);
    for (int i = 0; i < 4; i++)
     for (int j = 0; j < column[i]; j++)
       array[i][j] = i * 100 + j;
    return 0;
}
```