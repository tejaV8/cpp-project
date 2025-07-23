#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL, *New_node, *temp, *cur;

void create() {
    New_node = new node();
    cout << "Enter data: ";
    cin >> New_node->data;
    New_node->next = NULL;
}

void push() {
    create();
    if (top == NULL) {
        top = New_node;
    } else {
        New_node->next = top;
        top = New_node;
    }
    cout << "Element " << New_node->data << " pushed into stack.\n";
}

void pop() {
    if (top == NULL) {
        cout << "Stack is Underflow.\n";
        return;
    }
    temp = top;
    top = top->next;
    cout << "Popped " << temp->data << " from stack.\n";
    delete temp;
}

void peek() {
    if (top == NULL) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Top element is: " << top->data << endl;
}

void display() {
    if (top == NULL) {
        cout << "Stack is empty.\n";
        return;
    }
    temp = top;
    cout << "Stack elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void search(int ele) {
    if (top == NULL) {
        cout << "Stack is empty.\n";
        return;
    }
    temp = top;
    while (temp != NULL) {
        if (temp->data == ele) {
            cout << "Element " << ele << " found in the stack.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Element " << ele << " not found in the stack.\n";
}

int main() {
    int choice, ele;

    cout << "--- Stack Operations Menu ---\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. Display Stack\n";
    cout << "5. Search Element\n";
    cout << "6. Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Enter element to search: ";
                cin >> ele;
                search(ele);
                break;
            case 6:
                cout << "Exiting program. All operations completed.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
