#include<iostream>
using namespace std;
int main(){

    int a, b, c, opr, d, e, f;
    cin >> a >> b >> c >> opr >> d >> e >> f;
    int new_b, new_e;
    new_b = ( a*c<0? a*c-b : a*c+b ); // 注意正負號
    new_e = ( d*f<0? d*f-e : d*f+e );

    //做運算
    int divsor, divden;
    switch(opr){
        case 0: // addition
            divsor = new_b*f + new_e*c;
            divden = c*f;
            break;          
        case 1: // minus
            divsor = new_b*f - new_e*c;
            divden = c*f;
            break;
        case 2: 
            divsor = new_b * new_e;
            divden = c*f;
            break;
        case 3:
            divsor = new_b / f;
            divden = c/new_e;
            break;
        default:
            break;
    }
    int x, y;
    x = divsor<0? -divsor : divsor; 
    y = divden; 

    // 找最大公因數
    while(x%y!=0){  // 輾轉相除法 -> 最大公因數
        int rem = x%y;
        x = y;
        y = rem;  // 2
    }

    //約分
    divsor/=y; // divsor = divsor / y;
    divden/=y;

    //把假分數換成帶分數
    int intt = divsor/divden;
    divsor%=divden; //divsor = divsor % divden;
    int div;
    
    //輸出成題目要的樣子
    if(divsor==0){
        div = 0;
        divden = 1;
    }else{
        div = divsor<0? (-divsor): divsor;
    }
    cout << intt <<" "<< div << " " << divden << '\n';
}

