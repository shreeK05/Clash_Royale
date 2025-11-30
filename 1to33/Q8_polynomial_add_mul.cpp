// 8) Write a program to implement polynomial addition and multiplication operations using array representation. 
// Concept used: Array of coefficients where index represents power of x, with term-wise addition and convolution multiplication.
#include <iostream>
using namespace std;

void readPoly(int p[], int &deg) {
    cout << "Enter degree: ";
    cin >> deg;
    cout << "Enter coefficients (x^0 to x^" << deg << "): ";
    for (int i = 0; i <= deg; i++) cin >> p[i];
}

void printPoly(int p[], int deg) {
    for (int i = deg; i >= 0; i--) {
        if (p[i] != 0) {
            cout << p[i];
            if (i > 0) cout << "x^" << i;
            if (i != 0) cout << " + ";
        }
    }
    cout << endl;
}

void addPoly(int p1[], int d1, int p2[], int d2, int res[], int &dr) {
    dr = max(d1, d2);
    for (int i = 0; i <= dr; i++) {
        res[i] = 0;
        if (i <= d1) res[i] += p1[i];
        if (i <= d2) res[i] += p2[i];
    }
}

void multPoly(int p1[], int d1, int p2[], int d2, int res[], int &dr) {
    dr = d1 + d2;
    for (int i = 0; i <= dr; i++) res[i] = 0;

    for (int i = 0; i <= d1; i++)
        for (int j = 0; j <= d2; j++)
            res[i+j] += p1[i] * p2[j];
}

int main() {
    int p1[50], p2[50], sum[100], prod[100];
    int d1, d2, ds, dp;

    readPoly(p1, d1);
    readPoly(p2, d2);

    cout << "\nP1(x) = "; printPoly(p1, d1);
    cout << "P2(x) = "; printPoly(p2, d2);

    addPoly(p1, d1, p2, d2, sum, ds);
    cout << "\nP1 + P2 = "; printPoly(sum, ds);

    multPoly(p1, d1, p2, d2, prod, dp);
    cout << "P1 * P2 = "; printPoly(prod, dp);

    return 0;
}
