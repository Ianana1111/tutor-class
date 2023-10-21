#include<iostream>
using namespace std;
int main(){
    //讀寫string 中的特定字元
    string s = "abcde";
    cout << "s[1]'s value: "<<s[1] << "   " << "s.at(3)'s value: " <<s.at(3) << '\n';
    cout << '\n';

    //回傳string的長度
    cout << "s's length: "<<s.size() << "   "<< s.length() << '\n';
    cout << '\n'; 

    //兩個string相接
    string s1 = "12345";
    cout << "s+s1: " << s+s1 << ' ';
    s+=s1;
    cout << "s+=s1: " << s <<'\n';
    cout << '\n';

    //string 比大小
    if(s>s1)
        cout << "s>s1" <<'\n';
    else    
        cout << "s<s1" << '\n';
    cout << '\n';

    //找substring(子字串)
    string rr = "i know you know my name";
    cout << "The position of first know: "<<rr.find("know") << '\n';
    cout << "The position of second know: "<<rr.find("know", 5) << '\n';
    if(rr.find("hi") == string::npos)
        cout << "We can't find 'hi' in rr" << '\n';
    cout << '\n';

    //插入字串
    string ss = "hellothere";
    cout << ss.insert(4, "12345") << '\n';
    cout << '\n';

    //刪除字串
    cout << ss.erase(4, 5) << '\n';
    cout << '\n';

    //讀入整條字串(包含空格)
    string input;
    cout << "Please type some words: ";
    getline(cin, input, '\n');
    cout << input << '\n';
    cout << '\n';
    return 0;
}