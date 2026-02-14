#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

// Print shortest path
void printPath(vector<vector<int>>& parent, int u, int v) {
    if(u == v) {
        cout << u << " ";
        return;
    }
    if(parent[u][v] == -1) {
        cout << "No path";
        return;
    }
    printPath(parent, u, parent[u][v]);
    cout << v << " ";
}

int main() {

    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n+1, vector<int>(n+1));

    cout << "Enter adjacency matrix (use -1 for no edge):\n";

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> graph[i][j];
            if(graph[i][j] == -1)
                graph[i][j] = INF;
        }
    }

// Step 1: Add extra vertex s
    vector<int> h(n+1, 0); // potential values

// Bellman-Ford
    for(int k=1;k<=n-1;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(graph[i][j] != INF && h[i] + graph[i][j] < h[j]) {
                    h[j] = h[i] + graph[i][j];
                }
            }
        }
    }

// Check negative cycle
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(graph[i][j] != INF && h[i] + graph[i][j] < h[j]) {
                cout << "Negative weight cycle detected!\n";
                return 0;
            }
        }
    }

// Step 2: Reweight edges
    vector<vector<int>> newGraph = graph;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(graph[i][j] != INF) {
                newGraph[i][j] = graph[i][j] + h[i] - h[j];
            }
        }
    }

// Step 3: Run Dijkstra from each vertex
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    vector<vector<int>> parent(n+1, vector<int>(n+1, -1));

    for(int src=1; src<=n; src++) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[src][src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for(int v=1; v<=n; v++) {
                if(newGraph[u][v] != INF) {
                    if(dist[src][u] + newGraph[u][v] < dist[src][v]) {
                        dist[src][v] = dist[src][u] + newGraph[u][v];
                        parent[src][v] = u;
                        pq.push({dist[src][v], v});
                    }
                }
            }
        }

// Restore original weights
        for(int v=1; v<=n; v++) {
            if(dist[src][v] != INF)
                dist[src][v] = dist[src][v] - h[src] + h[v];
        }
    }

// Print distance matrix
    cout << "\nShortest Distance Matrix:\n";

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    int u,v;
    cout << "\nEnter source and destination: ";
    cin >> u >> v;

    cout << "Shortest Path: ";
    printPath(parent, u, v);
    cout << endl;

    return 0;
}

