// 07_insert_erase_shift.cpp
// TODO: implement insert(index, value) and erase(index) with manual shifts.

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

    void pop(){
        if(size>0){
            size--;
        }else{
            cout<<"Array is empty"<<endl;
        }
    }

    void insert(int index, int value){
        if(size<capacity && index>=0 && index<=size){
            for(int i =size;i>index;i--){
                arr[i] = arr[i-1];
            }
            arr[index] = value;
            size++;
        }
    }

    void erase(int index){
        if(index>=0 && index<size){
            for(int i = index;i<size-1;i++){
                arr[i] = arr[i+1];
            }
            size--;
        }
    }
};

int main(){
    ManualArray myArray = {{0}, 0, 10};
    myArray.push_back(10);
    myArray.pop();
    myArray.pop();
    myArray.push_back(20);
    myArray.push_back(30);
    myArray.push_back(40);
    myArray.insert(1,25);
    myArray.erase(0);


    cout << "Element at index 0: " << myArray.at(0) << endl;
    cout << "Element at index 1: " << myArray.at(1) << endl;
    cout << "Element at index 2: " << myArray.at(2) << endl;
    cout << "Element at index 3: " << myArray.at(3) << endl;
}