// 18) Write a program to implement a linked-list-based Music Playlist Manager. Your program should allow users to: Add a new song, delete a song, move to the next or previous song, Display the current playlist. Explain why a linked list is better than an array for this application (dynamic size, fast insert/delete).
// Concept used: Doubly linked list representing playlist with a current pointer for navigation.

#include <iostream>
#include <string>
using namespace std;

class Song {
public:
    string name;
    Song *next;
    Song *prev;

    Song(string n) {
        name = n;
        next = prev = NULL;
    }
};

class Playlist {
private:
    Song *head;
    Song *tail;
    Song *current;

public:
    Playlist() {
        head = tail = current = NULL;
    }

    void addSong(string name) {
        Song *s = new Song(name);

        if (head == NULL) {
            head = tail = current = s;
        } else {
            tail->next = s;
            s->prev = tail;
            tail = s;
        }

        cout << "Song added.\n";
    }

    void deleteSong(string name) {
        Song *p = head;

        while (p != NULL) {
            if (p->name == name) {

                if (p->prev) p->prev->next = p->next;
                else head = p->next;

                if (p->next) p->next->prev = p->prev;
                else tail = p->prev;

                if (current == p) current = head;

                delete p;
                cout << "Song deleted.\n";
                return;
            }
            p = p->next;
        }
        cout << "Song not found.\n";
    }

    void nextSong() {
        if (current && current->next)
            current = current->next;
        else
            cout << "No next song.\n";
    }

    void previousSong() {
        if (current && current->prev)
            current = current->prev;
        else
            cout << "No previous song.\n";
    }

    void displayPlaylist() {
        cout << "Playlist: ";
        Song *p = head;

        if (!p) {
            cout << "Empty\n";
            return;
        }

        while (p != NULL) {
            cout << "[" << p->name << "] ";
            p = p->next;
        }
        cout << endl;
    }

    void showCurrent() {
        if (current)
            cout << "Current song: " << current->name << endl;
        else
            cout << "No songs in playlist.\n";
    }
};

int main() {
    Playlist p;
    int choice;
    string name;

    do {
        cout << "\n--- Music Playlist Menu ---\n";
        cout << "1. Add new song\n";
        cout << "2. Delete song\n";
        cout << "3. Next song\n";
        cout << "4. Previous song\n";
        cout << "5. Display playlist\n";
        cout << "6. Show current song\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                cout << "Enter song name: ";
                getline(cin, name);
                p.addSong(name);
                break;

            case 2:
                cout << "Enter song name to delete: ";
                getline(cin, name);
                p.deleteSong(name);
                break;

            case 3:
                p.nextSong();
                break;

            case 4:
                p.previousSong();
                break;

            case 5:
                p.displayPlaylist();
                break;

            case 6:
                p.showCurrent();
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
