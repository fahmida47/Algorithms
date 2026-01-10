//-------------------TOPOLOGICAL SORT-------------------------------//
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];   // graph
bool visited[100];
vector<int> topo;      // linked list equivalent

// Step 1: DFS to compute finishing time
void DFS(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
            DFS(v);
    }
// Step 2: vertex finished → insert at front
    topo.push_back(u);
}
// Topological-SORT(G)
void Topological_Sort(int n)
{
    for (int i = 0; i < n; i++)
        visited[i] = false;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            DFS(i);
    }
// Step 3: return list → reverse to simulate front insertion
    reverse(topo.begin(), topo.end());
}
int main()
{
    int node, edge;
    cin >> node >> edge;

    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Topological_Sort(node);

    cout << "Topological Order: ";
    for (int x : topo)
        cout << x << " ";

    return 0;
}

