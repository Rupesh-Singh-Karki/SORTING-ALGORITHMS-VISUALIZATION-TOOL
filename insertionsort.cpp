#include <bits/stdc++.h>
#include <cstdlib> 
#include <ctime>   

using namespace std;

#ifdef _WIN32
#include <windows.h>
void sleepMilliseconds(int milliseconds) {
    Sleep(milliseconds);
}
#else
#include <unistd.h>
void sleepMilliseconds(int milliseconds) {
    usleep(milliseconds * 1000); 
}
#endif

// Function to print the current state of the array
void printArray(const vector<int>& arr) {
    int n = arr.size();
    for (int k = 0; k < n; ++k) {
        cout << k << ": ";
        for (int l = 0; l < arr[k]; ++l) {
            cout << "*";
        }
        cout << endl;
    }
}

// Function to perform insertion sort on an array
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;

        // Shift elements of arr[0..i-1], that are greater than temp, to one position ahead
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place temp at the correct position
        arr[j + 1] = temp;

        // Clear the screen and visualize the current state of the array
        system("clear");
        cout << "Visualization of Insertion Sort:" << endl;
        printArray(arr);
        sleepMilliseconds(500);
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl << endl;

    cout << "Visualization of Selection Sort:" << endl;
    insertionSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}