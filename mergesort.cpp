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

void merge(vector<int>& arr, int s, int e) {
    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays     
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

    system("clear");
    cout << "Visualization of Merge Sort:" << endl;
    printArray(arr);
    sleepMilliseconds(500);
}

void mergeSort(vector<int>& arr, int s, int e) {
    if (s < e) {
        int mid = s + (e - s) / 2;

        mergeSort(arr, s, mid);
        mergeSort(arr, mid + 1, e);

        merge(arr, s, e);
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl << endl;

    cout << "Visualization of Merge Sort:" << endl;
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
