#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL, *New_node, *temp, *cur;

void create()
{
    New_node = new node();
    cout << "Enter data: ";
    cin >> New_node->data;
    New_node->next = NULL;
}

void insertAtFront()
{
    create();
    if (front == NULL && rear == NULL)
    {
        front = rear = New_node;
    }
    else
    {
        New_node->next = front;
        front = New_node;
    }
    cout << "Element " << front->data << " inserted at front.\n";
}

void insertAtRear()
{
    create();
    if (front == NULL && rear == NULL)
    {
        front = rear = New_node;
    }
    else
    {
        rear->next = New_node;
        rear = New_node;
    }
    cout << "Element " << rear->data << " inserted at rear.\n";
}

void deleteFromFront()
{
    if (front == NULL)
    {
        cout << "Deque underflow\n";
        return;
    }

    temp = front;
    front = front->next;
    cout << "Element " << temp->data << " deleted from front.\n";
    delete temp;

    if (front == NULL)
        rear = NULL;
}

void deleteFromRear()
{
    if (rear == NULL)
    {
        cout << "Deque underflow\n";
        return;
    }

    if (front == rear)
    {
        cout << "Element " << rear->data << " deleted from rear.\n";
        delete rear;
        front = rear = NULL;
        return;
    }

    cur = front;
    while (cur->next != rear)
    {
        cur = cur->next;
    }

    cout << "Element " << rear->data << " deleted from rear.\n";
    delete rear;
    rear = cur;
    rear->next = NULL;
}

void display()
{
    if (front == NULL)
    {
        cout << "Deque is empty\n";
        return;
    }

    cout << "Deque elements: ";
    for (temp = front; temp != NULL; temp = temp->next)
    {
        cout << temp->data << " ";
    }
    cout << endl;
}

int main()
{
    int choice;

    cout << "\n--- DEQUE USING SINGLE LINKED LIST ---\n";
    cout << "1. Insert at Front\n";
    cout << "2. Insert at Rear\n";
    cout << "3. Delete from Front\n";
    cout << "4. Delete from Rear\n";
    cout << "5. Display\n";
    cout << "6. Exit\n";

    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertAtFront();
            break;
        case 2:
            insertAtRear();
            break;
        case 3:
            deleteFromFront();
            break;
        case 4:
            deleteFromRear();
            break;
        case 5:
            display();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
