// 13_generic_dynamic_array.cpp
// TODO: implement a template-based or void*-based generic dynamic array.

// Placeholder file — implement code described in README.md

#include <iostream>
#include <utility> // for std::move (if needed)
using namespace std;

template <typename T>
struct GenericArray {
    T* data;
    size_t size;
    size_t capacity;

    // Constructor
    GenericArray(size_t cap = 4)
        : data(new T[cap]), size(0), capacity(cap) {}

    // Destructor
    ~GenericArray() {
        delete[] data;
    }

    // Disable copy to avoid shallow copies (move-only for simplicity)
    GenericArray(const GenericArray&) = delete;
    GenericArray& operator=(const GenericArray&) = delete;

    // Move constructor
    GenericArray(GenericArray&& other) noexcept
        : data(other.data), size(other.size), capacity(other.capacity) {
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    // Move assignment
    GenericArray& operator=(GenericArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            capacity = other.capacity;
            other.data = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }

    // Push back element
    void push_back(const T& value) {
        if (size >= capacity) {
            resize(capacity * 2);
        }
        data[size++] = value;
    }

    // Safe access
    T& at(size_t index) {
        if (index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    const T& at(size_t index) const {
        if (index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // Resize (internal)
    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = std::move(data[i]); // move elements if possible
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    // Get size
    size_t get_size() const { return size; }

    // Get capacity
    size_t get_capacity() const { return capacity; }
};

int main() {
    // Test with int
    GenericArray<int> int_array(2);
    int_array.push_back(10);
    int_array.push_back(20);
    int_array.push_back(30); // triggers resize

    cout << "Int array: ";
    for (size_t i = 0; i < int_array.get_size(); ++i) {
        cout << int_array.at(i) << " ";
    }
    cout << "(size=" << int_array.get_size() << ", capacity=" << int_array.get_capacity() << ")" << endl;

    // Test with double
    GenericArray<double> double_array(2);
    double_array.push_back(1.1);
    double_array.push_back(2.2);
    double_array.push_back(3.3); // triggers resize

    cout << "Double array: ";
    for (size_t i = 0; i < double_array.get_size(); ++i) {
        cout << double_array.at(i) << " ";
    }
    cout << "(size=" << double_array.get_size() << ", capacity=" << double_array.get_capacity() << ")" << endl;

    // Demonstrate move
    GenericArray<int> moved_array = std::move(int_array);
    cout << "After move, moved_array size=" << moved_array.get_size() << endl;

    return 0;
}
