// 11) Write a menu-driven program to implement and compare different search techniques — Binary, and Fibonacci Search — on sorted and unsorted datasets. Count and display the number of comparisons made by each algorithm to evaluate their efficiency.
// Concept used: Divide and conquer searching (binary, Fibonacci) with comparison counting on sorted and unsorted arrays.

#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int n, int key, int &comp) {
    int low = 0, high = n - 1;
    comp = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        comp++;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int fibonacciSearch(int arr[], int n, int key, int &comp) {
    comp = 0;

    int fib2 = 0;       
    int fib1 = 1;       
    int fib  = fib1 + fib2;  

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib  = fib1 + fib2;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset + fib2, n - 1);
        comp++;

        if (arr[i] < key) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (arr[i] > key) {
            fib  = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            return i;
        }
    }

    if (fib1 && offset + 1 < n) {
        comp++;
        if (arr[offset + 1] == key)
            return offset + 1;
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100], sortedArr[100];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sortedArr[i] = arr[i];
    }

    sort(sortedArr, sortedArr + n);

    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Binary Search (Unsorted)\n";
        cout << "2. Binary Search (Sorted)\n";
        cout << "3. Fibonacci Search (Unsorted)\n";
        cout << "4. Fibonacci Search (Sorted)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            int key, index, comp;
            cout << "Enter key to search: ";
            cin >> key;

            if (choice == 1) {
                sort(arr, arr + n);
                index = binarySearch(arr, n, key, comp);
            }
            else if (choice == 2) {
                index = binarySearch(sortedArr, n, key, comp);
            }
            else if (choice == 3) {
                sort(arr, arr + n);
                index = fibonacciSearch(arr, n, key, comp);
            }
            else {
                index = fibonacciSearch(sortedArr, n, key, comp);
            }

            if (index != -1)
                cout << "Key found at index " << index << endl;
            else
                cout << "Key NOT found!\n";

            cout << "Comparisons = " << comp << endl;
        }

    } while (choice != 5);

    return 0;
}
