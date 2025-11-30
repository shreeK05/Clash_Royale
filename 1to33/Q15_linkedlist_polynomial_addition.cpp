// 15) Write a program to perform addition of polynomials using singly linked list.
// Concept used: Singly linked list where each node stores coefficient and exponent, merged by exponent for addition.

#include <iostream>
using namespace std;

class Node {
public:
    int coeff;
    int exp;
    Node* next;

    Node(int c, int e) {
        coeff = c;
        exp = e;
        next = NULL;
    }
};

class Polynomial {
public:
    Node* head;

    Polynomial() {
        head = NULL;
    }

    void insertTerm(int c, int e) {
        Node* temp = new Node(c, e);

        if (head == NULL) {
            head = temp;
            return;
        }

        Node* p = head;
        while (p->next != NULL)
            p = p->next;

        p->next = temp;
    }

    void readPoly() {
        int n, c, e;
        cout << "Enter number of terms: ";
        cin >> n;

        cout << "Enter coefficient and exponent (descending order):\n";
        for (int i = 0; i < n; i++) {
            cin >> c >> e;
            insertTerm(c, e);
        }
    }

    void printPoly() {
        if (head == NULL) {
            cout << "0\n";
            return;
        }

        Node* p = head;
        while (p != NULL) {
            cout << p->coeff << "x^" << p->exp;
            if (p->next != NULL) cout << " + ";
            p = p->next;
        }
        cout << endl;
    }

    Polynomial add(Polynomial &P2) {
        Polynomial result;
        Node *p1 = this->head;
        Node *p2 = P2.head;

        while (p1 != NULL && p2 != NULL) {
            if (p1->exp > p2->exp) {
                result.insertTerm(p1->coeff, p1->exp);
                p1 = p1->next;
            }
            else if (p2->exp > p1->exp) {
                result.insertTerm(p2->coeff, p2->exp);
                p2 = p2->next;
            }
            else {  
                int sumCoeff = p1->coeff + p2->coeff;
                if (sumCoeff != 0)
                    result.insertTerm(sumCoeff, p1->exp);

                p1 = p1->next;
                p2 = p2->next;
            }
        }

        while (p1 != NULL) {
            result.insertTerm(p1->coeff, p1->exp);
            p1 = p1->next;
        }
        while (p2 != NULL) {
            result.insertTerm(p2->coeff, p2->exp);
            p2 = p2->next;
        }

        return result;
    }
};

int main() {
    Polynomial P1, P2;

    cout << "Polynomial 1:\n";
    P1.readPoly();

    cout << "Polynomial 2:\n";
    P2.readPoly();

    cout << "\nP1(x) = ";
    P1.printPoly();

    cout << "P2(x) = ";
    P2.printPoly();

    Polynomial Sum = P1.add(P2);

    cout << "\nP1(x) + P2(x) = ";
    Sum.printPoly();

    return 0;
}

