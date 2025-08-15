// 02_access_with_pointers.cpp
// TODO: implement pointer access comparison between arr[i] and *(arr + i).

// Placeholder file — implement code described in README.md

#include <iostream>
using namespace std;

int main(){
    int arr[5] = {1,2,3,4,5};

    //access value via pointers

    for(int i = 0;i<5;i++){
        cout<<"Value : "<<arr[i]<<" "<<"Value via pointer : "<<*(arr+i)<<endl;
    }
}