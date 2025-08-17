// 09_resize_with_heap.cpp
// TODO: implement heap-based resize using new[] and delete[].

// Placeholder file — implement code described in README.md

#include <iostream>
using namespace std;

struct DynamicArray{
    int* data;
    int size;
    int capacity;

    DynamicArray(int capacity){
        this->size = 0;
        this->capacity = capacity;
        this->data = new int[capacity];
    }
    ~DynamicArray(){
        delete[] data;
    }

    void resize(){
        int newCap = (capacity == 0 ? 1 : capacity * 2);
        int* newArr = new int[newCap];

        for(int i =0;i<size;i++){
            newArr[i] = data[i];
        }
        delete[] data;
        data = newArr;
        capacity=newCap;
    }

    void push_back(int value){
        if (size==capacity){
            resize();
        }
        if(size<capacity){
            data[size++] = value;
        }
    }
};
int main(){
    DynamicArray array(5);
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    array.push_back(6);

    for (int i = 0; i < array.capacity; i++) {
        cout << array.data[i] << " ";
    }
    cout << endl;

    return 0;
}