#include <iostream>
#include <stack>
using namespace std;

int factorialRecursive(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorialRecursive(n - 1);
}

int factorialStack(int n) {
    stack<int> st;
    int result = 1;

    // Push all numbers onto stack
    for (int i = n; i > 1; i--) {
        st.push(i);
    }

    // Pop one by one and multiply
    while (!st.empty()) {
        result *= st.top();
        st.pop();
    }

    return result;
}

void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " -> " << to << endl;
        return;
    }

    towerOfHanoi(n - 1, from, aux, to); // Move smaller disks to helper
    cout << "Move disk " << n << " from " << from << " -> " << to << endl;
    towerOfHanoi(n - 1, aux, to, from); // Move smaller disks to target
}


int main() {
    int n = 5;
    cout << "Factorial using recursion: " << factorialRecursive(n) << endl;
    cout<<endl;
        
    cout << "Factorial using explicit stack: " << factorialStack(n) << endl;
    cout<<endl;

    int m = 3;
    towerOfHanoi(m, 'A', 'C', 'B');
    return 0;
}
