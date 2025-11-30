// 24) Write a program to implement Tower of Hanoi using Recursion.
// Concept used: Recursive divide and conquer to move n disks from one peg to another using an auxiliary peg.

#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from, char aux, char to) {
    if (n == 0) return;
    towerOfHanoi(n - 1, from, to, aux);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    towerOfHanoi(n - 1, aux, from, to);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
