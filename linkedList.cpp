#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

struct node *head = NULL, *head2 = NULL, *head3 = NULL, *p, *q;
node *cycleStart = NULL;

class Sll
{

public:
    int element;

    void insertFromB()
    {
        cout << "Enter the element you want to insert: ";
        cin >> element;

        p = (struct node *)malloc(sizeof(struct node));
        p->data = element;
        if (head == NULL)
        {
            p->next = NULL;
        }
        else
        {
            p->next = head;
        }
        head = p;
    }

    void insertFromE()
    {
        cout << "Enter the element you want to insert: ";
        cin >> element;
        p = (struct node *)malloc(sizeof(struct node));
        p->data = element;
        if (head == NULL)
        {
            p->next = NULL;
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
            p->next = NULL;
        }
    }

    void insertBefore()
    {
        int val;
        cout << "Enter the element before which you want to insert the element: ";
        cin >> val;

        if (head == NULL)
        {
            cout << "List is empty!";
            return;
        }

        if (head->data == val)
        {
            cout << "Enter the element you want to insert: ";
            cin >> element;

            p = (struct node *)malloc(sizeof(struct node));
            p->data = element;

            p->next = head;
            head = p;
        }
        else
        {
            q = head;
            while (q != NULL && q->next != NULL && q->next->data != val)
            {
                q = q->next;
            }

            if (q->next == NULL)
            {
                cout << "Element not found in the list !";
                return;
            }
            else
            {
                cout << "Enter the element you want to insert: ";
                cin >> element;

                p = (struct node *)malloc(sizeof(struct node));
                p->data = element;

                p->next = q->next;
                q->next = p;
            }
        }
    }

    void insertAfter()
    {
        int val;
        cout << "Enter the element after which you want to insert the element: ";
        cin >> val;

        if (head == NULL)
        {
            cout << "List is empty!";
            return;
        }

        if (head->data == val)
        {
            cout << "Enter the element you want to insert: ";
            cin >> element;

            p = (struct node *)malloc(sizeof(struct node));
            p->data = element;

            p->next = head->next;
            head->next = p;
        }
        else
        {
            q = head;
            while (q != NULL && q->data != val)
            {
                q = q->next;
            }

            if (q == NULL)
            {
                cout << "Element not found in the list !";
                return;
            }
            else
            {
                cout << "Enter the element you want to insert: ";
                cin >> element;

                p = (struct node *)malloc(sizeof(struct node));
                p->data = element;

                p->next = q->next;
                q->next = p;
            }
        }
    }

    void deleteEl()
    {
        cout << "Enter the value to delete: ";
        cin >> element;

        if (head == NULL)
        {
            cout << "The list is empty !!";
            return;
        }

        if (head->data == element)
        {
            p = head;
            head = head->next;
            free(p);
            return;
        }
        q = head;

        while (q->next != NULL && q->next->data != element)
        {
            q = q->next;
        }

        if (q->next == NULL)
        {
            cout << "Element not found in the list!!";
            return;
        }
        else
        {
            p = q->next;
            q->next = p->next;
            free(p);
        }
    }

    void count()
    {
        if (head == NULL)
        {
            cout << "Total elements : 0";
            return;
        }

        q = head;
        int count = 0;
        while (q != NULL)
        {
            count++;
            q = q->next;
        }

        cout << "Total elements : " << count << endl;
    }

    void search()
    {
        cout << "Enter element to search: ";
        cin >> element;

        if (head == NULL)
        {
            cout << "List is empty";
            return;
        }

        q = head;
        while (q != NULL)
        {
            if (q->data == element)
            {
                cout << "Element present !!";
                return;
            }

            q = q->next;
        }

        cout << "Element not found!";
    }

    void reverse()
    {

        if (head == NULL)
            return;
        q = NULL;
        p = head;
        node *r = NULL;

        while (p != NULL)
        {
            r = p->next;
            p->next = q;
            q = p;
            p = r;
        }

        head = q;
    }

    void merge()
    {
        head3 = NULL;
        if (head == NULL && head2 == NULL)
        {
            cout << "Both lists are empty!";
            return;
        }

        // If the first list is empty, head3 takes the second list
        if (head == NULL)
        {
            sort2();
            head3 = head2;
        }
        // If the second list is empty, head3 takes the first list
        else if (head2 == NULL)
        {
            sort();
            head3 = head;
        }
        else
        {
            sort();
            sort2();
            node *t1 = head;
            node *t2 = head2;
            node *tail3 = NULL;

            // Initialize head3 with the smaller of the two starting nodes
            if (t1->data <= t2->data)
            {
                head3 = t1;
                t1 = t1->next;
            }
            else
            {
                head3 = t2;
                t2 = t2->next;
            }
            tail3 = head3;

            // Traverse both lists and attach the smaller node to tail3
            while (t1 != NULL && t2 != NULL)
            {
                if (t1->data <= t2->data)
                {
                    tail3->next = t1;
                    t1 = t1->next;
                }
                else
                {
                    tail3->next = t2;
                    t2 = t2->next;
                }
                tail3 = tail3->next;
            }

            // Attach any remaining nodes from either list
            if (t1 != NULL)
            {
                tail3->next = t1;
            }
            else
            {
                tail3->next = t2;
            }
        }

        cout << "Merged sorted list: ";
        q = head3;
        while (q != NULL)
        {
            cout << q->data << " -> ";
            q = q->next;
        }
        cout << "NULL";
    }

