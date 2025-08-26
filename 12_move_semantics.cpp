// 12_move_semantics.cpp
// TODO: implement move constructor and move assignment; demonstrate moves.

// Placeholder file — implement code described in README.md

#include <iostream>
using namespace std;

//declare dynamic array
struct DynamicArray{
  int*  data;
    size_t size;
    size_t capacity;

    //declare constructor
    DynamicArray(size_t capacity){
        this->data = new int[capacity];
        this->size = 0;
        this->capacity = capacity;
    }

    //declare destructor
    ~DynamicArray(){
        delete[] data;
    }


    //move calling
    //take the second dynamicarray data and assign to first
    //release the memory of first dynamic array
    DynamicArray(DynamicArray&& other) {
        this->data = other.data;
        this->size = other.size;
        this->capacity = other.capacity;

        //release the memory of first dynamic array
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    //move assign
    //take the second dynamicarray data and assign to first
    //release the memory of first dynamic array
    DynamicArray& operator=(DynamicArray&& other) {
        if (this != &other) {
            delete[] data;

            this->data = other.data;
            this->size = other.size;
            this->capacity = other.capacity;

            //release the memory of first dynamic array
            other.data = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }
};


int main(){
    DynamicArray arr1(5);
    DynamicArray arr2(10);

    //move copy
    DynamicArray arr4 = std::move(arr1);

    //move assign
    DynamicArray arr3(15);
    arr3 = std::move(arr2);

    // Verify that arr1 and arr2 is in a valid but unspecified state
    // After the move, arr1 , arr2 should not be used except for assignment
    // We can check if the data pointer is nullptr
    if (arr1.data == nullptr) {
        cout << "arr1 is in a valid but unspecified state." << endl;
    }
    if (arr2.data == nullptr) {
        cout << "arr2 is in a valid but unspecified state." << endl;
    }

    

    return 0;
}