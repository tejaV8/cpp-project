#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *New_node = NULL, *head = NULL, *temp = NULL, *cur = NULL;

void create()
{
    New_node = new node();
    cout << "Enter data: ";
    cin >> New_node->data;
    New_node->next = NULL;
    New_node->prev = NULL;
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
        head->prev = New_node;
        head = New_node;
    }
    cout << "Element " << New_node->data << " inserted at the beginning.\n";
}

void insertAtEnd()
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
        {
            temp = temp->next;
        }
        temp->next = New_node;
        New_node->prev = temp;
    }
    cout << "Element " << New_node->data << " inserted at the end.\n";
}

void insertAtPosition(int pos)
{
    if (pos < 1)
    {
        cout << "Invalid position.\n";
        return;
    }

    if(head == NULL){
        create();
        head = New_node;
    }

    else{
        cur = head;
        for(int i = 1; i < pos; i++){
            if(cur->next == NULL){
                cout<<"Position does not exist\n";
                return ;
            }
            cur = cur->next;
        }
        if(cur == head){
            insertAtBeginning();
            return;
        }
        else{
            create();
            New_node->next = cur;
            New_node->prev = cur->prev;
            cur->prev->next = New_node;
            cur->prev = New_node;
        }
    }
    cout << "Element " << New_node->data << " inserted at position " << pos << ".\n";
}

void deleteFromBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    else if (head->next == NULL)
    {
        cout << "Deleted element: " << head->data << ".\n";
        delete head;
        head = NULL;
        return;
    }

    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        cout << "Deleted element: " << temp->data << ".\n";
        delete temp;
    }
}

void deleteFromEnd()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    else if (head->next == NULL)
    {
        cout << "Deleted element: " << head->data << ".\n";
        head = NULL;
        return;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        cout << "Deleted element: " << temp->data << ".\n";
        delete temp;
    }
}

void deleteFromPosition(int pos)
{
    if (pos < 1 || head == NULL)
    {
        cout << "Invalid position or list is empty.\n";
        return;
    }
    else
    {
        cur = head;

        for (int i = 1; i < pos; i++)
        {
            cur = cur->next;
            if (cur == NULL)
            {
                cout << "Position " << pos << " does not exist.\n";
                return;
            }
        }

        if (cur == head)
        {
            deleteFromBeginning();
        }
        else if (cur->next == NULL)
        {
            deleteFromEnd();
        }
        else
        {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            cout << "Deleted element: " << cur->data << ".\n";
            delete cur;
        }
    }
}

void displayForward()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    temp = head;
    cout << "List elements (forward): ";

    while (temp != NULL)
    {
        cout << temp->data << " ⇄ ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void displayBackward()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    cout << "List elements (backward): ";
    while (temp != NULL)
    {
        cout << temp->data << " ⇄ ";
        temp = temp->prev;
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

    do
    {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display Forward\n";
        cout << "8. Display Backward\n";
        cout << "9. Search Element\n";
        cout << "10. Exit\n";

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
            deleteFromPosition(pos);
            break;
        case 7:
            displayForward();
            break;
        case 8:
            displayBackward();
            break;
        case 9:
            cout << "Enter element to search: ";
            cin >> ele;
            search(ele);
            break;
        case 10:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 10);

    return 0;
}
