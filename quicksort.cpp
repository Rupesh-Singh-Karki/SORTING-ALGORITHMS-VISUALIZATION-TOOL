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

void printArray(const vector<int>& arr) {
    for (int k = 0; k < arr.size(); ++k) {
        cout << k << ": ";
        for (int l = 0; l < arr[k]; ++l) {
            cout << "*";
        }
        cout << endl;
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        system("clear");
        cout << "Visualization of Quick Sort:" << endl;
        printArray(arr);
        sleepMilliseconds(500);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl << endl;

    cout << "Visualization of Quick Sort:" << endl;
    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
