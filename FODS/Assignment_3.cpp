#include<iostream>
using namespace std;

void insertVal(int *mat, int r, int c, int row, int col, int val, bool rowMajor, bool colMajor) {
    int idx;
    if(rowMajor) {
        idx = row * c + col;
    }
    if(colMajor) {
        idx = col * r + row;
    }
    mat[idx] = val;

    if(rowMajor) {
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cout << mat[i * c + j] << "(" << &mat[i * c + j] << ") ";
            }
            cout << "\n";
        }
    }
    if(colMajor) {
        for(int i = 0; i < c; i++) {
            for(int j = 0; j < r; j++) {
                cout << mat[i * r + j] << "(" << &mat[i * r + j] << ") ";
            }
            cout << "\n";
        }
    }
}

void deleteVal(int *mat, int r, int c, int row, int col, bool rowMajor, bool colMajor) {
    int idx;
    if(rowMajor) {
        idx = row * c + col;
    }
    if(colMajor) {
        idx = col * r + row;
    }
    mat[idx] = 0;

    if(rowMajor) {
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cout << mat[i * c + j] << "(" << &mat[i * c + j] << ") ";
            }
            cout << "\n";
        }
    }
    else {
        for(int i = 0; i < c; i++) {
            for(int j = 0; j < r; j++) {
                cout << mat[i * r + j] << "(" << &mat[i * r + j] << ") ";
            }
            cout << "\n";
        }
    }
}

void mergeMat(int *mat1, int *mat2, int *res, int r, int c, bool rowMajor, bool colMajor) {
    if(rowMajor) {
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                res[i * c + j] = mat1[i * c + j] + mat2[i * c + j]; 
            }
        }
        cout << "Merged Array :" << endl;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cout << res[i * c + j] << "(" << &res[i * c + j] << ") ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    if(colMajor) {
        for(int i = 0; i < c; i++) {
            for(int j = 0; j < r; j++) {
                res[i * r + j] = mat1[i * r + j] + mat2[i * r + j];
            }
        }
        cout << "Merged Array :" << endl;
        for(int i = 0; i < c; i++) {
            for(int j = 0; j < r; j++) {
                cout << res[i * r + j] << "(" << &res[i * r + j] << ") ";
            }
            cout << "\n";
        }
    }
}

int main() {
    int matA[100] = {2, 4, 6, 3, 7, 4};
    int matB[100] = {4, 2, 11, 9, 10, 8};
    int matC[100]; 

    int r = 2;
    int c = 3;

    cout << "Matrix in Row Major :" << endl;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << matA[i * c + j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    cout << "Matrix in Column Major :" << endl;
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            cout << matA[i * r + j] << " ";
        }
        cout << "\n";
    }

    int choice, row, col, val, pref;
    bool rowMajor = false, colMajor = false;

    do {
        cout << "Menu:\n";
        cout << "1. Insert Value\n";
        cout << "2. Delete Value\n";
        cout << "3. Merge Arrays\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "RowMajor 1 or ColMajor 2: ";
                cin >> pref;
                rowMajor = (pref == 1);
                colMajor = (pref == 2);

                cout << "Enter insert index (row col): ";
                cin >> row >> col;
                cout << "Enter value: ";
                cin >> val;
                insertVal(matA, r, c, row, col, val, rowMajor, colMajor);
                break;

            case 2:
                cout << "RowMajor 1 or ColMajor 2: ";
                cin >> pref;
                rowMajor = (pref == 1);
                colMajor = (pref == 2);

                cout << "Enter delete index (row col): ";
                cin >> row >> col;
                deleteVal(matA, r, c, row, col, rowMajor, colMajor);
                break;

            case 3:
                cout << "RowMajor 1 or ColMajor 2: ";
                cin >> pref;
                rowMajor = (pref == 1);
                colMajor = (pref == 2);

                mergeMat(matA, matB, matC, r, c, rowMajor, colMajor);
                break;

            case 4:
                cout << "Exit\n";
                break;

            default:
                cout << "Invalid\n";
                break;
        }
    } while(choice != 4);

    return 0;
}
