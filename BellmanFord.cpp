#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    // edge list: (u, v, w)
    vector<tuple<int,int,int>> edges;

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int s;
    cout << "Enter source: ";
    cin >> s;

    vector<int> d(n, INT_MAX);
    vector<int> parent(n, -1); // parent array for path reconstruction

    // Initialize-Single-Source(G, s)
    d[s] = 0;

    // |V| - 1 times relaxation
    for (int i = 1; i <= n - 1; i++) {
        for (auto edge : edges) {
            int u, v, w;
            tie(u, v, w) = edge;

            if (d[u] != INT_MAX && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                parent[v] = u; // update parent
            }
        }
    }

    // Check for negative weight cycle
    for (auto edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;

        if (d[u] != INT_MAX && d[v] > d[u] + w) {
            cout << "Negative weight cycle detected\n";
            return 0;
        }
    }

    // Output shortest distances and paths
    cout << "\nVertex   Distance   Path\n";
    for (int i = 0; i < n; i++) {
        cout << i << "        ";
        if (d[i] == INT_MAX) {
            cout << "INF\n";
        } else {
            cout << d[i] << "        ";

            // reconstruct path
            vector<int> path;
            for (int v = i; v != -1; v = parent[v])
                path.push_back(v);
            reverse(path.begin(), path.end());

            for (int j = 0; j < path.size(); j++) {
                cout << path[j];
                if (j != path.size() - 1)
                    cout << " -> ";
            }
            cout << "\n";
        }
    }

    return 0;
}

