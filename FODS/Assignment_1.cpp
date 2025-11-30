#include<iostream>
#include<chrono>
#include<cmath>
using namespace std;
using namespace chrono;

long long countDigits(long long num) {
    if (num == 0) return 0;
    long long cnt = 0;
    while (num > 0) {
        num /= 10;
        cnt++;
    }
    return cnt;
}

long long karatsubaMul(long long num1, long long num2) {
    if (num1 < 10 || num2 < 10) {
        return num1 * num2;
    }

    int n = max(countDigits(num1), countDigits(num2));
    int half = n / 2;

    long long base = 1;
    for (int i = 0; i < half; i++) base *= 10;

    long long high1 = num1 / base;
    long long low1 = num1 % base;
    long long high2 = num2 / base;
    long long low2 = num2 % base;

    long long highProd = karatsubaMul(high1, high2);
    long long lowProd = karatsubaMul(low1, low2);
    long long crossProd = karatsubaMul((high1 + low1), (high2 + low2));

    return highProd * base * base + (crossProd - highProd - lowProd) * base + lowProd;
}


long long gaussMul(long long num1, long long num2) {
    if (num1 < 10 || num2 < 10) {
        return num1 * num2;
    }

    int n = max(countDigits(num1), countDigits(num2));
    int half = n / 2;

    long long base = 1;
    for (int i = 0; i < half; i++) base *= 10;

    long long high1 = num1 / base;
    long long low1 = num1 % base;
    long long high2 = num2 / base;
    long long low2 = num2 % base;

    long long highProd = gaussMul(high1, high2);
    long long lowProd = gaussMul(low1, low2);
    long long mid1 = gaussMul(high1, low2);
    long long mid2 = gaussMul(low1, high2);

    return highProd * base * base + (mid1 + mid2) * base + lowProd;
}

int main() {
    long long num1, num2;
    cout << "Enter Your Values: ";
    cin >> num1 >> num2;

    auto start1 = high_resolution_clock::now();
    long long karatsubaResult = karatsubaMul(num1, num2);
    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    long long gaussResult = gaussMul(num1, num2);
    auto end2 = high_resolution_clock::now();

    cout << "\nKaratsuba Result: " << karatsubaResult;
    cout << "\nTime: " << duration_cast<microseconds>(end1 - start1).count() << " microseconds";

    cout << "\n\nGauss Result: " << gaussResult;
    cout << "\nTime: " << duration_cast<microseconds>(end2 - start2).count() << " microseconds\n";

    return 0;
}
