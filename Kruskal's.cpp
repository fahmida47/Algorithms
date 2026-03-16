#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

vector<int> parent;

// MakeSet(v)
void MakeSet(int v)
{
    parent[v] = v;
}

// FindSet(v)
int FindSet(int v)
{
    if(parent[v] == v)
        return v;
    return parent[v] = FindSet(parent[v]);
}

// Union
void Union(int a, int b)
{
    parent[FindSet(a)] = FindSet(b);
}

// compare edge weight
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    parent.resize(V);

    cout << "Enter edges (u v weight):\n";
    for(int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    // T = empty
    vector<Edge> T;

    // for each v in V → MakeSet(v)
    for(int v = 0; v < V; v++)
        MakeSet(v);

    // sort E by increasing weight
    sort(edges.begin(), edges.end(), cmp);

    // for each (u,v) in E
    for(auto e : edges)
    {
        int u = e.u;
        int v = e.v;

        // if FindSet(u) != FindSet(v) → no cycle
        if(FindSet(u) != FindSet(v))
        {
            T.push_back(e);   // T = T ∪ {(u,v)}
            Union(u, v);
        }
    }

    cout << "\nEdges in MST:\n";
    int totalWeight = 0;

    for(auto e : T)
    {
        cout << e.u << " - " << e.v << " : " << e.w << endl;
        totalWeight += e.w;
    }

    cout << "Total Weight = " << totalWeight << endl;

    return 0;
}
