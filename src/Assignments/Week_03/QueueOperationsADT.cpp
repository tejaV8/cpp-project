#include <iostream>
using namespace std;
#define MAX 100
int front = -1, rear = -1;
int queue[MAX];

#include <iostream>
using namespace std;

#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        cout << "Queue Overflow\n";
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = value;
    }
    else
    {
        rear++;
        queue[rear] = value;
    }
    cout << "Enqueuing " << value << " into queue.\n";
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue Underflow\n";
        return;
    }
    else if (front == rear)
    {
        cout << "Dequeued " << queue[front] << " from queue.\n";
        front = -1;
        rear = -1;
    }
    else
    {
        cout << "Dequeued " << queue[front] << " from queue.\n";
        front++;
    }
}

void traversal()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue elements are: ";
    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << " ";
    }
    cout << endl;
}

void search(int value)
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty\n";
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        if (queue[i] == value)
        {
            cout << "Element " << value << " found at index " << i << endl;
            return;
        }
    }
    cout << "Element " << value << " not found in queue\n";
}

int main()
{
    int choice, value;
    cout << "---Queue Operations ADT---\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Traversal\n";
    cout << "4. Search\n";
    cout << "5. Exit\n";
    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            traversal();
            break;
        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            search(value);
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}