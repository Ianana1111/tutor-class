# 第七節課解答

[TOC]

:::info
上面兩個遞迴式的int main函式都長下面這樣
```cpp=
int main(){
    int n, m;
    cin >> n >> m;
    cout << recursion(n, m) << '\n';
}
```
:::
### 一般遞迴式
```cpp=
int recursion(int n, int m){
    if(n==0 || m==0)
        return 1;
    return recursion(n-1, m) + recursion(n, m-1);
}
```

### 有記憶版遞迴式
```cpp=
int mem[10000][10000];
int visit[10000][10000];
int recursion(int n, int m){
    if(n==0 || m==0)
        return 1;
    if(visit[n][m])
        return mem[n][m];
    mem[n][m] = recursion(n-1, m) + recursion(n, m-1);
    visit[n][m] = 1;
    return mem[n][m];
}
```

### dp形式
:::info
下面的int main長這樣
```cpp=
int main(){
    int n, m;
    cin >> n >> m;
    dp();
    cout << rec[n][m] << '\n';
}
```
:::
```cpp=
int rec[10000][10000];
void dp(){
    for(int i=0; i<1001; i++){
        rec[0][i] = 1;
        rec[i][0] = 1;
    }    
    for(int i=1; i<1001; i++){
        for(int j=1; j<1001; j++){
            rec[i][j] = rec[i-1][j] + rec[i][j-1];
        }
    }
}
```