#include <iostream>
using namespace std;

int maxx = -1;

bool avali[102] = {false};
void find(int arr[102][2002], int rec_pos[102], int n, int num, int rec){
    // 當全部avali都變成true後，就做一次比較
    if(n == num){
        maxx = max(maxx, rec);
        return;
    }
    // backtracking，上課會講
    for(int i=1; i<=n; i++){
        if(!avali[i]){
            int count = 0, tmp[102] = {0};
            avali[i] = true;
            for(int j=0; j<rec_pos[i]; j++){
                if(avali[arr[i][j]] == false)
                    tmp[count++] = arr[i][j];
                avali[arr[i][j]] = true;
            }
            find(arr, rec_pos, n, num + 1 + count, rec+1);
            avali[i] = false;
            for(int j=0; j<count; j++){
                avali[tmp[j]] = false;
            }
        }
    }
    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    int arr[102][2002] = {{0}}; // 用來記錄那些寶石們互相相衝
    int rec_pos[102] = {0}; // 用來記錄寶石們相衝個數
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        arr[a][rec_pos[a]++] = b; 
        arr[b][rec_pos[b]++] = a;
    }
    find(arr, rec_pos, n, 0, 0);
    cout << maxx << '\n';
}
// 1 2
// 2 1 3 4 5 6
// 3 2 4
// 4 2 3 5
// 5 2 4 6
// 6 2 5

// 1 2
// 2 3 4 5 6
// 3 4
// 4 5
// 5 6