    void unionn()
    {
        head3 = NULL;
        if (head == NULL && head2 == NULL)
        {
            cout << "Both lists are empty";
            return;
        }

        q = head;
        while (q != NULL)
        {
            int flag = 1;
            p = head3;
            while (flag == 1 && p != NULL)
            {
                if (q->data == p->data)
                {
                    flag = 0;
                    break;
                }
                p = p->next;
            }
            if (flag == 1)
            {
                if (head3 == NULL)
                {
                    node *temp = (struct node *)malloc(sizeof(struct node));
                    temp->data = q->data;
                    temp->next = NULL;
                    head3 = temp;
                }
                else
                {
                    p = head3;
                    while (p->next != NULL)
                    {
                        p = p->next;
                    }
                    node *temp = (struct node *)malloc(sizeof(struct node));
                    temp->data = q->data;
                    temp->next = NULL;
                    p->next = temp;
                }
            }

            q = q->next;
        }

        q = head2;
        while (q != NULL)
        {
            int flag = 1;
            p = head3;
            while (flag == 1 && p != NULL)
            {
                if (q->data == p->data)
                {
                    flag = 0;
                    break;
                }
                p = p->next;
            }
            if (flag == 1)
            {
                if (head3 == NULL)
                {
                    node *temp = (struct node *)malloc(sizeof(struct node));
                    temp->data = q->data;
                    temp->next = NULL;
                    head3 = temp;
                }
                else
                {
                    p = head3;
                    while (p->next != NULL)
                    {
                        p = p->next;
                    }
                    node *temp = (struct node *)malloc(sizeof(struct node));
                    temp->data = q->data;
                    temp->next = NULL;
                    p->next = temp;
                }
            }

            q = q->next;
        }

        q = head3;
        while (q != NULL)
        {
            cout << q->data << " -> ";
            q = q->next;
        }

        cout << "NULL";
    }

    void intersec()
    {
        head3 = NULL;
        if (head == NULL && head2 == NULL)
        {
            cout << "Both lists are empty";
            return;
        }

        q = head;
        while (q != NULL)
        {
            int flag = 1;
            p = head2;
            while (flag == 1 && p != NULL)
            {
                if (q->data == p->data)
                {
                    flag = 0;
                    break;
                }
                p = p->next;
            }
            if (flag == 0)
            {
                if (head3 == NULL)
                {
                    node *temp = (struct node *)malloc(sizeof(struct node));
                    temp->data = q->data;
                    temp->next = NULL;
                    head3 = temp;
                }
                else
                {
                    p = head3;
                    int flag2 = 1;
                    while (flag2 == 1 && p != NULL)
                    {
                        if (q->data == p->data)
                        {
                            flag2 = 0;
                            break;
                        }
                        p = p->next;
                    }
                    if (flag2 == 1)
                    {
                        p = head3;
                        while (p->next != NULL)
                        {
                            p = p->next;
                        }
                        node *temp = (struct node *)malloc(sizeof(struct node));
                        temp->data = q->data;
                        temp->next = NULL;
                        p->next = temp;
                    }
                }
            }

            q = q->next;
        }

        q = head3;
        while (q != NULL)
        {
            cout << q->data << " -> ";
            q = q->next;
        }

        cout << "NULL";
    }

    void sort()
    {
        if (head == NULL || head->next == NULL)
        {
            cout << "List is already sorted";
            return;
        }

        int swapped;
        node *i, *j;

        do
        {
            swapped = 0;
            i = head;

            while (i->next != NULL)
            {
                j = i->next;

                if (i->data > j->data)
                {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;

                    swapped = 1;
                }

                i = i->next;
            }

        } while (swapped == 1);

        cout << "Sorted list: ";
        q = head;

        while (q != NULL)
        {
            cout << q->data << " -> ";
            q = q->next;
        }

        cout << "NULL";
    }

    void sort2()
    {
        if (head2 == NULL || head2->next == NULL)
        {
            cout << "Second list is already sorted or empty";
            return;
        }

        int swapped;
        node *i, *j;

        do
        {
            swapped = 0;
            i = head2;

            while (i->next != NULL)
            {
                j = i->next;

                if (i->data > j->data)
                {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;

                    swapped = 1;
                }
                i = i->next;
            }

        } while (swapped == 1);

        cout << "Second list sorted successfully!";
    }

