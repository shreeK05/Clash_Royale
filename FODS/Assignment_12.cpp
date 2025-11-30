#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear == SIZE - 1);
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void push(int value){
        if(isFull()){
            cout << "Queue is full cannot insert " << value << endl;
            return;
        }

        if (front == -1){
            front = 0;  
        }

        rear++;
        arr[rear] = value;
        cout << value << " inserted into the queue." << endl;
    }

    void pop(){
        if (isEmpty()){
            cout << "Queue Underflow! No element to remove." << endl;
            return;
        }

        cout << arr[front] << " removed from the queue." << endl;
        front++;

        if (front > rear) {
            front = rear = -1;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } 
        
        else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.display();
    
    q.pop();
    q.display();

    q.peek();

    q.push(40);
    q.push(50);
    q.push(60);

    q.display();

    return 0;
}
