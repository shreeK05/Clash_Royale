// 29) Write a program to implement a Circular Queue using an array and perform the operations: Enqueue, Dequeue, Peek, Display, compare how Circular Queue avoids the limitations of Linear Queue.
// Concept used: Circular array-based queue using modulo arithmetic for front and rear to reuse freed space.

#include <iostream>
using namespace std;

class CircularQueue {
private:
    int arr[100];
    int front, rear, size;

public:
    CircularQueue(int s) {
        size = s;
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if ((front == 0 && rear == size - 1) || (rear + 1) % size == front) {
            cout << "Queue Overflow! Cannot insert.\n";
            return;
        }

        if (front == -1) {    
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = x;
        cout << "Inserted " << x << endl;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow! Cannot delete.\n";
            return;
        }

        cout << "Deleted " << arr[front] << endl;

        if (front == rear) {
           
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void peek() {
        if (front == -1) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Front element = " << arr[front] << endl;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Circular Queue elements: ";
        int i = front;

        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter size of circular queue: ";
    cin >> n;

    CircularQueue cq(n);

    int choice, val;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek (Front)\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                cq.enqueue(val);
                break;

            case 2:
                cq.dequeue();
                break;

            case 3:
                cq.peek();
                break;

            case 4:
                cq.display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
