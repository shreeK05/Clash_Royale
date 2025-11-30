// 6) Write a program to implement simple transpose and fast transpose of a sparse matrix using the 3-tuple representation. Compare both methods based on their time and space efficiency to understand which one works better for handling large and fragmented data in real-world systems.
// Concept used: Sparse matrix 3-tuple representation with simple scan transpose and counting-based fast transpose.

#include <iostream>
using namespace std;

void readTriple(int a[][3], int &terms) {
    cout << "Enter number of rows, columns and non-zero terms: ";
    cin >> a[0][0] >> a[0][1] >> terms;
    a[0][2] = terms;
    cout << "Enter row, column and value for each non-zero element:" << endl;
    for (int i = 1; i <= terms; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
}

void printTriple(int a[][3]) {
    int terms = a[0][2];
    cout << "Rows Cols Terms: " << a[0][0] << " " << a[0][1] << " " << a[0][2] << endl;
    cout << "Row Col Val:" << endl;
    for (int i = 1; i <= terms; i++) {
        cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << endl;
    }
}

void simpleTranspose(int a[][3], int t[][3]) {
    int rows = a[0][0];
    int cols = a[0][1];
    int terms = a[0][2];
    t[0][0] = cols;
    t[0][1] = rows;
    t[0][2] = terms;
    int k = 1;
    for (int col = 0; col < cols; col++) {
        for (int i = 1; i <= terms; i++) {
            if (a[i][1] == col) {
                t[k][0] = a[i][1];
                t[k][1] = a[i][0];
                t[k][2] = a[i][2];
                k++;
            }
        }
    }
}

void fastTranspose(int a[][3], int t[][3]) {
    int rows = a[0][0];
    int cols = a[0][1];
    int terms = a[0][2];
    t[0][0] = cols;
    t[0][1] = rows;
    t[0][2] = terms;
    if (terms == 0) return;
    int rowTerms[100] = {0};
    int startingPos[100] = {0};
    for (int i = 1; i <= terms; i++) {
        rowTerms[a[i][1]]++;
    }
    startingPos[0] = 1;
    for (int i = 1; i < cols; i++) {
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
    }
    for (int i = 1; i <= terms; i++) {
        int col = a[i][1];
        int pos = startingPos[col];
        t[pos][0] = a[i][1];
        t[pos][1] = a[i][0];
        t[pos][2] = a[i][2];
        startingPos[col]++;
    }
}

int main() {
    int a[100][3], st[100][3], ft[100][3];
    int terms;
    readTriple(a, terms);
    cout << "Original 3-tuple matrix:" << endl;
    printTriple(a);
    simpleTranspose(a, st);
    cout << "Simple transpose 3-tuple matrix:" << endl;
    printTriple(st);
    fastTranspose(a, ft);
    cout << "Fast transpose 3-tuple matrix:" << endl;
    printTriple(ft);
    return 0;
}
