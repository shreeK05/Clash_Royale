// 25) Write a program to implement Tower of Hanoi using explicit stack.
// Concept used: Simulation of recursive Tower of Hanoi using an explicit stack of frames instead of function calls.

#include <iostream>
using namespace std;

struct Frame {
    int n;
    char from, aux, to;
    int state;
};

void towerOfHanoiIterative(int n, char from, char aux, char to) {
    Frame stack[100];
    int top = -1;
    stack[++top] = {n, from, aux, to, 0};
    while (top >= 0) {
        Frame &f = stack[top];
        if (f.n == 0) {
            top--;
            continue;
        }
        if (f.state == 0) {
            f.state = 1;
            stack[++top] = {f.n - 1, f.from, f.to, f.aux, 0};
        } else if (f.state == 1) {
            cout << "Move disk " << f.n << " from " << f.from << " to " << f.to << endl;
            f.state = 2;
            stack[++top] = {f.n - 1, f.aux, f.from, f.to, 0};
        } else {
            top--;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    towerOfHanoiIterative(n, 'A', 'B', 'C');
    return 0;
}
