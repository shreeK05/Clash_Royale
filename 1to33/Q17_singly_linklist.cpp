// 17) Write a program to implement a singly linked list and perform the following operations: Insert a node at the beginning, end, and at a specific position, delete a node from the beginning, end, and a specific position, Search for an element in the linked list, Display the linked list.
// Concept used: Singly linked list with basic insertion, deletion, search, and traversal operations.

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

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertBegin(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    void insertEnd(int val) {
        Node* n = new Node(val);

        if (head == NULL) {
            head = n;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = n;
    }

    void insertPos(int val, int pos) {
        if (pos == 1) {
            insertBegin(val);
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != NULL && i < pos - 1; i++)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Invalid Position!\n";
            return;
        }

        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }

    void deleteBegin() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }

    void deletePos(int pos) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        if (pos == 1) {
            deleteBegin();
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != NULL && i < pos - 1; i++)
            temp = temp->next;

        if (temp == NULL || temp->next == NULL) {
            cout << "Invalid Position!\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void search(int key) {
        Node* temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Element found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }

        cout << "Element not found!\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList obj;
    int choice, val, pos;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                obj.insertBegin(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                obj.insertEnd(val);
                break;

            case 3:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                obj.insertPos(val, pos);
                break;

            case 4:
                obj.deleteBegin();
                break;

            case 5:
                obj.deleteEnd();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                obj.deletePos(pos);
                break;

            case 7:
                cout << "Enter value to search: ";
                cin >> val;
                obj.search(val);
                break;

            case 8:
                obj.display();
                break;

            case 9:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 9);

    return 0;
}
