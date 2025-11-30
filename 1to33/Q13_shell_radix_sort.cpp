// 13) Write a program to implement Shell Sort & Radix Sort to analyse their performance on the same input array. Track and display the time taken, number of swaps, and comparisons, and generate a report with the sorted output and performance insights.
// Concept used: Gap-based insertion sort (Shell sort) and digit-wise counting sort (Radix sort) with performance metrics.

#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void shellSort(int arr[], int n, long long &comp, long long &moves) {
    comp = moves = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                comp++;
                arr[j] = arr[j - gap];
                moves++;
                j -= gap;
            }
            comp++; 
            arr[j] = temp;
        }
    }
}

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp, long long &comp, long long &moves) {
    int output[200];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i]/exp)%10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i-1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
        moves++;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    comp += n; 
}

void radixSort(int arr[], int n, long long &comp, long long &moves) {
    comp = moves = 0;
    int maxVal = getMax(arr, n);

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countSort(arr, n, exp, comp, moves);
}

void printArr(int arr[], int n, const char *msg) {
    cout << msg;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a1[200], a2[200];
    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> a1[i];
        a2[i] = a1[i];
    }

    long long compS, moveS, compR, moveR;

    auto t1 = high_resolution_clock::now();
    shellSort(a1, n, compS, moveS);
    auto t2 = high_resolution_clock::now();
    long long timeShell = duration_cast<microseconds>(t2 - t1).count();

    auto t3 = high_resolution_clock::now();
    radixSort(a2, n, compR, moveR);
    auto t4 = high_resolution_clock::now();
    long long timeRadix = duration_cast<microseconds>(t4 - t3).count();

    printArr(a1, n, "\nShell Sorted: ");
    cout << "Shell Sort -> Comparisons: " << compS
         << ", Moves: " << moveS
         << ", Time: " << timeShell << " microseconds\n";

    printArr(a2, n, "Radix Sorted: ");
    cout << "Radix Sort -> Comparisons (digit ops): " << compR
         << ", Moves: " << moveR
         << ", Time: " << timeRadix << " microseconds\n";

    return 0;
}