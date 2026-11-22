#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

struct node *head = NULL, *tail = NULL;
struct node *head2 = NULL, *tail2 = NULL;
struct node *head3 = NULL, *tail3 = NULL;
struct node *p, *q;

class cll
{
public:
    int element;

    void insertFromB()
    {
        cout << "Enter element: ";
        cin >> element;

        p = (struct node *)malloc(sizeof(struct node));

        p->data = element;

        if (head == NULL)
        {
            head = p;
            tail = p;
            tail->next = head;
        }
        else
        {
            p->next = head;
            head = p;
            tail->next = head;
        }

        cout << "Node inserted at beginning";
    }

    void insertFromE()
    {
        cout << "Enter element: ";
        cin >> element;

        p = (struct node *)malloc(sizeof(struct node));

        p->data = element;

        if (head == NULL)
        {
            head = p;
            tail = p;
            tail->next = head;
        }
        else
        {
            tail->next = p;
            tail = p;
            tail->next = head;
        }

        cout << "Node inserted at end";
    }

    void insertBefore()
    {
        int value;
        node *r;

        cout << "Enter value before which to insert: ";
        cin >> value;

        if (head == NULL)
        {
            cout << "List is empty";
            return;
        }

        q = head;

        while (q->data != value && q != tail)
        {
            q = q->next;
        }

        if (q->data != value)
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
            p->next = head;
            head = p;
            tail->next = head;
        }
        else
        {
            r = head;

            while (r->next != q)
            {
                r = r->next;
            }

            p->next = q;
            r->next = p;
        }

