// 12_move_semantics.cpp
// TODO: implement move constructor and move assignment; demonstrate moves.

// Placeholder file — implement code described in README.md

#include <iostream>
using namespace std;

struct DynamicArray{
    int* data;
    size_t size;
    size_t capacity;

    //Constructor
    DynamicArray(size_t cap){
        this->capacity = cap;
        this->size = 0;
        this->data = new int[capacity];
    }

    //Destructor
    ~DynamicArray(){
        delete[] data;
    }

    //move
    DynamicArray(DynamicArray&& other) {
        this->data = other.data;
        this->size = other.size;
        this->capacity = other.capacity;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    //move assign
    DynamicArray& operator=(DynamicArray&& other) {
        if (this != &other) {
            delete[] data; // Free existing resource

            this->data = other.data;
            this->size = other.size;
            this->capacity = other.capacity;

            other.data = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }
};

int main(){
    DynamicArray arr1(10);
    DynamicArray arr2 = std::move(arr1);

}