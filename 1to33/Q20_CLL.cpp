// 20) Write a program to implement a Circular Linked List (CLL). Your program should include the following operations: Insert a node at the beginning and at the end, delete a node from the beginning and from the end, Traverse and display all elements of the circular list, Search for an element in the circular list.
// Concept used: Singly circular linked list where last node points back to head for circular traversal.

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

class CircularLinkedList {
private:
    Node* last;   

public:
    CircularLinkedList() {
        last = NULL;
    }

    void insertBegin(int val) {
        Node* n = new Node(val);

        if (last == NULL) {  
            last = n;
            last->next = last;
        } else {
            n->next = last->next;
            last->next = n;
        }
    }

    void insertEnd(int val) {
        Node* n = new Node(val);

        if (last == NULL) {
            last = n;
            last->next = last;
        } else {
            n->next = last->next;  
            last->next = n;
            last = n;
        }
    }

    void deleteBegin() {
        if (last == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* head = last->next;

        if (head == last) {
            delete head;
            last = NULL;
        } else {
            last->next = head->next;
            delete head;
        }
    }

    void deleteEnd() {
        if (last == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* head = last->next;

        if (head == last) {
            delete last;
            last = NULL;
            return;
        }

        Node* temp = head;

        while (temp->next != last)
            temp = temp->next;

        temp->next = last->next;
        delete last;
        last = temp;
    }

    void display() {
        if (last == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = last->next;
        cout << "Circular List: ";

        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != last->next);

        cout << "(back to head)\n";
    }

    void search(int key) {
        if (last == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = last->next;
        int pos = 1;

        do {
            if (temp->data == key) {
                cout << "Element found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != last->next);

        cout << "Element not found!\n";
    }
};

int main() {
    CircularLinkedList cll;
    int choice, val;

    do {
        cout << "\n--- CIRCULAR LINKED LIST MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete at Beginning\n";
        cout << "4. Delete at End\n";
        cout << "5. Display List\n";
        cout << "6. Search Element\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                cll.insertBegin(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                cll.insertEnd(val);
                break;

            case 3:
                cll.deleteBegin();
                break;

            case 4:
                cll.deleteEnd();
                break;

            case 5:
                cll.display();
                break;

            case 6:
                cout << "Enter value to search: ";
                cin >> val;
                cll.search(val);
                break;

            case 7:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}
