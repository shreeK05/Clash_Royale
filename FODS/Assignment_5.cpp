#include <iostream>
using namespace std;

void addPolynomials(int poly1[], int size1, int poly2[], int size2, int result[], int resultSize) {
    for (int i = 0; i < resultSize; i++) {
        int coeff1 = 0, coeff2 = 0;
        if (i < size1) {
            coeff1 = poly1[i];
        }
        if (i < size2) {
            coeff2 = poly2[i];
        }
        result[i] = coeff1 + coeff2;
    }
}

void subtractPolynomials(int poly1[], int size1, int poly2[], int size2, int result[], int resultSize) {
    for (int i = 0; i < resultSize; i++) {
        int coeff1 = 0, coeff2 = 0;
        if (i < size1) {
            coeff1 = poly1[i];
        }
        if (i < size2) {
            coeff2 = poly2[i];
        }
        result[i] = coeff1 - coeff2;
    }
}

void multiplyPolynomials(int poly1[], int size1, int poly2[], int size2, int result[]) {
    for (int i = 0; i < size1 + size2 - 1; i++) {
        result[i] = 0;
    }

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }
}

void printPolynomial(int poly[], int size) {
    for (int i = 0; i < size; i++) {
        cout << poly[i] << "x^" << i;
        if (i != size - 1) {
            cout << " + ";
        }
    }
    cout << endl;
}

int main() {
    int size1 = 5;
    int size2 = 4;

    int eq1[5] = {3, 2, 0, 5, 0};  
    int eq2[4] = {1, 0, 4, 2};     

    int choice;
    cout << "Polynomial Operations:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int resultSize;
            if (size1 > size2) {
                resultSize = size1;
            } else {
                resultSize = size2;
            }
            int result[resultSize];
            addPolynomials(eq1, size1, eq2, size2, result, resultSize);
            cout << "Result (eq1 + eq2): ";
            printPolynomial(result, resultSize);
            break;
        }
        case 2: {
            int resultSize;
            if (size1 > size2) {
                resultSize = size1;
            } else {
                resultSize = size2;
            }
            int result[resultSize];
            subtractPolynomials(eq1, size1, eq2, size2, result, resultSize);
            cout << "Result (eq1 - eq2): ";
            printPolynomial(result, resultSize);
            break;
        }
        case 3: {
            int resultSize = size1 + size2 - 1;
            int result[resultSize];
            multiplyPolynomials(eq1, size1, eq2, size2, result);
            cout << "Result (eq1 * eq2): ";
            printPolynomial(result, resultSize);
            break;
        }
        default:
            cout << "Invalid choice" << endl;
    }

    return 0;
}
