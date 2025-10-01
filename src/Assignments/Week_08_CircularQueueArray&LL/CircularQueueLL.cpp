#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL, *rear = NULL, *New_node, *temp;

void create()
{
    New_node = new node();
    cout << "Enter data: ";
    cin >> New_node->data;
    New_node->next = NULL;
}

void enqueue()
{
    create();
    if (front == NULL)
    {
        front = rear = New_node;
        rear->next = front;
    }
    else
    {
        rear->next = New_node;
        rear = New_node;
        rear->next = front;
    }
    cout << "Element " << New_node->data << " enqueued.\n";
}

void dequeue()
{
    if (front == NULL)
    {
        cout << "Circular Queue Underflow\n";
        return;
    }
    else if (front == rear)
    {
        cout << "Element " << front->data << " dequeued.\n";
        delete front;
        front = rear = NULL;
    }
    else
    {
        temp = front;
        cout << "Element " << front->data << " dequeued.\n";
        front = front->next;
        rear->next = front;
        delete temp;
    }
}

void display()
{
    if (front == NULL)
    {
        cout << "Circular Queue is empty.\n";
        return;
    }
    temp = front;
    cout << "Circular Queue elements: ";
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);
    cout << endl;
}

void search(int ele)
{
    if (front == NULL)
    {
        cout << "Circular Queue is empty.\n";
        return;
    }
    temp = front;
    do
    {
        if (temp->data == ele)
        {
            cout << "Element " << ele << " found in circular queue.\n";
            return;
        }
        temp = temp->next;
    } while (temp != front);
    cout << "Element " << ele << " not found in circular queue.\n";
}

int main()
{
    int choice, ele;
    cout << "--- Circular Queue Menu ---\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Display\n";
    cout << "4. Search\n";
    cout << "5. Exit\n";
    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            enqueue();
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
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}