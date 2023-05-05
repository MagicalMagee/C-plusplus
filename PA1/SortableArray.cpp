
// SortableArray.cpp
// Class Section: CS 210-07
// Date: 9 October 2022

// Needed Functions in order for the code to work properly
#include "SortableArray.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

    // Default constructor
    SortableArray::SortableArray() {
        max_size = DEFAULT_TEST_SIZE;
        arr = new int[max_size];
        count = 0;
    }

    // Constructor that takes int size as input
    SortableArray::SortableArray(int size) {
        max_size = size;
        arr = new int[size];
        count = 0;
    }

    // Adds element to end of array if there is room
    // Returns true if successful
    bool SortableArray::add(int element) {
        // Adds element at the end of the array as long as there is room
        // then returns true if succesful
        if(count < max_size) {
            arr[count] = element;
            count++;
            return true;
        }
        // returns false once count reached over the max_size of the array
        return false;
    }

    // Adds element at index and shift the array if needed
    // Returns true if successful
    bool SortableArray::add(int element, int index) {
        // Checks if the index is not over and under within the range of the array
        if (index <= max_size && index >= 0) {
            // Shifts the array when it passed the check
            for (count = max_size; count > index; count--) {
                arr[count] = arr[count-1];
            }
            //Adds element at index
            arr[index] = element;
            // Returns true if successful
            return true;
        }
        // Returns false it fails the check or unsuccessful
        return false;
    }

    // Returns the element at a given index
    int SortableArray::get(int index) {
        return arr[index];
    }

    // Removes and returns element at given index
    // Array should be shifted after removal of element
    int SortableArray::remove(int index) { 
        // Checks if the index is out of bounds
        if (index < 0 || index > max_size) {
            // if out of bounds, returns -1
            return -1;
        }

        // Saves the copy of the index
        int element = arr[index];

        // Shifts the array down to the left and remove the targeted index
        // and reduce the size of the array
        arr[index] = 0;
        for (int i = index; i < count; i++) {
                arr[i] = arr[i+1];
            }
        count--;
        return element;
    }


    // Returns the size/capacity of the array
    int SortableArray::size() const {
        return max_size;
    }

    // Reads file from given fileName and stores each number into the array
    // Returns true if successful
    bool SortableArray::readFile(std::string fileName) {
        // Input file stream
        ifstream file;

        // Opens the file: fileName
        file.open(fileName);

        // "Reads" the elements of the entire array
        while(count < max_size && file >> arr[count]) {
            count++;
        }

        // Closes the file then returns true when succesful
        file.close();
        return true;
    }

    // Saves the current array into a text file 
    // Returns true if successful
    bool SortableArray::saveFile(std::string fileName) {
        // Opens file for writing
        ofstream file;
        file.open(fileName);

        // Checks if file is open
        // If open, the elements of the array will be written in the txt.file
        if(file.is_open()) {
            for (int count = 0; count < max_size; count++) {
                file << arr[count] << " ";
            }
            // Closes file
            file.close();
        }
        // Returns true when done/succesful
        return true;
    }

    // Sorts the current array with insertion sort in place
    void SortableArray::insertionSort() {
        // Goes through the array by "inserting" elements by swapping
        for (int i = 1; i < count; i++) {
            int j = i;
            while(i > 0 && arr[j] < arr[j-1]) {

                // Swap arr[j] and arr[j-1] by using a temp or placeholder
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                j--;
            }
        }
    }
