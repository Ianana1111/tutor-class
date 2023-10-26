# 第四節課解答
- isdigit用法 -> [isdigit](https://blog.csdn.net/qq_36736330/article/details/81448324)
- isalpha用法 -> [isalpha](https://blog.csdn.net/weixin_41162823/article/details/80172379)
## 字串裡的答案
:::warning
這題的getline有一個小重點，就是在輸入完n的時候，因為程式不會自動換行，因此要用getline先把後面的換行吃掉（這getline指的是第11行），再輸入你要輸入的字串（這指的是第14行），這樣程式才不會出錯
:::
```cpp=
#include<iostream>
using namespace std;
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    s1+=' ';
    int n;
    cin >> n;
    string rec[100];
    string s;
    getline(cin, s); //吃掉n後面的換行來換行，上課的時候還是會說

    for(int i=0; i<n; i++){
        getline(cin, s);
        int pos = s.find(s2);
        s.insert(pos, s1);
        rec[i]=s;
    }
    for(int i=0; i<n; i++)
        cout << rec[i] << '\n';
    return 0;
}
```
## problem 裡的題目
### 第一題
::: info
hint:
這裡有用到函式，但不用太緊張，你只要這樣看，當在第28行時遇到check()，就會自動跳到第4行去執行，而在函式內return的值，會和函式前面設定的變數型態一樣，這禮拜會教，先大概知道怎麼做就好，我還會來講解這題
而我也有用到isdigit和isalpha，都是上禮拜要你去看ㄉ歐，希望你有去查ㄍ資料 嗚嗚
:::
```cpp=
#include<iostream>
using namespace std;

bool check(string s){
    if(s.length()<8) // 用來看成績
        return 0;
    int len = s.length();
    int flag[3]={0}; // 用來記錄有幾個條件達成
    for(int i=0; i<len; i++){
        if(isdigit(s[i]))
            flag[0]=1;
        if(isalpha(s[i])){
            if(s[i]>='a' && s[i]<='z')
                flag[1] = 1;
            else if(s[i]>='A' && s[i]<='Z')
                flag[2] = 1;
        }
    }
    for(int i=0; i<3; i++)
        if(flag[i]==0)
            return 0;
    return 1;
}
int main(){
    string s;
    cin >> s;
    bool flag = 1;
    flag = check(s);
    if(flag){
        string s1;
        cin >> s1;
        if(s1 == s)
            cout << "Succeeded!" << '\n';
        else 
            cout << "Failed!" << '\n';
    }else    
        cout << "Failed!" << '\n';
    return 0;
}
```
### 第二題
::: info
注意我num的使用方式，在第11行，我先初始化為0，當進到14行時，如果用isdigit判斷為數字後，先將num*10 再+當下的數字(用s[i]-'0'，可以去看acsii那張表)，一直做到遇到空格，就可以記錄起整個數字了，上課我一樣還會講，希望你先看過就好
:::
```cpp=
#include<iostream>
using namespace std;
int main(){
    string s;
    int count; //用來記錄一行有幾個數字要運算的
    int rec[1000] = {0}; //紀錄答案
    for(int k=0; k<2; k++){
        getline(cin, s);
        s+=' ';
        int len = s.length();
        int num = 0;
        count = 0;
        for(int i=0; i<len; i++){
            if(isdigit(s[i])){
                num*=10;
                num+=(s[i]-'0');
            }else{
                if(k==0) //若k==0代表 把rec[i]設成對應到的數就好
                    rec[count++] = num;
                else   // 若k==1代表 把rec[i]+=第二排相對應的數
                    rec[count++]+=num;
                num = 0;
            }    
        }
    }
    for(int i=0; i<count; i++){
        cout << rec[i] << " \n"[i==count-1];
    }
    return 0;
}
```
### 第三題
:::info
先把母音都放在compare裡，把ans[4]分別設成相對應的數，ans[0]=數字量，ans[1]=字母總數，ans[2]=母音數，ans[3]=子音數，
:::
```cpp=
#include<iostream>
using namespace std;
int main(){
    int ans[4]={0};
    char compare[10] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
    string s;
    getline(cin, s);
    int len = s.length();
    for(int i=0; i<len; i++){
        if(isdigit(s[i]))
            ans[0]++;
        if(isalpha(s[i])){
            ans[1]++;
            bool flag = 1; //用來看說，若是母音，flag就會設成0，而第22行就不會進入
            for(int j=0; j<10; j++){
                if(s[i]==compare[j]){
                    ans[2]++;
                    flag = 0;
                    break;
                }
            }
            if(flag)
                ans[3]++;

        }
    }
    for(int i=0; i<4; i++)
        cout << ans[i] << " \n"[i==3];
    return 0;
}
```
### 第四題
```cpp=
#include<iostream>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    int ans[26] = {0}; // 開26個大小的陣列
    int len = s.length();
    for(int i=0; i<len; i++){
        if(isalpha(s[i])){ 
            if(s[i]>='a') // 如果大於'a'，代表一定是a~z，因為我們已經用isalpha確認過了
                ans[s[i]-'a']++;  //因此我們就把他數字和'a'相差的大小當作相對應的從0~26來看，並在對應的ans[26]去放值
            else    
                ans[s[i]-'A']++;
        }
    }
    for(int i=0; i<26; i++)
        cout << ans[i] << '\n';
    return 0;
}
```