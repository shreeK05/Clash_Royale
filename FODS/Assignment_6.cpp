#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key, int &comp) {
    for (int i = 0; i < n; i++) {
        comp++;
        if (arr[i] == key) return i;
    }
    return -1;
}

int sentinelSearch(int arr[], int n, int key, int &comp) {
    int last = arr[n - 1];
    arr[n - 1] = key;
    int i = 0;
    while (true) {
        comp++;
        if (arr[i] == key) break;
        i++;
    }
    arr[n - 1] = last;
    if (i < n - 1 || arr[n - 1] == key) return i;
    return -1;
}

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int key, int &comp) {
    int s = 0, e = n - 1;
    while (s <= e) {
        int mid = (s + e) / 2;
        comp++;
        if (arr[mid] == key) return mid;
        else if (arr[mid] > key) e = mid - 1;
        else s = mid + 1;
    }
    return -1;
}

int fibonacciSearch(int arr[], int n, int key, int &comp) {
    int fib2 = 0, fib1 = 1, fibM = fib1 + fib2;
    while (fibM < n) {
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib1 + fib2;
    }
    int a = -1;
    while (fibM > 1) {
        int i = (a + fib2 < n - 1) ? a + fib2 : n - 1;
        comp++;
        if (arr[i] < key) {
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;
            a = i;
        } else if (arr[i] > key) {
            fibM = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibM - fib1;
        } else return i;
    }
    if (fib1 && a + 1 < n && arr[a + 1] == key) return a + 1;
    return -1;
}

int main() {
    int n, key, pos, choice;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];
    do {
        cout << "1. Linear Search\n";
        cout << "2. Sentinel Search\n";
        cout << "3. Binary Search\n";
        cout << "4. Fibonacci Search\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 5) break;
        cout << "Enter element to search: ";
        cin >> key;
        int comp = 0;
        switch (choice) {
            case 1:
                pos = linearSearch(arr, n, key, comp);
                if (pos != -1) cout << "index : " << pos << endl;
                else cout << "not found" << endl;
                cout << "Comparisons: " << comp << endl;
                break;
            case 2:
                pos = sentinelSearch(arr, n, key, comp);
                if (pos != -1) cout << "index : " << pos << endl;
                else cout << "not found" << endl;
                cout << "Comparisons: " << comp << endl;
                break;
            case 3:
                sortArray(arr, n);
                pos = binarySearch(arr, n, key, comp);
                if (pos != -1) cout << "index : " << pos << endl;
                else cout << "not found" << endl;
                cout << "Comparisons: " << comp << endl;
                break;
            case 4:
                sortArray(arr, n);
                pos = fibonacciSearch(arr, n, key, comp);
                if (pos != -1) cout << "index : " << pos << endl;
                else cout << "not found" << endl;
                cout << "Comparisons: " << comp << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                continue;
        }
    } while (choice != 5);
    return 0;
}
