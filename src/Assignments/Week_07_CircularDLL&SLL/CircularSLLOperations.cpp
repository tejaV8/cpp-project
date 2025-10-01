#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *New_node, *temp, *cur;

void create()
{
    New_node = new node();
    cout << "Enter data: ";
    cin >> New_node->data;
    New_node->next = NULL;
}

void insertAtBeginning()
{
    create();
    if (head == NULL)
    {
        New_node->next = New_node;
        head = New_node;
        cout << "Element " << New_node->data << " inserted at the beginning.\n";
    }
    else
    {
        cur = head;
        while (cur->next != head)
        {
            cur = cur->next;
        }
        New_node->next = head;
        cur->next = New_node;
        head = New_node;
        cout << "Element " << New_node->data << " inserted at the beginning.\n";
    }
}

void insertAtEnd()
{
    create();
    if (head == NULL)
    {
        New_node->next = New_node;
        head = New_node;
    }
    else
    {
        cur = head;
        while (cur->next != head)
        {
            cur = cur->next;
        }
        New_node->next = head;
        cur->next = New_node;
        cout << "Element " << New_node->data << " inserted at the end.\n";
    }
}

void insertAtPosition(int pos) {
    if (pos < 1) {
        cout << "Invalid position.\n";
        return;
    }

    if (pos == 1) {
        insertAtBeginning();
        return;
    }

    cur = head;
    for (int i = 1; i < pos - 1; i++) {
        if (cur->next == head) {
            cout << "Position " << pos << " is out of bounds. Inserting at end.\n";
            insertAtEnd();
            return;
        }
        cur = cur->next;
    }

    create();
    New_node->next = cur->next;
    cur->next = New_node;

    cout << "Element " << New_node->data << " inserted at position " << pos << ".\n";
}


void deleteFromBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    else if (head->next == head)
    {
        cout << "Deleted element: " << head->data << ".\n";
        delete head;
        head = NULL;
        return;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        cout << "Deleted element: " << head->data << ".\n";
        temp->next = head->next;
        delete head;
        head = temp->next;
    }
}

void deleteFromEnd()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    else if (head->next == head)
    {
        cout << "Deleted element: " << head->data << ".\n";
        delete head;
        head = NULL;
        return;
    }
    else
    {
        temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        cur = temp->next;
        cout << "Deleted element: " << cur->data << ".\n";
        temp->next = head;
        delete cur;
    }
}

void deletionFromPosition(int pos) {
    if (head == NULL || pos < 1) {
        cout << "Invalid position or list is empty.\n";
        return;
    }

    if (pos == 1) {
        deleteFromBeginning();
        return;
    }

    cur = head;

    for (int i = 1; i < pos - 1; i++) {
        cur = cur->next;
        if (cur->next == head) {
            cout << "Position " << pos << " does not exist.\n";
            return;
        }
    }

    temp = cur->next;
    cur->next = temp->next;
    cout << "Deleted element: " << temp->data << ".\n";
    delete temp;
}


void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    temp = head;
    cout << "List elements: ";

    while (temp->next != head) {
        cout << temp->data << " → ";
        temp = temp->next;
    }
    cout << temp->data << " → (head)\n";
}

void search(int ele)
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    temp = head;
    do
    {
        if (temp->data == ele)
        {
            cout << "Element " << ele << " found in the list.\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Element " << ele << " not found in the list.\n";
}

int main()
{
    int choice, pos, ele;
    do
    {
        cout << "\n--- Circular Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display List\n";
        cout << "8. Search Element\n";
        cout << "9. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                cout << "Enter position: ";
                cin >> pos;
                insertAtPosition(pos);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deletionFromPosition(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                cout << "Enter element to search: ";
                cin >> ele;
                search(ele);
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);
    return 0;
}