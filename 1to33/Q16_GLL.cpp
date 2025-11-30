// 16) Write a program to implement Generalized Linked List (GLL).
// Concept used: Node with two pointers (next and down) to represent hierarchical list (list of lists) and recursive display.

#include <iostream>
using namespace std;

struct GNode {
    bool isAtom;    
    int data;
    GNode *next;
    GNode *down;
};

GNode* atom(int val) {
    GNode *n = new GNode;
    n->isAtom = true;
    n->data = val;
    n->next = NULL;
    n->down = NULL;
    return n;
}

GNode* sublist(GNode* head) {
    GNode *n = new GNode;
    n->isAtom = false;
    n->next = NULL;
    n->down = head;
    return n;
}

void printGLL(GNode *head) {
    cout << "(";
    while (head != NULL) {
        if (head->isAtom)
            cout << head->data;
        else
            printGLL(head->down);

        if (head->next != NULL) cout << ", ";
        head = head->next;
    }
    cout << ")";
}

int main() {
   

    GNode *a1 = atom(1);
    GNode *a2 = atom(2);
    GNode *a3 = atom(3);

    a1->next = a2;
    a2->next = a3;

    GNode *b1 = atom(4);
    GNode *b2 = atom(5);
    b1->next = b2;

    GNode *sub = sublist(b1);

    GNode *a4 = atom(6);

    a3->next = sub;
    sub->next = a4;

    cout << "Generalized Linked List:\n";
    printGLL(a1);

    return 0;
}
