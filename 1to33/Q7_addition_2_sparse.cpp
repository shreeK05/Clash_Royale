// 7) Write a program to perform addition of two sparse matrices using the 3-tuple representation. Analyse the time and space complexity of your program and explain why efficient sparse matrix addition is useful for large data sets where most values are zero.
// Concept used: Merging two sorted 3-tuple sparse matrices by row and column.

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

void addSparse(int a[][3], int b[][3], int c[][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        c[0][0] = c[0][1] = c[0][2] = 0;
        return;
    }
    int i = 1, j = 1, k = 1;
    int termsA = a[0][2];
    int termsB = b[0][2];
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];
    while (i <= termsA && j <= termsB) {
        int rA = a[i][0], cA = a[i][1];
        int rB = b[j][0], cB = b[j][1];
        if (rA < rB || (rA == rB && cA < cB)) {
            c[k][0] = rA;
            c[k][1] = cA;
            c[k][2] = a[i][2];
            i++;
            k++;
        } else if (rB < rA || (rA == rB && cB < cA)) {
            c[k][0] = rB;
            c[k][1] = cB;
            c[k][2] = b[j][2];
            j++;
            k++;
        } else {
            int sum = a[i][2] + b[j][2];
            if (sum != 0) {
                c[k][0] = rA;
                c[k][1] = cA;
                c[k][2] = sum;
                k++;
            }
            i++;
            j++;
        }
    }
    while (i <= termsA) {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++;
        k++;
    }
    while (j <= termsB) {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++;
        k++;
    }
    c[0][2] = k - 1;
}

int main() {
    int a[100][3], b[100][3], c[100][3];
    int t1, t2;
    cout << "First sparse matrix:" << endl;
    readTriple(a, t1);
    cout << "Second sparse matrix:" << endl;
    readTriple(b, t2);
    cout << "First matrix:" << endl;
    printTriple(a);
    cout << "Second matrix:" << endl;
    printTriple(b);
    addSparse(a, b, c);
    cout << "Result of addition:" << endl;
    printTriple(c);
    return 0;
}
