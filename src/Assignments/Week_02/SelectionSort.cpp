#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        bool swapped = false;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (i != minIndex)
        {
            swap(arr[i], arr[minIndex]);
            swapped = true;
        }

        cout << "After pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;

        if (!swapped)
        {
            cout << "No swaps in this pass → Array is already sorted." << endl;
            break;
        }
    }
}

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int *arr = new int[size];

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl;

    cout << "Implementing Selection Sort..." << endl;
    selectionSort(arr, size);

    cout << "\nSorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
