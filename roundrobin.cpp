
#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int pid;
    int burstTime;
    node *next;
};

struct node *head = NULL, *tail = NULL;
struct node *p, *q;

class CPU
{
public:

    void addProcess()
    {
        int id, time;

        cout << "Enter Process ID: ";
        cin >> id;

        cout << "Enter Burst Time: ";
        cin >> time;

        if (time <= 0)
        {
            cout << "Burst time must be positive";
            return;
        }

        p = (struct node *)malloc(sizeof(struct node));

        p->pid = id;
        p->burstTime = time;

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

        cout << "Process added successfully";
    }

    void displayQueue()
    {
        if (head == NULL)
        {
            cout << "Ready queue is empty";
            return;
        }

        q = head;

        cout << "\n----- READY QUEUE -----\n";

        do
        {
            cout << "P" << q->pid
                 << " | Remaining Burst Time: "
                 << q->burstTime << endl;

            q = q->next;

        } while (q != head);
    }

    void roundRobin()
    {
        int timeQuantum;
        int executed;

        if (head == NULL)
        {
            cout << "No processes available";
            return;
        }

        cout << "Enter Time Quantum: ";
        cin >> timeQuantum;

        if (timeQuantum <= 0)
        {
            cout << "Time quantum must be positive";
            return;
        }

        q = head;
        p = tail;

        cout << "\n----- ROUND ROBIN EXECUTION -----\n";

        while (head != NULL)
        {
            if (q->burstTime > timeQuantum)
            {
                executed = timeQuantum;
            }
            else
            {
                executed = q->burstTime;
            }

            cout << "\nProcess P" << q->pid
                 << " executed for " << executed << " units";

            q->burstTime = q->burstTime - executed;

            cout << "\nRemaining Burst Time: "
                 << q->burstTime;

            if (q->burstTime == 0)
            {
                cout << "\nProcess P" << q->pid
                     << " completed";

                if (head == tail)
                {
                    free(q);
                    head = NULL;
                    tail = NULL;
                    q = NULL;
                }
                else if (q == head)
                {
                    head = head->next;
                    tail->next = head;

                    free(q);
                    q = head;
                }
                else
                {
                    p->next = q->next;

                    if (q == tail)
                    {
                        tail = p;
                        tail->next = head;
                    }

                    struct node *temp = q;
                    q = q->next;

                    free(temp);
                }
            }
            else
            {
                p = q;
                q = q->next;
            }
        }

        cout << "\n\nAll processes completed successfully";
    }
};

int main()
{
    CPU obj;
    int choice;

    do
    {
        cout << "\n\n----- ROUND ROBIN CPU SCHEDULER -----";
        cout << "\n1. Add Process";
        cout << "\n2. Display Ready Queue";
        cout << "\n3. Execute Round Robin Scheduling";
        cout << "\n4. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                obj.addProcess();
                break;

            case 2:
                obj.displayQueue();
                break;

            case 3:
                obj.roundRobin();
                break;

            case 4:
                cout << "Exiting CPU Scheduler";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 4);

    return 0;
}