// 4) Write a program to implement a greedy algorithm to solve a real-world optimization problem, such as maximizing non-overlapping events in a scheduler (activity selection). Represent the logic using pseudo-code and a flowchart. Analyse the algorithm's time complexity (Best, Average, Worst Case) using Big-O, Θ, and Ω notations.
// Concept used: Greedy activity selection based on earliest finishing time.

#include <iostream>
using namespace std;

void selectActivities(int start[], int finish[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (finish[j] > finish[j + 1]) {
                int temp = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = temp;
                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
            }
        }
    }
    cout << "Selected activities (start, finish):" << endl;
    int last = 0;
    cout << start[0] << " " << finish[0] << endl;
    for (int i = 1; i < n; i++) {
        if (start[i] >= finish[last]) {
            cout << start[i] << " " << finish[i] << endl;
            last = i;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
    int start[100], finish[100];
    cout << "Enter start and finish times:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> start[i] >> finish[i];
    }
    selectActivities(start, finish, n);
    return 0;
}
