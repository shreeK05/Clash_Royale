// 12) Write a program to implement Bubble, Insertion Sort to analyse their performance on the same input array. Track and display the time taken, number of swaps, and comparisons, and generate a report with the sorted output and performance insights.
// Concept used: Comparison-based sorting (bubble and insertion) with time, swap, and comparison counting.

#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void bubbleSort(int arr[], int n, long long &comparisons, long long &swaps) {
    comparisons = 0;
    swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
                swaps++;
            }
        }
    }
}

void insertionSort(int arr[], int n, long long &comparisons, long long &swaps) {
    comparisons = 0;
    swaps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n, const char *msg) {
    cout << msg << " ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr1[100], arr2[100];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    long long compB, swapsB, compI, swapsI;
    auto start1 = high_resolution_clock::now();
    bubbleSort(arr1, n, compB, swapsB);
    auto end1 = high_resolution_clock::now();
    auto timeB = duration_cast<microseconds>(end1 - start1).count();

    auto start2 = high_resolution_clock::now();
    insertionSort(arr2, n, compI, swapsI);
    auto end2 = high_resolution_clock::now();
    auto timeI = duration_cast<microseconds>(end2 - start2).count();

    printArray(arr1, n, "\nBubble sorted array:");
    cout << "Bubble Sort -> Comparisons: " << compB << ", Swaps: " << swapsB << ", Time (microseconds): " << timeB << endl;

    printArray(arr2, n, "\nInsertion sorted array:");
    cout << "Insertion Sort -> Comparisons: " << compI << ", Swaps: " << swapsI << ", Time (microseconds): " << timeI << endl;

    return 0;
}
