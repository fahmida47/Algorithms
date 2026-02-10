#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b; //condition ? value_if_true : value_if_false;
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> W;

    int w[n+1], b[n+1];

    // weight and benefit input
    for (int i = 1; i <= n; i++) {
        cout << "Enter weight and benefit of item " << i << ": ";
        cin >> w[i] >> b[i];
    }

    int V[n+1][W+1];

    // Base case
    for (int i = 0; i <= n; i++)
        V[i][0] = 0;

    for (int j = 0; j <= W; j++)
        V[0][j] = 0;

    // Knapsack DP logic
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (w[i] <= j) {
                if (b[i] + V[i-1][j - w[i]] > V[i-1][j])
                    V[i][j] = b[i] + V[i-1][j - w[i]];
                else
                    V[i][j] = V[i-1][j];
            } else {
                V[i][j] = V[i-1][j];
            }
        }
    }

    cout << "\nMaximum benefit: " << V[n][W] << endl;
    return 0;
}

