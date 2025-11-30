// 3) Write a program to implement a greedy algorithm to solve a real-world optimization problem, such as minimizing currency notes in a digital wallet (coin change). Write the logic using pseudo-code and a flowchart. Analyse the algorithm's time complexity (Best, Average, Worst Case) using Big-O, Θ, and Ω notations.
// Concept used: Greedy choice strategy picking the largest denomination first.

#include <iostream>
using namespace std;

void cashCount(int amount){
    int notes[10]= {2000,500,200,100,50,20,10,5,2,1};
    for(int i=0;i<10;i++){
        if(amount==0) break;
        if(amount>=notes[i]){
            int cnt= amount/notes[i];
            cout<<notes[i]<<" X "<<cnt<<endl;
            amount= amount%notes[i];
        }
    }
}

int main() {
    int amount;
    cout << "Enter amount: ";
    cin >> amount;
    cout << "Minimum notes/coins using greedy algorithm:" << endl;
    cashCount(amount);
    return 0;
}
