// 32) Write a program to implement a Double-Ended Queue (Deque). Allow insertion and deletion at both front and rear. Implement the following operations: Insert Front, Insert Rear, Delete Front, Delete Rear, Display.
// Concept used: Circular array-based deque with front and rear indices supporting insert/delete at both ends.

#include <iostream>
using namespace std;

class Deque {
private:
    int arr[100];
    int front, rear, size;

public:
    Deque(int s = 100) {
        size = s;
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) || (front == rear + 1));
    }

    void insertFront(int x) {
        if (isFull()) {
            cout << "Deque Overflow!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }
        arr[front] = x;
        cout << "Inserted at front: " << x << endl;
    }

    void insertRear(int x) {
        if (isFull()) {
            cout << "Deque Overflow!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
        cout << "Inserted at rear: " << x << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow!\n";
            return;
        }
        cout << "Deleted from front: " << arr[front] << endl;

        if (front == rear) { 
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    // Delete from rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow!\n";
            return;
        }
        cout << "Deleted from rear: " << arr[rear] << endl;

        if (front == rear) { 
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }
    }

    // Display deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return;
        }
        cout << "Deque elements: ";
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
    Deque dq(10);
    int choice, value;

    do {
        cout << "\n--- DEQUE MENU ---\n";
        cout << "1. Insert Front\n";
        cout << "2. Insert Rear\n";
        cout << "3. Delete Front\n";
        cout << "4. Delete Rear\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dq.insertFront(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                dq.insertRear(value);
                break;

            case 3:
                dq.deleteFront();
                break;

            case 4:
                dq.deleteRear();
                break;

            case 5:
                dq.display();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
