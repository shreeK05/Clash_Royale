// 14) Write a program to implement Quick Sort. Track and display the time taken, number of swaps, and comparisons, and generate a report with the sorted output and performance insights.
// Concept used: Divide and conquer partition-based sorting with performance metrics.

#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

long long compQ = 0;
long long swapsQ = 0;

void swapQ(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
    swapsQ++;
}

int partitionQ(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        compQ++;
        if (arr[j] <= pivot) {
            i++;
            swapQ(arr[i], arr[j]);
        }
    }
    swapQ(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionQ(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArrayQ(int arr[], int n, const char *msg) {
    cout << msg << " ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[100];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];

    auto start = high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = high_resolution_clock::now();
    auto timeQ = duration_cast<microseconds>(end - start).count();

    printArrayQ(arr, n, "\nQuick sorted array:");
    cout << "Quick Sort -> Comparisons: " << compQ << ", Swaps: " << swapsQ << ", Time (microseconds): " << timeQ << endl;

    return 0;
}
