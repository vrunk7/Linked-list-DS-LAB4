
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node
{
    char song[100];
    node *next;
};

struct node *head = NULL, *p, *q;

class Playlist
{
public:

    void addSong()
    {
        p = (struct node *)malloc(sizeof(struct node));

        cout << "Enter song name: ";
        cin.ignore();
        cin.getline(p->song, 100);

        p->next = NULL;

        if (head == NULL)
        {
            head = p;
        }
        else
        {
            q = head;

            while (q->next != NULL)
            {
                q = q->next;
            }

            q->next = p;
        }

        cout << "Song added successfully";
    }

    void deleteSong()
    {
        char name[100];

        if (head == NULL)
        {
            cout << "Playlist is empty";
            return;
        }

        cout << "Enter song name to delete: ";
        cin.ignore();
        cin.getline(name, 100);

        q = head;
        p = NULL;

        while (q != NULL && strcmp(q->song, name) != 0)
        {
            p = q;
            q = q->next;
        }

        if (q == NULL)
        {
            cout << "Song not found";
            return;
        }

        if (q == head)
        {
            head = head->next;
        }
        else
        {
            p->next = q->next;
        }

        free(q);

        cout << "Song deleted successfully";
    }

    void searchSong()
    {
        char name[100];
        int flag = 0, pos = 1;

        if (head == NULL)
        {
            cout << "Playlist is empty";
            return;
        }

        cout << "Enter song name to search: ";
        cin.ignore();
        cin.getline(name, 100);

        q = head;

        while (q != NULL)
        {
            if (strcmp(q->song, name) == 0)
            {
                cout << "Song found at position " << pos;
                flag = 1;
                break;
            }

            q = q->next;
            pos++;
        }

        if (flag == 0)
        {
            cout << "Song not found";
        }
    }

    void displayPlaylist()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty";
            return;
        }

        q = head;

        cout << "\n----- MUSIC PLAYLIST -----\n";

        while (q != NULL)
        {
            cout << q->song << endl;
            q = q->next;
        }
    }

    void playNext()
    {
        static node *current = NULL;

        if (head == NULL)
        {
            cout << "Playlist is empty";
            current = NULL;
            return;
        }

        if (current == NULL)
        {
            current = head;
        }
        else
        {
            current = current->next;

            if (current == NULL)
            {
                current = head;
            }
        }

        cout << "Now playing: " << current->song;
    }
};

int main()
{
    Playlist obj;
    int choice;

    do
    {
        cout << "\n\n----- MUSIC PLAYLIST MANAGER -----";
        cout << "\n1. Add Song";
        cout << "\n2. Delete Song";
        cout << "\n3. Search Song";
        cout << "\n4. Display Playlist";
        cout << "\n5. Play Next Song";
        cout << "\n6. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                obj.addSong();
                break;

            case 2:
                obj.deleteSong();
                break;

            case 3:
                obj.searchSong();
                break;

            case 4:
                obj.displayPlaylist();
                break;

            case 5:
                obj.playNext();
                break;

            case 6:
                cout << "Exiting Playlist Manager";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 6);

    return 0;
}