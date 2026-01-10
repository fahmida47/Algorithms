//------------------------------DAG SHORTEST PATH-------------------------------//
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[100];
bool visited[100];
vector<int> topo;
int dist[100];
int parent[100]; // to store the previous node in the shortest path

// DFS for Topological Sort
void DFS(int u)
{
    visited[u] = true;
    for (auto e : adj[u])
    {
        int v = e.first;
        if (!visited[v])
            DFS(v);
    }
    topo.push_back(u);
}

// DAG-SHORTEST-PATHS(G, w, s)
void DAG_Shortest_Paths(int n, int s)
{
    // Step 1: Topological sort
    for (int i = 0; i < n; i++)
        if (!visited[i])
            DFS(i);

    reverse(topo.begin(), topo.end());

    // Step 2: Initialize-Single-Source
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1; // -1 means no parent
    }
    dist[s] = 0;

    // Step 3–5: Relax edges
    for (int u : topo)
    {
        if (dist[u] != INT_MAX)
        {
            for (auto e : adj[u])
            {
                int v = e.first;
                int w = e.second;
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    parent[v] = u; // update parent
                }
            }
        }
    }
}

// Function to print path from source to node u
void printPath(int u)
{
    if (u == -1) return; // no path
    printPath(parent[u]);
    cout << u << " ";
}

int main()
{
    int node, edge;
    cout << "Enter number of nodes & edges: ";
    cin >> node >> edge;

    cout << "Enter edges in format: u v w\n";
    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    DAG_Shortest_Paths(node, source);

    cout << "\nShortest distances and paths from node " << source << ":\n";
    cout << "Node\tDistance\tPath\n";
    cout << "-------------------------------\n";
    for (int i = 0; i < node; i++)
    {
        cout << i << "\t";
        if (dist[i] == INT_MAX)
        {
            cout << "INF\t\t-";
        }
        else
        {
            cout << dist[i] << "\t\t";
            printPath(i);
        }
        cout << "\n";
    }

    return 0;
}

