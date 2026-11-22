#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

struct node *head = NULL, *tail = NULL, *p, *q;
struct node *head2 = NULL, *tail2 = NULL;
struct node *head3 = NULL, *tail3 = NULL;
node *cycleStart = NULL;

class dll
{
public:
    int element;

    void insertFromB()
    {
        cout << "Enter element: ";
        cin >> element;

        p = (struct node *)malloc(sizeof(struct node));

        p->data = element;
        p->prev = NULL;
        p->next = head;

        if (head == NULL)
        {
            head = p;
            tail = p;
        }
        else
        {
            head->prev = p;
            head = p;
        }

        cout << "Node inserted at beginning";
    }

    void insertFromE()
    {
        cout << "Enter element: ";
        cin >> element;

        p = (struct node *)malloc(sizeof(struct node));

        p->data = element;
        p->next = NULL;
        p->prev = tail;

        if (head == NULL)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }

        cout << "Node inserted at end";
    }

    void insertBefore()
    {
        int value;

        cout << "Enter value before which to insert: ";
        cin >> value;

        q = head;

        while (q != NULL && q->data != value)
        {
            q = q->next;
        }

        if (q == NULL)
        {
            cout << "Value not found";
            return;
        }

        cout << "Enter element: ";
        cin >> element;

        p = (struct node *)malloc(sizeof(struct node));
        p->data = element;

        if (q == head)
        {
            p->prev = NULL;
            p->next = head;
            head->prev = p;
            head = p;
        }
        else
        {
            p->next = q;
            p->prev = q->prev;

            q->prev->next = p;
            q->prev = p;
        }

        cout << "Node inserted before given value";
    }

    void insertAfter()
    {
        int value;

        cout << "Enter value after which to insert: ";
        cin >> value;

        q = head;

        while (q != NULL && q->data != value)
        {
            q = q->next;
        }

        if (q == NULL)
        {
            cout << "Value not found";
            return;
        }

        cout << "Enter element: ";
        cin >> element;

        p = (struct node *)malloc(sizeof(struct node));
        p->data = element;

        if (q == tail)
        {
            p->prev = tail;
            p->next = NULL;
            tail->next = p;
            tail = p;
        }
        else
        {
            p->prev = q;
            p->next = q->next;

            q->next->prev = p;
            q->next = p;
        }

        cout << "Node inserted after given value";
    }

    void deleteEl()
    {
        int value;

        cout << "Enter value to delete: ";
        cin >> value;

        q = head;

        while (q != NULL && q->data != value)
        {
            q = q->next;
        }

        if (q == NULL)
        {
            cout << "Value not found";
            return;
        }

        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else if (q == head)
        {
            head = head->next;
            head->prev = NULL;
        }
        else if (q == tail)
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        else
        {
            q->prev->next = q->next;
            q->next->prev = q->prev;
        }

        free(q);

        cout << "Node deleted successfully";
    }

    void deleteBefore()
    {
        int value;

        cout << "Enter value: ";
        cin >> value;

        q = head;

        while (q != NULL && q->data != value)
        {
            q = q->next;
        }

        if (q == NULL)
        {
            cout << "Value not found";
            return;
        }

        if (q == head)
        {
            cout << "No node exists before this value";
            return;
        }

        p = q->prev;

        if (p == head)
        {
            head = q;
            q->prev = NULL;
        }
        else
        {
            p->prev->next = q;
            q->prev = p->prev;
        }

        free(p);

        cout << "Node before given value deleted";
    }

    void deleteAfter()
    {
        int value;

        cout << "Enter value: ";
        cin >> value;

        q = head;

        while (q != NULL && q->data != value)
        {
            q = q->next;
        }

        if (q == NULL)
        {
            cout << "Value not found";
            return;
        }

        if (q == tail)
        {
            cout << "No node exists after this value";
            return;
        }

        p = q->next;

        if (p == tail)
        {
            tail = q;
            q->next = NULL;
        }
        else
        {
            q->next = p->next;
            p->next->prev = q;
        }

        free(p);

        cout << "Node after given value deleted";
    }

    void search()
    {
        int value, flag = 0, count = 1;

        cout << "Enter value to search: ";
        cin >> value;

        q = head;

        while (q != NULL)
        {
            if (q->data == value)
            {
                cout << "Element found at position " << count;
                flag = 1;
                break;
            }

            q = q->next;
            count++;
        }

        if (flag == 0)
        {
            cout << "Element not found";
        }
    }

    void count()
    {
        int count = 0;

        q = head;

        while (q != NULL)
        {
            count++;
            q = q->next;
        }

        cout << "Total number of nodes: " << count;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty";
            return;
        }

        q = head;

        cout << "NULL <-> ";

        while (q != NULL)
        {
            cout << q->data << " <-> ";
            q = q->next;
        }

        cout << "NULL";
    }

    void displayReverse()
    {
        if (tail == NULL)
        {
            cout << "List is empty";
            return;
        }

        q = tail;

        cout << "NULL <-> ";

        while (q != NULL)
        {
            cout << q->data << " <-> ";
            q = q->prev;
        }

        cout << "NULL";
    }

    void sort()
    {
        if (head == NULL || head->next == NULL)
        {
            cout << "List cannot be sorted";
            return;
        }

        int swapped;
        node *i, *j;
        int temp;

        do
        {
            swapped = 0;
            i = head;

            while (i->next != NULL)
            {
                j = i->next;

                if (i->data > j->data)
                {
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;

                    swapped = 1;
                }

                i = i->next;
            }

        } while (swapped == 1);

        cout << "List sorted successfully";
    }

    void reverse()
    {
        if (head == NULL)
        {
            cout << "List is empty";
            return;
        }

        q = head;

        while (q != NULL)
        {
            p = q->prev;
            q->prev = q->next;
            q->next = p;

            q = q->prev;
        }

        p = head;
        head = tail;
        tail = p;

        cout << "List reversed successfully";
    }

    void merge()
    {
        node *a = head;
        node *b = head2;
        node *temp;

        head3 = NULL;
        tail3 = NULL;

        while (a != NULL || b != NULL)
        {
            temp = (struct node *)malloc(sizeof(struct node));

            if (b == NULL || (a != NULL && a->data <= b->data))
            {
                temp->data = a->data;
                a = a->next;
            }
            else
            {
                temp->data = b->data;
                b = b->next;
            }

            temp->prev = tail3;
            temp->next = NULL;

            if (head3 == NULL)
            {
                head3 = temp;
                tail3 = temp;
            }
            else
            {
                tail3->next = temp;
                tail3 = temp;
            }
        }

        cout << "Sorted merge completed";
    }

    void concatenate()
    {
        node *r;

        head3 = NULL;
        tail3 = NULL;

        r = head;

        while (r != NULL)
        {
            p = (struct node *)malloc(sizeof(struct node));

            p->data = r->data;
            p->prev = tail3;
            p->next = NULL;

            if (head3 == NULL)
            {
                head3 = p;
                tail3 = p;
            }
            else
            {
                tail3->next = p;
                tail3 = p;
            }

            r = r->next;
        }

        r = head2;

        while (r != NULL)
        {
            p = (struct node *)malloc(sizeof(struct node));

            p->data = r->data;
            p->prev = tail3;
            p->next = NULL;

            if (head3 == NULL)
            {
                head3 = p;
                tail3 = p;
            }
            else
            {
                tail3->next = p;
                tail3 = p;
            }

            r = r->next;
        }

        cout << "Concatenation completed";
    }
    void unionn()
    {
        node *r, *s;
        int flag;

        head3 = NULL;
        tail3 = NULL;

        r = head;

        while (r != NULL)
        {
            p = (struct node *)malloc(sizeof(struct node));

            p->data = r->data;
            p->prev = tail3;
            p->next = NULL;

            if (head3 == NULL)
            {
                head3 = p;
                tail3 = p;
            }
            else
            {
                tail3->next = p;
                tail3 = p;
            }

            r = r->next;
        }

        r = head2;

        while (r != NULL)
        {
            flag = 1;
            s = head3;

            while (s != NULL)
            {
                if (s->data == r->data)
                {
                    flag = 0;
                    break;
                }

                s = s->next;
            }

            if (flag == 1)
            {
                p = (struct node *)malloc(sizeof(struct node));

                p->data = r->data;
                p->prev = tail3;
                p->next = NULL;

                if (head3 == NULL)
                {
                    head3 = p;
                    tail3 = p;
                }
                else
                {
                    tail3->next = p;
                    tail3 = p;
                }
            }

            r = r->next;
        }

        cout << "Union completed";
    }
    void intersec()
    {
        node *r, *s, *t;
        int flag, flag2;

        head3 = NULL;
        tail3 = NULL;

        r = head;

        while (r != NULL)
        {
            flag = 0;
            s = head2;

            while (s != NULL)
            {
                if (s->data == r->data)
                {
                    flag = 1;
                    break;
                }

                s = s->next;
            }

            if (flag == 1)
            {
                flag2 = 1;
                t = head3;

                while (t != NULL)
                {
                    if (t->data == r->data)
                    {
                        flag2 = 0;
                        break;
                    }

                    t = t->next;
                }

                if (flag2 == 1)
                {
                    p = (struct node *)malloc(sizeof(struct node));

                    p->data = r->data;
                    p->prev = tail3;
                    p->next = NULL;

                    if (head3 == NULL)
                    {
                        head3 = p;
                        tail3 = p;
                    }
                    else
                    {
                        tail3->next = p;
                        tail3 = p;
                    }
                }
            }

            r = r->next;
        }

        cout << "Intersection completed";
    }

    void createCycle()
    {
        if (head == NULL)
        {
            cout << "List is empty";
            return;
        }

        // Copy original list into head3
        head3 = NULL;
        tail3 = NULL;

        q = head;

        while (q != NULL)
        {
            p = (struct node *)malloc(sizeof(struct node));

            p->data = q->data;
            p->prev = tail3;
            p->next = NULL;

            if (head3 == NULL)
            {
                head3 = p;
                tail3 = p;
            }
            else
            {
                tail3->next = p;
                tail3 = p;
            }

            q = q->next;
        }

        int pos, count = 1;

        cout << "Enter position to create cycle: ";
        cin >> pos;

        if (pos < 1)
        {
            cout << "Invalid position";
            return;
        }

        q = head3;

        while (count < pos && q != NULL)
        {
            q = q->next;
            count++;
        }

        if (q == NULL)
        {
            cout << "Invalid position";
            return;
        }

        cycleStart = q;

        // Connect last node to cycle starting node
        tail3->next = cycleStart;
        cycleStart->prev = tail3;

        cout << "Cycle created successfully in head3";
    }

    void displayCycle()
    {
        if (head3 == NULL || cycleStart == NULL)
        {
            cout << "No cycle exists";
            return;
        }

        q = head3;

        while (q != tail3)
        {
            cout << q->data << " <-> ";
            q = q->next;
        }

        cout << tail3->data;

        cout << " -> " << cycleStart->data << " (Cycle)";
    }

    void insertFromB2()
    {
        cout << "Enter element: ";
        cin >> element;

        p = (struct node *)malloc(sizeof(struct node));

        p->data = element;
        p->prev = NULL;
        p->next = head2;

        if (head2 == NULL)
        {
            head2 = p;
            tail2 = p;
        }
        else
        {
            head2->prev = p;
            head2 = p;
        }

        cout << "Node inserted at beginning of second list";
    }

    void insertFromE2()
    {
        cout << "Enter element: ";
        cin >> element;

        p = (struct node *)malloc(sizeof(struct node));

        p->data = element;
        p->next = NULL;
        p->prev = tail2;

        if (head2 == NULL)
        {
            head2 = p;
            tail2 = p;
        }
        else
        {
            tail2->next = p;
            tail2 = p;
        }

        cout << "Node inserted at end of second list";
    }

    void display2()
    {
        if (head2 == NULL)
        {
            cout << "List is empty";
            return;
        }

        q = head2;

        cout << "NULL <-> ";

        while (q != NULL)
        {
            cout << q->data << " <-> ";
            q = q->next;
        }

        cout << "NULL";
    }

    void display3()
    {
        if (head3 == NULL)
        {
            cout << "Result list is empty";
            return;
        }

        q = head3;

        cout << "NULL <-> ";

        while (q != NULL)
        {
            cout << q->data << " <-> ";
            q = q->next;
        }

        cout << "NULL";
    }
};

