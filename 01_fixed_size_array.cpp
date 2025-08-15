// 01_fixed_size_array.cpp
// TODO: implement the fixed-size array example and tests here.

// Placeholder file — implement code described in README.md

#include <iostream>
using namespace std;

int main(){
    int arr[5] = {1,2,3,4,5};

    for(int i =0;i<5;i++){
        cout<<"value: "<<arr[i]<<" "<<"Address: "<<&arr[i]<<endl;
    }
}