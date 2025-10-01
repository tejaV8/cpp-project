#include <iostream>
using namespace std;

void mergeSort(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low, b[high + 1];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else if (arr[i] > arr[j])
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = arr[j];
        j++;
        k++;
    }
    for (int l = low; l <= high; l++)
    {
        arr[l] = b[l];
    }
    cout << "Merged [" << low << " to " << high << "]: ";
    for (int l = low; l <= high; l++)
    {
        cout << arr[l] << " ";
    }
    cout << endl;
}

void partition(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        partition(arr, low, mid);
        partition(arr, mid + 1, high);
        mergeSort(arr, low, mid, high);
    }
}

int main()
{
    int n;
    cout << "Enter the size: ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;

    cout << "Initiating Merge Sort Technique!" << endl
         << endl;
    partition(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}