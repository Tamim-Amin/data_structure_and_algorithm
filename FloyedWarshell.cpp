 #include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int path[100][100];

void printPath(int s, int d) {
    if (s == d) {
        cout << d << " ";
    } else {
        printPath(s, path[s][d]);
        cout << d << " ";
    }
}

int main() {
    int n, e, u, v, w, i, s;

    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    int dist[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
                path[i][j] = i;
            } else {
                dist[i][j] = INF;
                path[i][j] = -1;
            }
        }
    }

    cout << "Enter edges with source, destination, and weight (S D W):\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v >> w;
        dist[u][v] = w;
        path[u][v] = u;
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    cout << "\nDistance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    int src, dest;
    cout << "\nEnter source and destination: ";
    cin >> src >> dest;
    cout << "Shortest Path: ";
    printPath(src, dest);
    cout << "\nCost: " << dist[src][dest] << endl;

    return 0;
}
