// 19) Write a program to implement a Doubly Linked List (DLL). Your program should support the following operations: Insert a node at the beginning, at the end, and at any given position, delete a node from the beginning, from the end, and from any given position, display the list in forward and reverse order, search for an element in the list. Also analyse how DLL helps in easier forward–backward navigation compared to a singly linked list.
// Concept used: Doubly linked list with bidirectional traversal and position-based insertion/deletion.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = tail = NULL;
    }

    void insertBegin(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = tail = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
    }

    void insertEnd(int val) {
        Node* n = new Node(val);
        if (!tail) {
            head = tail = n;
            return;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    void insertPos(int val, int pos) {
        if (pos == 1) {
            insertBegin(val);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (!temp) {
            cout << "Invalid Position!\n";
            return;
        }

        if (temp == tail) {
            insertEnd(val);
            return;
        }

        Node* n = new Node(val);
        n->next = temp->next;
        n->prev = temp;
        temp->next->prev = n;
        temp->next = n;
    }

    void deleteBegin() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteEnd() {
        if (!tail) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete temp;
    }

    void deletePos(int pos) {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        if (pos == 1) {
            deleteBegin();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos && temp != NULL; i++)
            temp = temp->next;

        if (!temp) {
            cout << "Invalid Position!\n";
            return;
        }

        if (temp == tail) {
            deleteEnd();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
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
        cout << "Element not found.\n";
    }

    void displayForward() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        cout << "Forward: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void displayBackward() {
        if (!tail) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = tail;
        cout << "Backward: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, val, pos;

    do {
        cout << "\n--- DOUBLY LINKED LIST MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Display Forward\n";
        cout << "8. Display Backward\n";
        cout << "9. Search\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                dll.insertBegin(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                dll.insertEnd(val);
                break;

            case 3:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                dll.insertPos(val, pos);
                break;

            case 4:
                dll.deleteBegin();
                break;

            case 5:
                dll.deleteEnd();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                dll.deletePos(pos);
                break;

            case 7:
                dll.displayForward();
                break;

            case 8:
                dll.displayBackward();
                break;

            case 9:
                cout << "Enter value to search: ";
                cin >> val;
                dll.search(val);
                break;

            case 10:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 10);

    return 0;
}
