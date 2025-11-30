#include <iostream>
using namespace std;

int recursiveCalls = 0;
int multiplicationCalls = 0;
int additionCalls = 0;

long long numLength(long long n) {
    int len;
    if (n == 0) {
        return 1;
    }
    len = 0;
    while (n > 0) {
        len++;
        n /= 10;
    }
    return len;
}

long long power10(int m) {
    long long res = 1;
    while (m-- > 0){
        res *= 10;
    } 
    return res;
}

long long karastuba(long long x, long long y){
    recursiveCalls++;

    if (x < 10 || y < 10) {
        multiplicationCalls++;
        return x * y;
    }

    int n=max(numLength(x), numLength(y));
    int m=n/2;

    long long pow10m=power10(m);

    long long a = x / pow10m;
    long long b = x % pow10m;
    long long c = y / pow10m;
    long long d = y % pow10m;

    long long p1 = karastuba(a, c);
    long long p2 = karastuba(b, d);
    long long p3 = karastuba(a + b, c + d);
    additionCalls += 4; // for a+b, c+d, p3 - p1 - p2, and final additions

    long long mid = p3 - p1 - p2;
    additionCalls += 2; // for p3 - p1 - p2

    long long result = p1 * power10(2 * m) + mid * pow10m + p2;
    return result;  
}

int main() {
    long long x, y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;

    long long result = karastuba(x, y);

    cout << "Karastuba result = " << result << endl;
    cout << "Recursive calls = " << recursiveCalls << endl;
    cout << "Multiplications (base case) = " << multiplicationCalls << endl;
    cout << "Additions/Subtractions = " << additionCalls << endl;

    return 0;
}