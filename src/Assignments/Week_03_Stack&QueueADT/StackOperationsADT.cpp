#include <iostream>
using namespace std;
#define MAX 100
int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        cout << "Stack Overflow\n";
    }
    else
    {
        top++;
        stack[top] = value;
        cout << "Pushed " << value << " onto stack.\n";
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow\n";
    }
    else
    {
        cout << "Popped " << stack[top] << " from stack.\n";
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        cout << "Stack is empty\n";
    }
    else
    {
        cout << "Top element is: " << stack[top] << endl;
    }
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is empty\n";
    }
    else
    {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

void search(int value)
{

    if (top == -1)
    {
        cout << "Stack is empty\n";
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        if (stack[i] == value)
        {
            cout << "Element " << value << " found at index " << i << " from top\n";
            return;
        }
    }

    cout << "Element " << value << " not found in stack\n";
}

int main()
{
    int choice, value;
    cout << "---Stack Operations Menu---\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. Display\n";
    cout << "5. Search\n";
    cout << "6. Exit\n";
    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            push(value);
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
            cout << "Enter value to search: ";
            cin >> value;
            search(value);
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 6);
    return 0;
}