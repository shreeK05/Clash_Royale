// 9) Write a program to store a polynomial using an array of structures, where each structure contains a coefficient and an exponent. Perform polynomial addition and multiplication using this structure-based representation. Compare the efficiency of this approach with the previous method and explain which representation is better and why.
// Concept used: Array of terms (coefficient, exponent) with merge-based addition and term-wise multiplication plus combining like exponents.

#include <iostream>
using namespace std;

struct Term {
    int coeff;
    int exp;
};

void readPoly(Term p[], int &n) {
    cout << "Enter number of terms: ";
    cin >> n;
    cout << "Enter coeff and exponent (in descending exponent order):\n";
    for (int i = 0; i < n; i++) {
        cin >> p[i].coeff >> p[i].exp;
    }
}

void printPoly(Term p[], int n) {
    for (int i = 0; i < n; i++) {
        cout << p[i].coeff << "x^" << p[i].exp;
        if (i != n - 1) cout << " + ";
    }
    cout << endl;
}

void addPoly(Term A[], int n1, Term B[], int n2, Term C[], int &n3) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (A[i].exp == B[j].exp) {
            int sum = A[i].coeff + B[j].coeff;
            if (sum != 0) {
                C[k].coeff = sum;
                C[k].exp = A[i].exp;
                k++;
            }
            i++; j++;
        }
        else if (A[i].exp > B[j].exp) {
            C[k++] = A[i++];
        }
        else {
            C[k++] = B[j++];
        }
    }

    while (i < n1) C[k++] = A[i++];
    while (j < n2) C[k++] = B[j++];

    n3 = k;
}

void multiplyPoly(Term A[], int n1, Term B[], int n2, Term C[], int &n3) {
    Term temp[200];
    int k = 0;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            temp[k].coeff = A[i].coeff * B[j].coeff;
            temp[k].exp = A[i].exp + B[j].exp;
            k++;
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (temp[i].exp == temp[j].exp) {
                temp[i].coeff += temp[j].coeff;
                temp[j].coeff = 0; 
            }
        }
    }

    n3 = 0;
    for (int i = 0; i < k; i++) {
        if (temp[i].coeff != 0) {
            C[n3++] = temp[i];
        }
    }
}

int main() {
    Term P1[100], P2[100], Sum[200], Prod[200];
    int n1, n2, nSum, nProd;

    cout << "Polynomial 1:\n";
    readPoly(P1, n1);

    cout << "Polynomial 2:\n";
    readPoly(P2, n2);

    cout << "\nP1(x) = ";
    printPoly(P1, n1);

    cout << "P2(x) = ";
    printPoly(P2, n2);

    addPoly(P1, n1, P2, n2, Sum, nSum);
    cout << "\nP1 + P2 = ";
    printPoly(Sum, nSum);

    multiplyPoly(P1, n1, P2, n2, Prod, nProd);
    cout << "P1 X P2 = ";
    printPoly(Prod, nProd);

    return 0;
}
