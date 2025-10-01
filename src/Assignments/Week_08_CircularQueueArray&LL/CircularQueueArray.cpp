#include <iostream>
using namespace std;

#define MAX 5
int front = -1, rear = -1;
int CQ[MAX];

void enqueue(int ele)
{
    if (front == (rear + 1) % MAX)
    {
        cout << "CircularQueue overflow\n";
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        CQ[rear] = ele;
        cout << "Element " << ele << " enqueued.\n";
    }
    else
    {
        rear = (rear + 1) % MAX;
        CQ[rear] = ele;
        cout << "Element " << ele << " enqueued.\n";
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "Circular Queue Underflow\n";
    }
    else if (front == rear)
    {
        cout << "Element " << CQ[front] << " dequeued.\n";
        front = rear = -1;
    }
    else
    {
        cout << "Element " << CQ[front] << " dequeued.\n";
        front = (front + 1) % MAX;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        cout << "Circular Queue is empty.\n";
    }
    else
    {
        cout << "Circular Queue elements: ";
        for (int i = front; i != rear; i = (i + 1) % MAX)
        {
            cout << CQ[i] << " ";
        }
        cout << CQ[rear] << endl;
    }
}

void search(int ele)
{
    if (front == -1 && rear == -1)
    {
        cout << "Circular Queue is empty.\n";
    }
    else
    {
        for (int i = front; i != rear; i = (i + 1) % MAX)
        {
            if (CQ[i] == ele)
            {
                cout << "Element " << ele << " found in circular queue.\n";
                return;
            }
        }
        if (CQ[rear] == ele)
        {
            cout << "Element " << ele << " found in circular queue.\n";
            return;
        }
        cout << "Element " << ele << " not found in circular queue.\n";
    }
}

int main()
{
    int choice, ele;

    cout << "---Circular Queue Menu---\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Display Circular Queue\n";
    cout << "4. Search\n";
    cout << "5. Exit\n";

    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element to enqueue: ";
            cin >> ele;
            enqueue(ele);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Enter element to search: ";
            cin >> ele; 
            search(ele);
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please enter a valid choice.\n";
        }
    } while (choice != 5);

    return 0;
}