#include <bits/stdc++.h>
#include <cstdlib> 
#include <ctime>   

using namespace std;

#ifdef _WIN32 //This line checks if the _WIN32 macro is defined
#include <windows.h> //This header provides declarations for all of the functions in the Windows API, including Sleep.
void sleepMilliseconds(int milliseconds) {
    Sleep(milliseconds); //pauses the execution of the current thread for the specified number of milliseconds.
}
#else
#include <unistd.h> //This header provides access to the POSIX operating system API, including the usleep function.
void sleepMilliseconds(int milliseconds) {
    usleep(milliseconds * 1000); //Takes argument in microseconds
}
#endif

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n-1; ++i) {
        swapped = false;
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
       
        system("clear");  //This line clears the console screen
       cout << "Visualization of Bubble Sort:" << endl;
        for (int k = 0; k < n; ++k) {
            cout << k << ": ";
            for (int l = 0; l < arr[k]; ++l) {
                cout << "*";
            }
            cout << endl;
        }

        sleepMilliseconds(500); //This line pauses the execution of the program for 500 milliseconds
        
        if (!swapped) break; 
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    cout << endl << endl;

    cout << "Visualization of Bubble Sort:" << endl;
    bubbleSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}