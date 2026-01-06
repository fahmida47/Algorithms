#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    vector<vector<pair<int,int>>> adj(n);

    cout << "Enter graph (u v w):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // For undirected graph, uncomment:
        // adj[v].push_back({u, w});
    }

    int s;
    cout << "Enter source: ";
    cin >> s;

    vector<int> d(n, INT_MAX);
    vector<int> parent(n, -1); // To store path
    vector<bool> visited(n, false);

    d[s] = 0;

    // Dijkstra (array-based)
    for (int i = 0; i < n; i++) {
        int u = -1, mn = INT_MAX;

        // Extract-MIN(Q)
        for (int j = 0; j < n; j++) {
            if (!visited[j] && d[j] < mn) {
                mn = d[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = true;

        // Relax all adjacent vertices
        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (d[u] != INT_MAX && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                parent[v] = u; // Track parent
            }
        }
    }

    // Function to print path
    auto print_path = [&](int v) {
        if (v == -1) return;
        stack<int> path;
        while (v != -1) {
            path.push(v);
            v = parent[v];
        }
        while (!path.empty()) {
            cout << path.top();
            path.pop();
            if (!path.empty()) cout << " -> ";
        }
    };

    // Output
    cout << "\nVertex   Distance from Source   Path\n";
    for (int i = 0; i < n; i++) {
        cout << i << "        ";
        if (d[i] == INT_MAX) {
            cout << "INF\n";
        } else {
            cout << d[i] << "                 ";
            print_path(i);
            cout << "\n";
        }
    }

    return 0;
}
