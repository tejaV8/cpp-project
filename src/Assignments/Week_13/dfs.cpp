#include <iostream>
using namespace std;

int G[10][10], visited[10], n;
char vertex[10];

void DFS(int v)
{
    cout << vertex[v] << "->";
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (G[v][i] && !visited[i])
        {
            DFS(i);
        }
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

    cout << "\nDFS Traversal: ";
    DFS(v);

    return 0;
}