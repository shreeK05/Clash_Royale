#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node* next;
    Node(string s) {
        song = s;
        next = NULL;
    }
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() { head = NULL; }

    void addSong(string s) {
        Node* newNode = new Node(s);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void deleteSong(string s) {
        if (!head) return;
        if (head->song == s) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->song != s) temp = temp->next;
        if (temp->next) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }

    void searchSong(string s) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->song == s) {
                cout << s << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << s << " not found." << endl;
    }

    void traverse() {
        Node* temp = head;
        cout << "Singly Playlist: ";
        while (temp) {
            cout << temp->song << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

class DNode {
public:
    string song;
    DNode *next, *prev;
    DNode(string s) {
        song = s;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() { head = NULL; }

    void addSong(string s) {
        DNode* newNode = new DNode(s);
        if (!head) { head = newNode; return; }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteSong(string s) {
        if (!head) return;
        DNode* temp = head;
        while (temp && temp->song != s) temp = temp->next;
        if (!temp) return;
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
    }

    void traverseForward() {
        DNode* temp = head;
        cout << "Doubly Playlist Forward: ";
        while (temp) {
            cout << temp->song << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void traverseBackward() {
        DNode* temp = head;
        if (!temp) return;
        while (temp->next) temp = temp->next;
        cout << "Doubly Playlist Backward: ";
        while (temp) {
            cout << temp->song << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

class CNode {
public:
    string song;
    CNode* next;
    CNode(string s) {
        song = s;
        next = NULL;
    }
};

class CircularLinkedList {
    CNode* tail;
public:
    CircularLinkedList() { tail = NULL; }

    void addSong(string s) {
        CNode* newNode = new CNode(s);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    void deleteSong(string s) {
        if (!tail) return;
        CNode *curr = tail->next, *prev = tail;
        do {
            if (curr->song == s) {
                if (curr == tail && curr->next == tail) { delete curr; tail = NULL; return; }
                if (curr == tail) tail = prev;
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);
    }

    void traverse() {
        if (!tail) { cout << "Circular Playlist Empty\n"; return; }
        CNode* temp = tail->next;
        cout << "Circular Playlist: ";
        do {
            cout << temp->song << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(back to start)\n";
    }
};

class DCNode {
public:
    string song;
    DCNode *next, *prev;
    DCNode(string s) {
        song = s;
        next = prev = NULL;
    }
};

class DoublyCircularLinkedList {
    DCNode* head;
public:
    DoublyCircularLinkedList() { head = NULL; }

    void addSong(string s) {
        DCNode* newNode = new DCNode(s);
        if (!head) {
            head = newNode;
            head->next = head->prev = head;
            return;
        }
        DCNode* last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }

    void traverseForward() {
        if (!head) { cout << "Doubly Circular Playlist Empty\n"; return; }
        DCNode* temp = head;
        cout << "Doubly Circular Playlist Forward: ";
        do {
            cout << temp->song << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to start)\n";
    }

    void traverseBackward() {
        if (!head) return;
        DCNode* temp = head->prev;
        cout << "Doubly Circular Playlist Backward: ";
        do {
            cout << temp->song << " <-> ";
            temp = temp->prev;
        } while (temp != head->prev);
        cout << "(back to end)\n";
    }
};

int main() {
    cout << " Playlist Simulation Using Various Linked Lists \n";

    SinglyLinkedList sList;
    sList.addSong("Song A");
    sList.addSong("Song B");
    sList.addSong("Song C");
    sList.traverse();
    sList.searchSong("Song B");
    sList.deleteSong("Song A");
    sList.traverse();
    cout << endl;
  

    DoublyLinkedList dList;
    dList.addSong("Track 1");
    dList.addSong("Track 2");
    dList.addSong("Track 3");
    dList.traverseForward();
    dList.traverseBackward();
    cout << endl;

    CircularLinkedList cList;
    cList.addSong("Loop A");
    cList.addSong("Loop B");
    cList.addSong("Loop C");
    cList.traverse();
    cList.deleteSong("Loop B");
    cList.traverse();
    cout << endl;

    
    DoublyCircularLinkedList dcList;
    dcList.addSong("Play X");
    dcList.addSong("Play Y");
    dcList.addSong("Play Z");
    dcList.traverseForward();
    dcList.traverseBackward();

    return 0;
}
