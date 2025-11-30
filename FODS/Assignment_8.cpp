#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
};

Node* createNode(int c, int p) {
    Node* n = new Node;
    n->coeff = c;
    n->pow = p;
    n->next = NULL;
    return n;
}

void insertTerm(Node*& poly, int c, int p) {
    Node* newNode = createNode(c, p);
    if (!poly || poly->pow < p) {
        newNode->next = poly;
        poly = newNode;
    } else {
        Node* temp = poly;
        while (temp->next && temp->next->pow > p) temp = temp->next;
        if (temp->pow == p) temp->coeff += c;
        else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

Node* addPolynomials(Node* p1, Node* p2) {
    Node* result = NULL;
    while (p1 && p2) {
        if (p1->pow > p2->pow) {
            insertTerm(result, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            insertTerm(result, p2->coeff, p2->pow);
            p2 = p2->next;
        } else {
            insertTerm(result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1) {
        insertTerm(result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2) {
        insertTerm(result, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return result;
}

void display(Node* poly) {
    while (poly) {
        cout << poly->coeff << "x^" << poly->pow;
        if (poly->next) cout << " + ";
        poly = poly->next;
    }
    cout << endl;
}

struct GNode {
    int flag;
    void* data;
    GNode* next;
};

GNode* createAtom(int c, int p) {
    Node* term = createNode(c, p);
    GNode* g = new GNode;
    g->flag = 0;
    g->data = term;
    g->next = NULL;
    return g;
}

GNode* createGList(Node* poly) {
    GNode* head = NULL, *tail = NULL;
    while (poly) {
        GNode* g = createAtom(poly->coeff, poly->pow);
        if (!head) head = tail = g;
        else {
            tail->next = g;
            tail = g;
        }
        poly = poly->next;
    }
    return head;
}

void displayGList(GNode* g) {
    while (g) {
        Node* term = (Node*)g->data;
        cout << term->coeff << "x^" << term->pow;
        if (g->next) cout << " + ";
        g = g->next;
    }
    cout << endl;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    insertTerm(poly1, 5, 2);
    insertTerm(poly1, 4, 1);
    insertTerm(poly1, 2, 0);

    insertTerm(poly2, 5, 1);
    insertTerm(poly2, 5, 0);

    cout << "Polynomial 1: ";
    display(poly1);
    cout << "Polynomial 2: ";
    display(poly2);

    Node* result = addPolynomials(poly1, poly2);
    cout << "Sum: ";
    display(result);

    cout << "Generalized Linked List Representation: ";
    GNode* gll = createGList(result);
    displayGList(gll);

    return 0;
}
