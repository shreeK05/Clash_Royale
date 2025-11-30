//30)	Write a program to implement a Queue using a singly linked list. Implement the following functions: Enqueue, Dequeue, Display Explain how a linked list avoids overflow issues seen in array implementation.
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int val) {
        Node* n = new Node(val);

        if (!n) {
            cout << "Memory allocation failed! Cannot insert.\n";
            return;
        }

        if (rear == NULL) {
            front = rear = n;
        } else {
            rear->next = n;
            rear = n;
        }

        cout << "Inserted " << val << endl;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow! No element to delete.\n";
            return;
        }

        Node* temp = front;
        cout << "Deleted " << front->data << endl;

        front = front->next;

        if (front == NULL)  
            rear = NULL;

        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, val;

    do {
        cout << "\n--- QUEUE USING LINKED LIST ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                q.enqueue(val);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
