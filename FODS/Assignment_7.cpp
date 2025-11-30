#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, int &comp, int &swaps) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
}

void insertionSort(int arr[], int n, int &comp, int &swaps) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && (++comp && arr[j] > key)) {
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high, int &comp, int &swaps) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comp++;
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            swaps++;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    swaps++;
    return i + 1;
}

void quickSort(int arr[], int low, int high, int &comp, int &swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, comp, swaps);
        quickSort(arr, low, pi - 1, comp, swaps);
        quickSort(arr, pi + 1, high, comp, swaps);
    }
}

void shellSort(int arr[], int n, int &comp, int &swaps) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && (++comp && arr[j - gap] > temp); j -= gap) {
                arr[j] = arr[j - gap];
                swaps++;
            }
            arr[j] = temp;
        }
    }
}

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > mx) mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp, int &comp, int &swaps) {
    int output[100];
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        swaps++;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(int arr[], int n, int &comp, int &swaps) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10) countSort(arr, n, exp, comp, swaps);
}

int main() {
    int a = 5;
    int arr1[5] = {5, 1, 4, 2, 3};
    int arr2[5], arr3[5], arr4[5], arr5[5];
    for (int i = 0; i < a; i++) { 
        arr2[i] = arr1[i]; arr3[i] = arr1[i]; arr4[i] = arr1[i]; arr5[i] = arr1[i]; 
    }

    int comp = 0, swaps = 0;

    comp = swaps = 0;
    bubbleSort(arr1, a, comp, swaps);
    cout << "Bubble Sort: ";
    for (int i = 0; i < a; i++) cout << arr1[i] << " ";
    cout << "\nComparisons: " << comp << " Swaps: " << swaps << endl << endl;

    comp = swaps = 0;
    insertionSort(arr2, a, comp, swaps);
    cout << "Insertion Sort: ";
    for (int i = 0; i < a; i++) cout << arr2[i] << " ";
    cout << "\nComparisons: " << comp << " Swaps: " << swaps << endl << endl;

    comp = swaps = 0;
    quickSort(arr3, 0, a - 1, comp, swaps);
    cout << "Quick Sort: ";
    for (int i = 0; i < a; i++) cout << arr3[i] << " ";
    cout << "\nComparisons: " << comp << " Swaps: " << swaps << endl << endl;

    comp = swaps = 0;
    shellSort(arr4, a, comp, swaps);
    cout << "Shell Sort: ";
    for (int i = 0; i < a; i++) cout << arr4[i] << " ";
    cout << "\nComparisons: " << comp << " Swaps: " << swaps << endl << endl;

    comp = swaps = 0;
    radixSort(arr5, a, comp, swaps);
    cout << "Radix Sort: ";
    for (int i = 0; i < a; i++) cout << arr5[i] << " ";
    cout << "\nComparisons: " << comp << " Swaps: " << swaps << endl;

    return 0;
}
