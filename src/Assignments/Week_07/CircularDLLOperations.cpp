#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *tail = NULL, *New_node, *temp, *cur;

void create() {
    New_node = new node();
    cout << "Enter data: ";
    cin >> New_node->data;
    New_node->next = NULL;
    New_node->prev = NULL;
}

void insertAtBeginning() {
    create();
    if (head == NULL) {
        head = tail = New_node;

        head->next = head->prev = head;
    } else {
        New_node->next = head;
        head->prev = New_node;
        tail->next = New_node;
        New_node->prev = tail;
        head = New_node;
    }
    cout << "Element " << New_node->data << " inserted at the beginning.\n";
}

void insertAtEnd() {
    create();
    if (head == NULL) {
        head = tail = New_node;

        head->next = head->prev = head;
    } else {
        tail->next = New_node;
        New_node->prev = tail;
        New_node->next = head;
        head->prev = New_node;
        tail = New_node;
    }
    cout << "Element " << New_node->data << " inserted at the end.\n";
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
    New_node->prev = cur;

    if (cur->next != head) {
        cur->next->prev = New_node;
    } else {
        tail = New_node;
    }

    cur->next = New_node;
    cout << "Element " << New_node->data << " inserted at position " << pos << ".\n";
}

void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    } else if (head->next == head) {
        cout << "Deleted element: " << head->data << ".\n";
        delete head;
        head = tail = NULL;
        return;
    } else {
        temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        cout << "Deleted element: " << temp->data << ".\n";
        delete temp;
    }
}

void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    } else if (head->next == head) {
        cout << "Deleted element: " << head->data << ".\n";
        delete head;
        head = tail = NULL;
        return;
    } else {
        temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        cout << "Deleted element: " << temp->data << ".\n";
        delete temp;
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
    for (int i = 1; i < pos; i++) {
        if (cur->next == head) {
            cout << "Position " << pos << " does not exist.\n";
            return;
        }
        cur = cur->next;
    }

    if (cur == tail) {
        deleteFromEnd();
        return;
    }

    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    cout << "Deleted element: " << cur->data << ".\n";
    delete cur;
}

void displayForward() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    temp = head;
    cout << "List elements (forward): ";
    do {
        cout << temp->data << " ⇄ ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)\n";
}

void displayBackward() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    temp = tail;
    cout << "List elements (backward): ";
    do {
        cout << temp->data << " ⇄ ";
        temp = temp->prev;
    } while (temp != tail);
    cout << "(tail)\n";
}

void search(int ele) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    temp = head;
    do {
        if (temp->data == ele) {
            cout << "Element " << ele << " found in the list.\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Element " << ele << " not found in the list.\n";
}


int main() {

    int choice, pos, ele;
    do {
        cout << "\n--- Circular Doubly Linked List Menu ---\n";
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

        switch (choice) {
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