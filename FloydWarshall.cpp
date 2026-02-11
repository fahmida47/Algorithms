#include <bits/stdc++.h>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

// Print shortest path
void printPath(vector<vector<int>>& pi, int i, int j) {
    if (i == j) {
        cout << i << " ";
    }
    else if (pi[i][j] == -1) {
        cout << "No path";
    }
    else {
        printPath(pi, i, pi[i][j]);
        cout << j << " ";
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> D(n+1, vector<int>(n+1));
    vector<vector<int>> pi(n+1, vector<int>(n+1));

    cout << "Enter adjacency matrix (use -1 for no edge):\n";

    // Input
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {

            int x;
            cin >> x;

            if(x == -1) {
                D[i][j] = INF;
                pi[i][j] = -1;
            }
            else {
                D[i][j] = x;
                if(i != j)
                    pi[i][j] = i;
                else
                    pi[i][j] = -1;
            }
        }
    }

    // Floyd-Warshall
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {

                // Overflow safe check
                if(D[i][k] != INF && D[k][j] != INF &&
                   D[i][k] + D[k][j] < D[i][j]) {

                    D[i][j] = D[i][k] + D[k][j];
                    pi[i][j] = pi[k][j];
                }
            }
        }
    }

    // Print distance matrix
    cout << "\nShortest Distance Matrix:\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(D[i][j] == INF)
                cout << "INF ";
            else
                cout << D[i][j] << " ";
        }
        cout << endl;
    }

    int u, v;
    cout << "\nEnter source and destination: ";
    cin >> u >> v;

    cout << "Shortest Path: ";
    printPath(pi, u, v);
    cout << endl;

    return 0;
}
