#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int graph[V][V];

    cout << "Enter adjacency matrix:\n";
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            cin >> graph[i][j];

    int parent[V];
    int weight[V];
    bool visited[V];

    for(int i=0;i<V;i++)
    {
        weight[i] = INT_MAX;
        visited[i] = false;
    }

    weight[0] = 0;
    parent[0] = -1;

    for(int count=0; count<V-1; count++)
    {
        int min = INT_MAX, u;

        for(int v=0; v<V; v++)
        {
            if(!visited[v] && weight[v] < min)
            {
                min = weight[v];
                u = v;
            }
        }

        visited[u] = true;

        for(int v=0; v<V; v++)
        {
            if(graph[u][v] && !visited[v] && graph[u][v] < weight[v])
            {
                parent[v] = u;
                weight[v] = graph[u][v];
            }
        }
    }

    cout << "\nEdges in MST:\n";
    for(int i=1;i<V;i++)
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
}
