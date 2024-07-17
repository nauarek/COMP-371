#include <iostream>
#include "Point.h"
#include "Triangle.h"
#include "Driver.h"

using namespace std;

// Part 1

// Take in the size of the array
// Return an array of the specified size
int* createArray(int size) {
    cout << "Creating an array of size " << size << endl;
    int* arr = new int[size];
    return arr;
}

// Take in the array pointer, and size of the array
// Populate the array
// Return the populated array
void initializeArray(int* ptr, int size) {
    cout << "Initializing the array" << endl;
    for (int i = 0; i < size; i++) {
        ptr[i] = i;
    }
}

// Take in the array pointer, and size of the array
// Loop through the array and print the values
void printArray(int* ptr, int size) {
    cout << "Printing the array: " ;
    for (int i = 0; i < size; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;
}

// Take in the array pointer
// Delete the array, and set the pointer to nullptr
void deleteArray(int* ptr) {
    cout << "Deleting the array" << endl;
    delete[] ptr;
    ptr = nullptr;
}

// Driver function for part 1
void part1() {
    int size;
    cout << "Please enter the size of array you want: ";
    cin >> size;

    int* arr = createArray(size);
    initializeArray(arr, size);
    printArray(arr, size);
    deleteArray(arr);
}

// Main function
int main() {
    cout << "Part 1 of Assignment:" << endl;
    part1();
    // Now time for part 2
    cout << "Part 2 of Assignment:" << endl;
    Driver driver;
    driver.run();
    return 0;
}
