
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node
{
    char url[200];
    node *prev;
    node *next;
};

struct node *head = NULL, *tail = NULL;
struct node *current = NULL;
struct node *p, *q;

class Browser
{
public:
    void visitPage()
    {
        p = (struct node *)malloc(sizeof(struct node));

        cout << "Enter webpage URL: ";
        cin.ignore();
        cin.getline(p->url, 200);

        p->prev = NULL;
        p->next = NULL;

        if (head == NULL)
        {
            head = p;
            tail = p;
            current = p;
        }
        else
        {
            // Delete forward history
            q = current->next;

            while (q != NULL)
            {
                struct node *temp = q;
                q = q->next;
                free(temp);
            }

            current->next = NULL;
            tail = current;

            // Insert new webpage
            p->prev = current;
            current->next = p;

            tail = p;
            current = p;
        }

        cout << "Webpage visited successfully";
    }

    void goBack()
    {
        if (current == NULL)
        {
            cout << "No webpage in history";
            return;
        }

        if (current->prev == NULL)
        {
            cout << "No previous webpage available";
            return;
        }

        current = current->prev;

        cout << "Moved backward successfully";
        cout << "\nCurrent webpage: " << current->url;
    }

    void goForward()
    {
        if (current == NULL)
        {
            cout << "No webpage in history";
            return;
        }

        if (current->next == NULL)
        {
            cout << "No forward webpage available";
            return;
        }

        current = current->next;

        cout << "Moved forward successfully";
        cout << "\nCurrent webpage: " << current->url;
    }

    void displayCurrent()
    {
        if (current == NULL)
        {
            cout << "No webpage currently open";
            return;
        }

        cout << "Current webpage: " << current->url;
    }

    void displayHistory()
    {
        if (head == NULL)
        {
            cout << "Browser history is empty";
            return;
        }

        q = head;

        cout << "\n----- BROWSER HISTORY -----\n";

        while (q != NULL)
        {
            cout << q->url;

            if (q == current)
            {
                cout << " <-- Current Page";
            }

            cout << endl;

            q = q->next;
        }
    }
};

int main()
{
    Browser obj;
    int choice;

    do
    {
        cout << "\n\n----- BROWSER NAVIGATION SYSTEM -----";
        cout << "\n1. Visit New Webpage";
        cout << "\n2. Go Back";
        cout << "\n3. Go Forward";
        cout << "\n4. Display Current Webpage";
        cout << "\n5. Display Browser History";
        cout << "\n6. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.visitPage();
            break;

        case 2:
            obj.goBack();
            break;

        case 3:
            obj.goForward();
            break;

        case 4:
            obj.displayCurrent();
            break;

        case 5:
            obj.displayHistory();
            break;

        case 6:
            cout << "Exiting Browser...";
            break;

        default:
            cout << "Invalid choice";
        }

    } while (choice != 6);

    return 0;
}