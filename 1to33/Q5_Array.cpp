// 5) Write a program to implement basic array operations such as insert, delete, and merge, while simulating a 2D array using a single-dimensional array to optimize space (using both row-major and column-major formats). Use pointer arithmetic to print memory addresses of elements, helping you understand how arrays are stored in memory.
// Concept used: Sequential array operations and 2D-to-1D index mapping with pointer arithmetic.

#include <iostream>
using namespace std;

void displayArray(int arr[], int n, const char* msg) {
    cout << msg << " ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int &n, int pos, int value) {
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;
}

void deleteElement(int arr[], int &n, int pos) {
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void mergeArrays(int a1[], int n1, int a2[], int n2, int merged[]) {
    int k = 0;
    for (int i = 0; i < n1; i++) {
        merged[k++] = a1[i];
    }
    for (int i = 0; i < n2; i++) {
        merged[k++] = a2[i];
    }
}

int main() {
    int arr[100];
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];
    displayArray(arr, n, "Original array:");

    int pos, value;
    cout << "Enter position (0-based) to insert: ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> value;
    insertElement(arr, n, pos, value);
    displayArray(arr, n, "Array after insertion:");

    cout << "Enter position (0-based) to delete: ";
    cin >> pos;
    deleteElement(arr, n, pos);
    displayArray(arr, n, "Array after deletion:");

    int arr2[100], n2;
    cout << "Enter size of second array for merge: ";
    cin >> n2;
    cout << "Enter " << n2 << " elements:" << endl;
    for (int i = 0; i < n2; i++) cin >> arr2[i];
    int merged[200];
    mergeArrays(arr, n, arr2, n2, merged);
    int mergedSize = n + n2;
    displayArray(merged, mergedSize, "Merged array:");

    int rows, cols;
    cout << "Enter rows and columns for 2D simulation: ";
    cin >> rows >> cols;
    int size = rows * cols;
    int arr1D[100];
    cout << "Enter " << size << " elements for 2D array (row-wise):" << endl;
    for (int i = 0; i < size; i++) cin >> arr1D[i];
    int *ptr = arr1D;

    cout << "Row-major order (index = i*cols + j):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = i * cols + j;
            cout << "Element[" << i << "][" << j << "] = " << arr1D[index] << " at address " << (ptr + index) << endl;
        }
    }

    cout << "Column-major order (index = j*rows + i):" << endl;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            int index = j * rows + i;
            cout << "Element[" << i << "][" << j << "] = " << arr1D[index] << " at address " << (ptr + index) << endl;
        }
    }

    return 0;
}
