#include <iostream>
using namespace std;

int linearSearchIterative(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int linearSearchRecursive(int arr[], int n, int key, int index)
{
    if (index >= n)
        return -1;
    if (arr[index] == key)
        return index;
    return linearSearchRecursive(arr, n, key, index + 1);
}

int main()
{
    int n,choice, key, result;

    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\n---- Linear Search Menu ----\n";
    cout << "1. Iterative Linear Search\n";
    cout << "2. Recursive Linear Search\n";
    cout << "3. Exit\n";
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element to search: ";
            cin >> key;
            result = linearSearchIterative(arr, n, key);
            if (result != -1)
                cout << "Element found at index: " << result << endl;
            else
                cout << "Element not found.\n";
            break;

        case 2:
            cout << "Enter element to search: ";
            cin >> key;
            result = linearSearchRecursive(arr, n, key, 0);
            if (result != -1)
                cout << "Element found at index: " << result << endl;
            else
                cout << "Element not found.\n";
            break;

        case 3:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);
    cout << endl;

    return 0;
}