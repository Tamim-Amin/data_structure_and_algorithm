#include <bits/stdc++.h>
using namespace std;
int adj[100][100];
bool visited[100];
void bfs( int n, int start)
{
    queue<int>q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int current_node = q.front();
        cout << current_node << " ";
        q.pop();

        for (int i = 0; i < n; i++)
        {
            if (adj[current_node][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
      int n, e;
    cout << "Enter number of vertices (n) and edges (e): ";
    cin >> n >> e;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }
    int u, v;
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++)
    {
         cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }
    cout << "BFS Traversal starting from vertex 0: ";

    bfs( n, 0);

    return 0;
}
