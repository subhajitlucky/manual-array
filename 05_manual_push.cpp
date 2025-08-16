// 05_manual_push.cpp
// TODO: implement push_back(int) with capacity checks.

// Placeholder file — implement code described in README.md
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

    void push_back(int value) {
        if(size<capacity) {
            arr[size] = value;
            size++;
        }else{
            cout<<"No space"<<endl;
        }
    }
};

int main(){
    ManualArray myArray = {{0}, 0, 1};
    myArray.push_back(10);
    myArray.push_back(20);


    cout << "Element at index 0: " << myArray.at(0) << endl;
    cout << "Element at index 1: " << myArray.at(1) << endl;
}