    void concatenate()
    {
        head3 = NULL;

        q = head;
        while (q != NULL)
        {
            node *temp = (struct node *)malloc(sizeof(struct node));
            temp->data = q->data;
            temp->next = NULL;

            if (head3 == NULL)
            {
                head3 = temp;
            }
            else
            {
                p = head3;
                while (p->next != NULL)
                {
                    p = p->next;
                }
                p->next = temp;
            }

            q = q->next;
        }

        q = head2;
        while (q != NULL)
        {
            node *temp = (struct node *)malloc(sizeof(struct node));
            temp->data = q->data;
            temp->next = NULL;

            if (head3 == NULL)
            {
                head3 = temp;
            }
            else
            {
                p = head3;
                while (p->next != NULL)
                {
                    p = p->next;
                }
                p->next = temp;
            }

            q = q->next;
        }

        cout << "Concatenated list: ";
        q = head3;
        while (q != NULL)
        {
            cout << q->data << " -> ";
            q = q->next;
        }
        cout << "NULL";
    }

    void createCycle()
    {
        head3 = NULL;

        if (head == NULL)
        {
            cout << "List is empty";
            return;
        }

        // Copy original list
        q = head;

        while (q != NULL)
        {
            node *temp = (struct node *)malloc(sizeof(struct node));
            temp->data = q->data;
            temp->next = NULL;

            if (head3 == NULL)
            {
                head3 = temp;
            }
            else
            {
                p = head3;
                while (p->next != NULL)
                {
                    p = p->next;
                }
                p->next = temp;
            }

            q = q->next;
        }

        int pos;
        cout << "Enter position to create cycle: ";
        cin >> pos;

        q = head3;
        node *start = NULL;
        int count = 1;

        while (q->next != NULL)
        {
            if (count == pos)
            {
                start = q;
            }

            q = q->next;
            count++;
        }

        if (count == pos)
        {
            start = q;
        }

        if (start == NULL)
        {
            cout << "Invalid position";
            return;
        }

        q->next = start;
        cycleStart = start;

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

        while (q != cycleStart)
        {
            cout << q->data << " -> ";
            q = q->next;
        }

        cout << cycleStart->data << " -> ";

        q = cycleStart->next;

        while (q != cycleStart)
        {
            cout << q->data << " -> ";
            q = q->next;
        }

        cout << cycleStart->data << " (Cycle)";
    }

    void deleteB()
    {

        if (head == NULL)
        {
            cout << "The list is empty !!";
            return;
        }

        p = head;
        head = p->next;
        free(p);
    }

    void deleteE()
    {

        if (head == NULL)
        {
            cout << "The list is empty !!";
            return;
        }

        if (head->next == NULL)
        {
            free(head);
            head = NULL;
            return;
        }

        q = head;
        p = head->next;

        while (p->next != NULL)
        {
            q = q->next;
            p = p->next;
        }
        q->next = NULL;
        free(p);
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }

        else
        {
            q = head;
            cout << "The elements in the list are: ";

            while (q != NULL)
            {
                cout << q->data << "-> ";
                q = q->next;
            }
            cout << "NULL";
        }
    }

    void insertFromB2()
    {
        cout << "Enter element: ";
        cin >> element;

        p = (struct node *)malloc(sizeof(struct node));
        p->data = element;
        p->next = head2;
        head2 = p;
    }

    void insertFromE2()
    {
        cout << "Enter element: ";
        cin >> element;

        p = (struct node *)malloc(sizeof(struct node));
        p->data = element;
        p->next = NULL;

        if (head2 == NULL)
        {
            head2 = p;
        }
        else
        {
            q = head2;
            while (q->next != NULL)
            {
                q = q->next;
            }
            q->next = p;
        }
    }

    void display2()
    {
        if (head2 == NULL)
        {
            cout << "Second list is empty";
            return;
        }

        q = head2;
        while (q != NULL)
        {
            cout << q->data << " -> ";
            q = q->next;
        }
        cout << "NULL";
    }
};

int main()
{
    int ch;
    Sll obj;

    do
    {
        cout << "\n\n========== SINGLY LINKED LIST ==========\n";

        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Value\n";
        cout << "4. Insert After a Value\n";
        cout << "5. Delete a Given Value\n";
        cout << "6. Delete at Beginning\n";
        cout << "7. Delete at End\n";
        cout << "8. Display First List\n";
        cout << "9. Search\n";
        cout << "10. Count Nodes\n";
        cout << "11. Reverse\n";
        cout << "12. Sort\n";
        cout << "13. Insert at Beginning (Second List)\n";
        cout << "14. Insert at End (Second List)\n";
        cout << "15. Display Second List\n";
        cout << "16. Merge\n";
        cout << "17. Union\n";
        cout << "18. Intersection\n";
        cout << "19. Concatenation\n";
        cout << "20. Create Cycle\n";
        cout << "21. Display Cycle\n";
        cout << "22. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
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
            obj.deleteB();
            break;

        case 7:
            obj.deleteE();
            break;

        case 8:
            obj.display();
            break;

        case 9:
            obj.search();
            break;

        case 10:
            obj.count();
            break;

        case 11:
            obj.reverse();
            break;

        case 12:
            obj.sort();
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
            obj.unionn();
            break;

        case 18:
            obj.intersec();
            break;

        case 19:
            obj.concatenate();
            break;

        case 20:
            obj.createCycle();
            break;

        case 21:
            obj.displayCycle();
            break;

        case 22:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (ch != 22);

    return 0;
}