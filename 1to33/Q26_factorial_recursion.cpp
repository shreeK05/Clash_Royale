// 26) Write a program to implement Factorial using Recursion.
// Concept used: Simple recursive definition n! = n * (n-1)! with base case 0! = 1.

#include <iostream>
using namespace std;

long long factorialRec(int n) {
    if (n <= 1) return 1;
    return n * factorialRec(n - 1);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    long long fact = factorialRec(n);
    cout << "Factorial of " << n << " = " << fact << endl;
    return 0;
}
