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

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);

       
        system("clear"); 
        cout << "Visualization of Selection Sort:" << endl;
        for (int k = 0; k < n; ++k) {
            cout << k << ": ";
            for (int l = 0; l < arr[k]; ++l) {
                cout << "*";
            }
            cout << endl;
        }

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
    selectionSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}