#include <iostream>
using namespace std;

struct node
{
    int row;
    int col;
    int val;
    struct node *next;
};

struct node *head = NULL, *New_node, *temp;

void create(int r, int c, int val)
{
    New_node = new node();
    New_node->row = r;
    New_node->col = c;
    New_node->val = val;
    New_node->next = NULL;
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
    }
}

void displaySparseMatrix()
{
    cout << "The Sparse Matrix: ";
    temp = head;
    while (temp != NULL)
    {
        cout << "|" << temp->row << "|" << temp->col << "|" << temp->val << "|->";
        temp = temp->next;
    }
    cout << endl;
}

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

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (M[i][j] != 0)
            {
                create(i, j, M[i][j]);
            }
        }
    }

    displaySparseMatrix();
    return 0;
}