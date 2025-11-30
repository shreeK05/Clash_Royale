// 33) Write a program to simulate a Queue-based system such as: Printer Spooling, Ticket Counter, Traffic Management, use a queue to model real-world waiting-line behaviour and display how requests are processed in order.
// Concept used: Array-based FIFO queue to simulate a printer job queue where jobs are enqueued and processed in order.

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string jobName;
    Node* next;

    Node(string name) {
        jobName = name;
        next = NULL;
    }
};

class PrinterQueue {
private:
    Node* front;
    Node* rear;

public:
    PrinterQueue() {
        front = rear = NULL;
    }

    void addJob(string job) {
        Node* n = new Node(job);

        if (rear == NULL) {
            front = rear = n;
        } else {
            rear->next = n;
            rear = n;
        }
        cout << "Print job added: " << job << endl;
    }

    void processJob() {
        if (front == NULL) {
            cout << "No print jobs pending.\n";
            return;
        }

        cout << "Processing print job: " << front->jobName << endl;

        Node* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    void displayJobs() {
        if (front == NULL) {
            cout << "No jobs in the queue.\n";
            return;
        }

        cout << "Pending print jobs:\n";
        Node* temp = front;

        while (temp != NULL) {
            cout << " - " << temp->jobName << endl;
            temp = temp->next;
        }
    }
};

int main() {
    PrinterQueue pq;
    int choice;
    string name;

    do {
        cout << "\n--- PRINTER SPOOLING SYSTEM ---\n";
        cout << "1. Add Print Job\n";
        cout << "2. Process Next Job\n";
        cout << "3. Show Pending Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter job name: ";
                getline(cin, name);
                pq.addJob(name);
                break;

            case 2:
                pq.processJob();
                break;

            case 3:
                pq.displayJobs();
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