        cout << "Node inserted before given value";
    }

    void insertAfter()
    {
        int value;

        cout << "Enter value after which to insert: ";
        cin >> value;

        if (head == NULL)
        {
            cout << "List is empty";
            return;
        }

        q = head;

        while (q->data != value && q != tail)
        {
            q = q->next;
        }

        if (q->data != value)
        {
            cout << "Value not found";
            return;
        }

        cout << "Enter element: ";
        cin >> element;

        p = (struct node *)malloc(sizeof(struct node));

        p->data = element;
        p->next = q->next;
        q->next = p;

        if (q == tail)
        {
            tail = p;
        }

        cout << "Node inserted after given value";
    }

    void deleteEl()
    {
        int value;

        cout << "Enter value to delete: ";
        cin >> value;

        if (head == NULL)
        {
            cout << "List is empty";
            return;
        }

        q = head;
        p = NULL;

        while (q->data != value && q != tail)
        {
            p = q;
            q = q->next;
        }

        if (q->data != value)
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
            tail->next = head;
        }
        else
        {
            p->next = q->next;

            if (q == tail)
            {
                tail = p;
            }
        }

        free(q);

        cout << "Node deleted successfully";
    }

    void deleteBefore()
    {
        int value;
        node *r;

        cout << "Enter value: ";
        cin >> value;

        if (head == NULL || head == tail)
        {
            cout << "No node exists before this value";
            return;
        }

        q = head;

        while (q->data != value && q != tail)
        {
            q = q->next;
        }

        if (q->data != value)
        {
            cout << "Value not found";
            return;
        }

        p = head;

        while (p->next != q)
        {
            p = p->next;
        }

        // p is the node immediately before q

        if (p == head && q == head)
        {
            // Not possible for a list with more than one node
            cout << "Invalid operation";
            return;
        }

        if (p == head)
        {
            cout << "No node exists before this value";
            return;
        }

        r = head;

        while (r->next != p)
        {
            r = r->next;
        }

        if (p == tail)
        {
            tail = r;
        }

        r->next = q;

        free(p);

        cout << "Node before given value deleted";
    }

    void deleteAfter()
    {
        int value;

        cout << "Enter value: ";
        cin >> value;

        if (head == NULL || head == tail)
        {
            cout << "No node exists after this value";
            return;
        }

        q = head;

        while (q->data != value && q != tail)
        {
            q = q->next;
        }

        if (q->data != value)
        {
            cout << "Value not found";
            return;
        }

        if (q->next == q)
        {
            cout << "No node exists after this value";
            return;
        }

        p = q->next;

        if (p == tail)
        {
            tail = q;
        }

        q->next = p->next;

        free(p);

        cout << "Node after given value deleted";
    }

    void search()
    {
        int value, flag = 0, count = 1;

        cout << "Enter value to search: ";
        cin >> value;

        if (head == NULL)
        {
            cout << "List is empty";
            return;
        }

        q = head;

        do
        {
            if (q->data == value)
            {
                cout << "Element found at position " << count;
                flag = 1;
                break;
            }

            q = q->next;
            count++;

        } while (q != head);

        if (flag == 0)
        {
            cout << "Element not found";
        }
    }

    void count()
    {
        int count = 0;

        if (head == NULL)
        {
            cout << "List is empty";
            return;
        }

        q = head;

        do
        {
            count++;
            q = q->next;

        } while (q != head);

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

        do
        {
            cout << q->data << " -> ";
            q = q->next;

        } while (q != head);

        cout << "(Back to Head)";
    }

    void addResult(int value)
    {
        p = (struct node *)malloc(sizeof(struct node));

        p->data = value;

        if (head3 == NULL)
        {
            head3 = p;
            tail3 = p;
            tail3->next = head3;
        }
        else
        {
            tail3->next = p;
            tail3 = p;
            tail3->next = head3;
        }
    }

    int existsInList(node *start, node *end, int value)
    {
        if (start == NULL)
        {
            return 0;
        }

        q = start;

        do
        {
            if (q->data == value)
            {
                return 1;
            }

            if (q == end)
            {
                break;
            }

            q = q->next;

        } while (q != start);

        return 0;
    }

    void sort()
    {
        if (head == NULL || head == tail)
        {
            cout << "List cannot be sorted";
            return;
        }

        int swapped, temp;

        do
        {
            swapped = 0;
            q = head;

            while (q != tail)
            {
                p = q->next;

                if (q->data > p->data)
                {
                    temp = q->data;
                    q->data = p->data;
                    p->data = temp;

                    swapped = 1;
                }

                q = q->next;
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

        p = tail;
        q = head;

        node *r;

        do
        {
            r = q->next;
            q->next = p;

            p = q;
            q = r;

        } while (q != head);

        tail = head;
        head = p;

        cout << "List reversed successfully";
    }

    void merge()
    {
        node *a = head;
        node *b = head2;

        int doneA = (head == NULL);
        int doneB = (head2 == NULL);

        head3 = NULL;
        tail3 = NULL;

        while (doneA == 0 || doneB == 0)
        {
            if (doneB == 1 ||
                (doneA == 0 && a->data <= b->data))
            {
                addResult(a->data);

                if (a == tail)
                {
                    doneA = 1;
                }
                else
                {
                    a = a->next;
                }
            }
            else
            {
                addResult(b->data);

                if (b == tail2)
                {
                    doneB = 1;
                }
                else
                {
                    b = b->next;
                }
            }
        }

        cout << "Merge completed";
    }

    void concatenate()
    {
        node *r;

        head3 = NULL;
        tail3 = NULL;

        if (head != NULL)
        {
            r = head;

            do
            {
                addResult(r->data);

                if (r == tail)
                {
                    break;
                }

                r = r->next;

            } while (r != head);
        }

        if (head2 != NULL)
        {
            r = head2;

            do
            {
                addResult(r->data);

                if (r == tail2)
                {
                    break;
                }

                r = r->next;

            } while (r != head2);
        }

        cout << "Concatenation completed";
    }

    void unionn()
    {
        node *r;

        head3 = NULL;
        tail3 = NULL;

        if (head != NULL)
        {
            r = head;

            do
            {
                if (existsInList(head3, tail3, r->data) == 0)
                {
                    addResult(r->data);
                }

                if (r == tail)
                {
                    break;
                }

                r = r->next;

            } while (r != head);
        }

        if (head2 != NULL)
        {
            r = head2;

            do
            {
                if (existsInList(head3, tail3, r->data) == 0)
                {
                    addResult(r->data);
                }

                if (r == tail2)
                {
                    break;
                }

                r = r->next;

            } while (r != head2);
        }

        cout << "Union completed";
    }

    void intersec()
    {
        node *r;

        head3 = NULL;
        tail3 = NULL;

        if (head != NULL)
        {
            r = head;

            do
            {
                if (existsInList(head2, tail2, r->data) == 1 &&
                    existsInList(head3, tail3, r->data) == 0)
                {
                    addResult(r->data);
                }

                if (r == tail)
                {
                    break;
                }

                r = r->next;

            } while (r != head);
        }

        cout << "Intersection completed";
    }

    void display3()
    {
        if (head3 == NULL)
        {
            cout << "Result list is empty";
            return;
        }

        q = head3;

        do
        {
            cout << q->data << " -> ";
            q = q->next;

        } while (q != head3);

        cout << "(Back to Head)";
    }

    void display2()
    {
        if (head2 == NULL)
        {
            cout << "Second list is empty";
            return;
        }

        q = head2;

        do
        {
            cout << q->data << " -> ";
            q = q->next;

        } while (q != head2);

        cout << "(Back to Head)";
    }

    void insertFromB2()
    {
        cout << "Enter element: ";
        cin >> element;

        p = (struct node *)malloc(sizeof(struct node));

        p->data = element;

        if (head2 == NULL)
        {
            head2 = p;
            tail2 = p;
            tail2->next = head2;
        }
        else
        {
            p->next = head2;
            head2 = p;
            tail2->next = head2;
        }

        cout << "Node inserted at beginning of second list";
    }

    void insertFromE2()
    {
        cout << "Enter element: ";
        cin >> element;

        p = (struct node *)malloc(sizeof(struct node));

        p->data = element;

        if (head2 == NULL)
        {
            head2 = p;
            tail2 = p;
            tail2->next = head2;
        }
        else
        {
            tail2->next = p;
            tail2 = p;
            tail2->next = head2;
        }

        cout << "Node inserted at end of second list";
    }
};

int main()
{
    cll obj;
    int choice;

    do
    {
        cout << "\n\n----- SINGLY CIRCULAR LINKED LIST -----";

        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert Before a Value";
        cout << "\n4. Insert After a Value";

        cout << "\n5. Delete a Given Value";
        cout << "\n6. Delete Before a Value";
        cout << "\n7. Delete After a Value";

        cout << "\n8. Search";
        cout << "\n9. Count";
        cout << "\n10. Display List 1";

        cout << "\n11. Sort";
        cout << "\n12. Reverse";

        cout << "\n13. Insert at Beginning (List 2)";
        cout << "\n14. Insert at End (List 2)";
        cout << "\n15. Display List 2";

        cout << "\n16. Merge";
        cout << "\n17. Concatenation";
        cout << "\n18. Union";
        cout << "\n19. Intersection";

        cout << "\n20. Display Result List";
        cout << "\n21. Exit";

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
            obj.sort();
            break;

        case 12:
            obj.reverse();
            break;

        case 13:
            obj.insertFromB2();
            break;

        case 14:
            obj.insertFromE2();
            break;

        case 15:
            obj.display2();
            break;

        case 16:
            obj.merge();
            break;

        case 17:
            obj.concatenate();
            break;

        case 18:
            obj.unionn();
            break;

        case 19:
            obj.intersec();
            break;

        case 20:
            obj.display3();
            break;

        case 21:
            cout << "Exiting program...";
            break;

        default:
            cout << "Invalid choice";
        }

    } while (choice != 21);

    return 0;
}