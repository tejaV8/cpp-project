#include <iostream>
using namespace std;

int main()
{
    int M[100][100], r, c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;
    cout << "Enter the elements of matrix: " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "M[" << i << "][" << j << "]: ";
            cin >> M[i][j];
        }
    }
    cout << endl;

    int size = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (M[i][j] != 0)
            {
                size++;
            }
        }
    }

    int SM[size][3], k = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (M[i][j] != 0)
            {
                SM[k][0] = i;
                SM[k][1] = j;
                SM[k][2] = M[i][j];
                k++;
            }
        }
    }

    cout << "The Sparse Matrix: " << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << SM[i][j] << "  ";
        }
        cout << endl;
    }
}