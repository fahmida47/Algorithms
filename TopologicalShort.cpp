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




Ques-01==========>All Topological Sort
#include <bits/stdc++.h>
using namespace std;

vector<int> path;

void alltoposort(vector<vector<int>>& adj,
                 vector<int>& indegree,
                 vector<bool>& visited,
                 int n)
{
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0 && !visited[i])
        {
            visited[i] = true;
            path.push_back(i);

            for (int v : adj[i])
                indegree[v]--;

            alltoposort(adj, indegree, visited, n);

            visited[i] = false;
            path.pop_back();

            for (int v : adj[i])
                indegree[v]++;

            found = true;
        }
    }

    if (!found)
    {
        cout << "Topological Order: ";
        for (int x : path)
            cout << x << " ";
        cout << endl;
    }
}

int main()
{
    int v, e;
    cout << "Enter number of nodes and edges: ";
    cin >> v >> e;

    vector<vector<int>> adj(v);
    vector<int> indegree(v, 0);

    cout << "Enter " << e << " edges (u v format):" << endl;
    for (int i = 0; i < e; i++)
    {
        int u, w;
        cin >> u >> w;
        adj[u].push_back(w);
        indegree[w]++;
    }

    cout << "\nAll possible topological orders:\n";
    vector<bool> visited(v, false);

    alltoposort(adj, indegree, visited, v);

    return 0;
}


