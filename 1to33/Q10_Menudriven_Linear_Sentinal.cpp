//10)	Write a menu-driven program to implement and compare different search techniques — Linear, Sentinel Search — on sorted and unsorted datasets. Count and display the number of comparisons made by each algorithm to evaluate their efficiency.
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key, int &comp) {
    comp = 0;
    for (int i = 0; i < n; i++) {
        comp++;
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int sentinelSearch(int arr[], int n, int key, int &comp) {
    comp = 0;
    int last = arr[n - 1];
    arr[n - 1] = key;

    int i = 0;
    while (true) {
        comp++;
        if (arr[i] == key)
            break;
        i++;
    }

    arr[n - 1] = last;
    if (i < n - 1 || last == key)
        return i;
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Linear Search\n";
        cout << "2. Sentinel Search\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            int key, index, comp = 0;
            cout << "Enter key to search: ";
            cin >> key;

            if (choice == 1)
                index = linearSearch(arr, n, key, comp);
            else
                index = sentinelSearch(arr, n, key, comp);

            if (index != -1)
                cout << "Key found at index " << index << endl;
            else
                cout << "Key not found\n";

            cout << "Comparisons = " << comp << endl;
        }

    } while (choice != 3);

    return 0;
}
