#include <iostream>

#define MAX_INT 2147483647

using namespace std;

int main(int argc, char **argv) {
    // Populate the array
    int* arr;
    int arraySize = 1;

    cin >> arraySize;
    arr = new int[arraySize];

    for(int i=0; i<arraySize; i++) {
        cin >> arr[i];
    }

    int* sorted = new int[arraySize];  
    sorted[0] = arr[0];
    // Loop over the initial array, sorting the elements
    for (int i=1; i<arraySize; i++) {
        int current = arr[i];
        for(int j = 0; j < i; j++) {
            
        }
    }    

}