#include <iostream>
using namespace std;

struct MyVector {
    // data 陣列
    int* data;
    int capacity;
    int size;
};

// 初始化
void init(MyVector& vec) {
    vec.capacity = 1;
    vec.size = 0;
    vec.data = new int[vec.capacity];
}

// 存資料
void push_back(MyVector& vec, int element) {
    if (vec.size == vec.capacity) {
        int* newData = new int[2 * vec.capacity];
        for (int i = 0; i < vec.size; ++i) {
            newData[i] = vec.data[i];
        }
        delete[] vec.data;
        vec.data = newData;
        vec.capacity *= 2;
    }
    vec.data[vec.size] = element;
    vec.size++;
}

// 釋放資料
void release(MyVector& vec) {
    delete[] vec.data;
} 

int main(){
  MyVector myVector;
    init(myVector);

    push_back(myVector, 10);
    push_back(myVector, 20);
    push_back(myVector, 30);

    std::cout << "Vector:" << std::endl;
    for (int i = 0; i < myVector.size; ++i) {
        std::cout << myVector.data[i] << std::endl;
    }

    release(myVector);
}