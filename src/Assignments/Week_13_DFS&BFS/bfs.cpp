#include <iostream>
using namespace std;

int G[10][10], visited[10], n;
int Queue[10], f = 0, r = 0;
char vertex[10];

void BFS(int v)
{

    for (int i = 0; i < n; i++)
    {
        if (G[v][i] && !visited[i])
        {
            Queue[++r] = i;
            visited[i] = 1;
        }
    }

    if (f <= r)
    {
        cout << vertex[Queue[f++]] << "->";
        BFS(Queue[f]);
    }
}

int main()
{
    int v;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "\nEnter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "G[" << i << "][" << j << "]: ";
            cin >> G[i][j];
        }
    }

    cout << "Enter names of vertices:\n";
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        cout << "Vertex " << i << ": ";
        cin >> vertex[i];
    }

    cout << "\nEnter starting vertex index: ";
    cin >> v;

    Queue[r] = v;
    visited[v] = 1;

    cout << "\nBFS Traversal: ";
    BFS(v);

    return 0;
}