int main()
{
    dll obj;
    int choice;

    do
    {
        cout << "\n\n----- DOUBLY LINKED LIST -----";
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert Before a Value";
        cout << "\n4. Insert After a Value";
        cout << "\n5. Delete a Given Value";
        cout << "\n6. Delete Before a Value";
        cout << "\n7. Delete After a Value";
        cout << "\n8. Search";
        cout << "\n9. Count";
        cout << "\n10. Display Forward";
        cout << "\n11. Display Backward";
        cout << "\n12. Sort";
        cout << "\n13. Reverse";
        cout << "\n14. Insert at Beginning (List 2)";
        cout << "\n15. Insert at End (List 2)";
        cout << "\n16. Display List 2";
        cout << "\n17. Merge";
        cout << "\n18. Concatenation";
        cout << "\n19. Union";
        cout << "\n20. Intersection";
        cout << "\n21. Display Result List";
        cout << "\n22. Create Cycle";
        cout << "\n23. Display Cycle";
        cout << "\n24. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.insertFromB();
            break;

        case 2:
            obj.insertFromE();
            break;

        case 3:
            obj.insertBefore();
            break;

        case 4:
            obj.insertAfter();
            break;

        case 5:
            obj.deleteEl();
            break;

        case 6:
            obj.deleteBefore();
            break;

        case 7:
            obj.deleteAfter();
            break;

        case 8:
            obj.search();
            break;

        case 9:
            obj.count();
            break;

        case 10:
            obj.display();
            break;

        case 11:
            obj.displayReverse();
            break;

        case 12:
            obj.sort();
            break;

        case 13:
            obj.reverse();
            break;

        case 14:
            obj.insertFromB2();
            break;

        case 15:
            obj.insertFromE2();
            break;

        case 16:
            obj.display2();
            break;

        case 17:
            obj.merge();
            break;

        case 18:
            obj.concatenate();
            break;

        case 19:
            obj.unionn();
            break;

        case 20:
            obj.intersec();
            break;

        case 21:
            obj.display3();
            break;

        case 22:
            obj.createCycle();
            break;

        case 23:
            obj.displayCycle();
            break;

        case 24:
            cout << "Exiting program...";
            break;

        default:
            cout << "Invalid choice";
        }

    } while (choice != 24);

    return 0;
}