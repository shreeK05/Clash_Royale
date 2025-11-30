//28)	Write a program to implement a Linear Queue using an array.
//The program should support the following operations: Enqueue (Insert element), Dequeue (Delete element), Peek (Display front element), Display (Show all elements in the queue), Also, handle overflow and underflow conditions properly.


#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int front, rear, size;

public:
    Queue(int s = 100) {
        size = s;
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == size - 1) {
            cout << "Queue Overflow!\n";
            return;
        }

        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else {
            rear++;
        }

        arr[rear] = x;
        cout << "Inserted: " << x << endl;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow!\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;
        front++;

        if (front > rear)
            front = rear = -1;
    }

    void peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n----- LINEAR QUEUE MENU -----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
