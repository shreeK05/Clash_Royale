#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void countNotes(int amount) {
    int notes[10] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < 10; i++) {
        if (amount == 0) break;

        if (amount >= notes[i]) {
            cout << notes[i] << " X " << amount / notes[i] << endl;
            amount = amount % notes[i];
        }
    }
}

int main() {
    int amount;
    cout << "Enter amount : ";
    cin >> amount;

    auto start = high_resolution_clock::now();
    countNotes(amount);
    auto end = high_resolution_clock::now(); 
    auto elapsed = duration_cast<microseconds>(end - start);

    cout << "Time taken: " << elapsed.count() << " microseconds" << endl;

    return 0;
}
