#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL, *New_node = NULL, *temp;

void create() {
    New_node = new node();
    cout << "Enter data: ";
    cin >> New_node->data;
    New_node->next = NULL;
}

void enqueue() {
    create();
    if (rear == NULL) {
        front = rear = New_node;
    } else {
        rear->next = New_node;
        rear = New_node;
    }
    cout << "Element " << New_node->data << " enqueued.\n";
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue is Underflow.\n";
        return;
    }
    temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    cout << "Dequeued " << temp->data << ".\n";
    delete temp;
}

void display() {
    if (front == NULL) {
        cout << "Queue is empty.\n";
        return;
    }
    temp = front;
    cout << "Queue elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void search(int ele) {
    if (front == NULL) {
        cout << "Queue is empty.\n";
        return;
    }
    temp = front;
    while (temp != NULL) {
        if (temp->data == ele) {
            cout << "Element " << ele << " found in the queue.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Element " << ele << " not found in the queue.\n";
}

int main() {
    int choice, ele;

    cout << "--- Queue Operations Menu ---\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Display Queue\n";
    cout << "4. Search Element\n";
    cout << "5. Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
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
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}