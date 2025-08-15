// 03_array_in_struct.cpp
// TODO: define FixedArray struct with data[], size, capacity and simple initialization.

// Placeholder file — implement code described in README.md

#include <iostream>
using namespace std;

struct FixedArray {
    int data[10];
    size_t size;
    size_t capacity;
};
int main(){

    FixedArray arr = {{0},0,10};
    arr.data[0]=1;
    arr.size++;
    arr.data[1]=2;
    arr.size++;
    arr.data[2]=3;
    arr.size++;

    cout<<"size : "<<arr.size<<endl;
    cout<<"capacity : "<<arr.capacity<<endl;

    return 0;
}