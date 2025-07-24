#include <iostream>
using namespace std;
#define MAX 5
int front = -1, rear = -1;
int deque[MAX];

void insertAtRear(int ele)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        cout << "Deque overflow\n";
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[rear] = ele;
        cout << "Element " << ele << " inserted at rear.\n";
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
        deque[rear] = ele;
        cout << "Element " << ele << " inserted at rear.\n";
    }
    else
    {
        rear++;
        deque[rear] = ele;
        cout << "Element " << ele << " inserted at rear.\n";
    }
}

void insertAtFront(int ele)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        cout << "Deque overflow\n";
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[front] = ele;
        cout << "Element " << ele << " inserted at front.\n";
    }
    else if (front == 0)
    {
        front = MAX - 1;
        deque[front] = ele;
        cout << "Element " << ele << " inserted at front.\n";
    }
    else
    {
        front--;
        deque[front] = ele;
        cout << "Element " << ele << " inserted at front.\n";
    }
}

void deleteFromFront()
{
    if (front == -1 && rear == -1)
    {
        cout << "Deque underflow\n";
    }
    else if (front == rear)
    {
        cout << "Element " << deque[front] << " deleted from front.\n";
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        cout << "Element " << deque[front] << " deleted from front.\n";
        front = 0;
    }
    else
    {
        cout << "Element " << deque[front] << " deleted from front.\n";
        front++;
    }
}

void deleteFromRear()
{
    if (front == -1 && rear == -1)
    {
        cout << "Deque underflow\n";
    }
    else if (front == rear)
    {
        cout << "Element " << deque[rear] << " deleted from rear.\n";
        front = rear = -1;
    }
    else if (rear == 0)
    {
        cout << "Element " << deque[rear] << " deleted from rear.\n";
        rear = MAX - 1;
    }
    else
    {
        cout << "Element " << deque[rear] << " deleted from rear.\n";
        rear--;
    }
}

void traversal()
{
    if (front == -1 && rear == -1)
    {
        cout << "Deque is empty\n";
        return;
    }

    cout << "Deque elements: ";
    for (int i = front; i != rear; i = (i + 1) % MAX)
    {
        cout << deque[i] << " ";
    }

    cout << deque[rear] << endl;
}

void search(int ele)
{
    if (front == -1 && rear == -1)
    {
        cout << "Deque is empty\n";
        return;
    }

    for (int i = front; i != rear; i = (i + 1) % MAX)
    {
        if (deque[i] == ele)
        {
            cout << "Element " << ele << " found in Deque.\n";
            return;
        }
    }

    if (deque[rear] == ele)
    {
        cout << "Element " << ele << " found in Deque.\n";
        return;
    }

    cout << "Element " << ele << " not found in Deque.\n";
}

int main()
{
    int choice, ele;
    cout << "Double Ended Queue Operations (Array Implementation)\n";
    cout << "1. Insert at front\n";
    cout << "2. Insert at rear\n";
    cout << "3. Delete from front\n";
    cout << "4. Delete from rear\n";
    cout << "5. Display\n";
    cout << "6. Search\n";
    cout << "7. Exit\n";

    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element to insert at front: ";
            cin >> ele;
            insertAtFront(ele);
            break;
        case 2:
            cout << "Enter element to insert at rear: ";
            cin >> ele;
            insertAtRear(ele);
            break;
        case 3:
            deleteFromFront();
            break;
        case 4:
            deleteFromRear();
            break;
        case 5:
            traversal();
            break;
        case 6:
            cout << "Enter element to search: ";
            cin >> ele;
            search(ele);
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 7);

    return 0;
}