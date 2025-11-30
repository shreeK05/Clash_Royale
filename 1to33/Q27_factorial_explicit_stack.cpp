// 27) Write a program to implement Factorial using explicit stack.
// Concept used: Simulation of recursive factorial using a manually managed stack of pending multiplications.

#include <iostream>
using namespace std;

long long factorialStack(int n) {
    int stack[100];
    int top = -1;
    while (n > 1) {
        stack[++top] = n;
        n--;
    }
    long long result = 1;
    while (top >= 0) {
        result *= stack[top--];
    }
    return result;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    long long fact = factorialStack(n);
    cout << "Factorial of " << n << " = " << fact << endl;
    return 0;
}
