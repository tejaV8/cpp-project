#include <iostream>
using namespace std;

int binarySearchIterative(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, high, key);
    else
        return binarySearchRecursive(arr, low, mid - 1, key);
}

int main()
{
    int n, choice, key, result;

    cout << "Enter number of elements (sorted): ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    do
    {
        cout << "\n---- Binary Search Menu ----\n";
        cout << "1. Iterative Binary Search\n";
        cout << "2. Recursive Binary Search\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element to search: ";
            cin >> key;
            result = binarySearchIterative(arr, n, key);
            if (result != -1)
                cout << "Element found at index: " << result << endl;
            else
                cout << "Element not found.\n";
            break;

        case 2:
            cout << "Enter element to search: ";
            cin >> key;
            result = binarySearchRecursive(arr, 0, n - 1, key);
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