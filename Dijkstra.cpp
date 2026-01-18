#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
int dist[100];
int parent[100];
bool visited[100];

// ---------- Initialize-Single-Source ----------
void initialize_single_source(int n, int s)
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[s] = 0;
}

// ---------- RELAX(u, v, w) ----------
void relax(int u, int v, int w)
{
    if (dist[u] != INF && dist[v] > dist[u] + w)
    {
        dist[v] = dist[u] + w;
        parent[v] = u;
    }
}

// ---------- Print Path (NO stack) ----------
void print_path(int v)
{
    if (v == -1) return;
    print_path(parent[v]);
    cout << v << " ";
}

int main()
{
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    vector<vector<pair<int,int>>> adj(n);

    cout << "Enter graph (u v w):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w}); // undirected
    }

    int s;
    cout << "Enter source: ";
    cin >> s;

    //INITIALIZE-SINGLE-SOURCE
    initialize_single_source(n, s);

    //DIJKSTRA
    for (int i = 0; i < n; i++)
    {
        int u = -1, mn = INF;

        // EXTRACT-MIN(Q)
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < mn)
            {
                mn = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = true; // S ← S ∪ {u}

        // RELAX edges
        for (auto e : adj[u])
        {
            int v = e.first;
            int w = e.second;
            relax(u, v, w);
        }
    }
    cout << "\nVertex  Distance  Path\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << "       ";
        if (dist[i] == INF)
        {
            cout << "INF\n";
        }
        else
        {
            cout << dist[i] << "        ";
            print_path(i);
            cout << "\n";
        }
    }

    return 0;
}
