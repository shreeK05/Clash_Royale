#include<iostream>
using namespace std;

int recursiveCalls = 0;
int multiplicationCalls = 0;
int additionCalls = 0;

long long gaussMulti(long long a, long long b) {
    recursiveCalls++;

    if (a < 10 && b < 10) {
        multiplicationCalls++;
        return a * b;
    }

    int s = a + b;
    int d = a - b;
    additionCalls += 2;

    int s2 = s * s;
    int d2 = d * d;
    multiplicationCalls += 2;

    int num = s2 - d2;
    additionCalls++;

    return num / 4;
}

int main() {
    long long a, b;
    cout << "Enter 2 numbers = ";
    cin >> a >> b;

    long long result = gaussMulti(a, b);

    cout << "Recursive Calls = " << recursiveCalls << endl;
    cout << "Multiplication Calls = " << multiplicationCalls << endl;
    cout << "Addition/Sub Calls = " << additionCalls << endl;

    cout << "Final result of " << a << " * " << b << " = " << result << endl;

    return 0;
}