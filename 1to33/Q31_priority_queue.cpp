//31)	Write a program to implement a Priority Queue where each element has a priority value.
//The program should always delete the element with the highest or lowest priority (based on your choice). Support insert, delete, and display operations.

#include <iostream>
using namespace std;

class Node {
public:
    int data, priority;
    Node* next;

    Node(int val, int pri) {
        data = val;
        priority = pri;
        next = NULL;
    }
};

class PriorityQueue {
private:
    Node* head;  

public:
    PriorityQueue() {
        head = NULL;
    }

    void insert(int value, int pri) {
        Node* n = new Node(value, pri);


        if (head == NULL || pri > head->priority) {
            n->next = head;
            head = n;
            cout << "Inserted " << value << " with priority " << pri << endl;
            return;
        }

        Node* temp = head;
 
        while (temp->next != NULL && temp->next->priority >= pri) {
            temp = temp->next;
        }

        n->next = temp->next;
        temp->next = n;

        cout << "Inserted " << value << " with priority " << pri << endl;
    }

    void deleteHighest() {
        if (head == NULL) {
            cout << "Priority Queue is empty!\n";
            return;
        }

        Node* temp = head;
        cout << "Deleted element " << head->data
             << " with priority " << head->priority << endl;

        head = head->next;
        delete temp;
    }

    void display() {
        if (head == NULL) {
            cout << "Priority Queue is empty!\n";
            return;
        }

        cout << "Priority Queue (value:priority): ";
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << ":" << temp->priority << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    int choice, value, pri;

    do {
        cout << "\n--- PRIORITY QUEUE MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete Highest Priority\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter priority (higher number = higher priority): ";
                cin >> pri;
                pq.insert(value, pri);
                break;

            case 2:
                pq.deleteHighest();
                break;

            case 3:
                pq.display();
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

