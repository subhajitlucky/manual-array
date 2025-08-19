// 11_rule_of_three.cpp
// TODO: implement copy constructor, copy assignment, and destructor (rule of three).

// Placeholder file — implement code described in README.md


#include <iostream>

struct DynamicArray {
    int* data;
    size_t size;
    size_t capacity;

    // Constructor
    DynamicArray(size_t cap)
        : size(0), capacity(cap) {
        data = new int[capacity];
        std::cout << "Constructor: Allocated " << capacity << " elements\n";
    }

    // Destructor
    ~DynamicArray() {
        delete[] data;
        std::cout << "Destructor: Freed memory\n";
    }

    // Copy Constructor (deep copy)
    DynamicArray(const DynamicArray& other)
        : size(other.size), capacity(other.capacity) {
        data = new int[capacity];
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        std::cout << "Copy Constructor: Created deep copy\n";
    }

    // Copy Assignment Operator (deep copy)
    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) return *this; // self-assignment guard

        // Free old memory
        delete[] data;

        // Copy size & capacity
        size = other.size;
        capacity = other.capacity;

        // Allocate new memory & copy elements
        data = new int[capacity];
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        std::cout << "Copy Assignment: Assigned deep copy\n";

        return *this;
    }

    // Helper: add element
    void push_back(int value) {
        if (size < capacity) {
            data[size++] = value;
        } else {
            std::cout << "No space left\n";
        }
    }

    // Helper: print array
    void print() const {
        for (size_t i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    DynamicArray arr1(5);
    arr1.push_back(10);
    arr1.push_back(20);
    arr1.push_back(30);

    std::cout << "arr1: ";
    arr1.print();

    // Copy constructor test
    DynamicArray arr2 = arr1;  // deep copy
    std::cout << "arr2 (after copy): ";
    arr2.print();

    // Modify arr2
    arr2.push_back(40);
    std::cout << "arr2 (modified): ";
    arr2.print();

    std::cout << "arr1 (should remain unchanged): ";
    arr1.print();

    // Copy assignment test
    DynamicArray arr3(5);
    arr3 = arr1; // deep copy assignment
    std::cout << "arr3 (after assignment from arr1): ";
    arr3.print();

    return 0;
}
