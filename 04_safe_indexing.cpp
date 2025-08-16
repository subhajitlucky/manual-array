// 04_safe_indexing.cpp
// TODO: implement at(int index) with bounds checks and error handling.

// Placeholder file — implement code described in README.md

#include <iostream>
using namespace std;

struct ManualArray {
    int arr[10];
    size_t size;
    size_t capacity;
    int at(size_t index){
        if(index>=0 && index<size){
            return arr[index];
        }
        return -1;
    }
};

int main(){
    ManualArray myArray = {{0}, 0, 10};
    myArray.arr[0] = 1;
    myArray.size++;
    myArray.arr[1] = 2;
    myArray.size++;

    cout<<myArray.at(0)<<endl;
    cout<<myArray.at(1)<<endl;
}