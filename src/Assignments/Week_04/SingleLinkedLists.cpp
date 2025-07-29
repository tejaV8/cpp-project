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
        head = New_node;
    }
    else
    {
        New_node->next = head;
        head = New_node;
    }
    cout << "Node inserted at beginning.\n";
}

void insertAtLast()
{
    create();
    if (head == NULL)
    {
        head = New_node;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = New_node;
    }
    cout << "Node inserted at last.\n";
}

void insertAtPosition(int pos)
{
    if (pos <= 0)
    {
        cout << "Invalid position.\n";
        return;
    }

    if (pos == 1)
    {
        insertAtBeginning();
        return;
    }

    if (head == NULL)
    {
        cout << "List is empty. Only position 1 is valid.\n";
        return;
    }

    temp = NULL;
    cur = head;

    for (int i = 1; i < pos; i++)
    {
        temp = cur;
        cur = cur->next;

        if (cur == NULL && i < pos - 1)
        {
            cout << "Position does not exist. Do you want to insert at the end? (y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                insertAtLast();
            }
            else
            {
                cout << "Insertion cancelled.\n";
            }
            return;
        }
    }

    create();
    temp->next = New_node;
    New_node->next = cur;
    cout << "Node inserted at position " << pos << ".\n";
}


void deleteFromBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    temp = head;
    head = head->next;
    delete temp;
    cout << "Node deleted from beginning.\n";
}

void deleteFromLast()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        cout << "Node deleted from last.\n";
        return;
    }
    temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
    cout << "Node deleted from last.\n";
}

void deleteFromPosition(int pos)
{
    if (pos <= 0)
    {
        cout << "Invalid position.\n";
        return;
    }

    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    if (pos == 1)
    {
        deleteFromBeginning();
        return;
    }

    cur = head;
    for (int i = 1; i < pos; i++)
    {
        temp = cur;
        cur = cur->next;
        if (cur == NULL)
        {
            cout << "Position does not exist.\n";
            return;
        }
    }

    temp->next = cur->next;
    delete cur;
    cout << "Node deleted from position " << pos << ".\n";
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    temp = head;
    cout << "List elements: ";
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void search(int ele)
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == ele)
        {
            cout << "Element " << ele << " found in the list.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Element " << ele << " not found in the list.\n";
}

int main()
{
    int choice, pos, ele;

    cout << "--- Singly Linked List Menu ---\n";
    cout << "1. Insert at Beginning\n";
    cout << "2. Insert at Last\n";
    cout << "3. Insert at Position\n";
    cout << "4. Delete from Beginning\n";
    cout << "5. Delete from Last\n";
    cout << "6. Delete from Position\n";
    cout << "7. Display List\n";
    cout << "8. Search Element\n";
    cout << "9. Exit\n";

    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertAtBeginning();
            break;
        case 2:
            insertAtLast();
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
            deleteFromLast();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> pos;
            deleteFromPosition(pos);
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
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
