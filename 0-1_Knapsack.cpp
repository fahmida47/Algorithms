Topic-01
// Knapsack (Without Finding Items)
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

Topic-02
// Knapsack (With Finding Items)
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> W;

    int w[n+1], b[n+1];

    // Input weight and benefit
    for (int i = 1; i <= n; i++) {
        cout << "Enter weight and benefit of item " << i << ": ";
        cin >> w[i] >> b[i];
    }

    int V[n+1][W+1];

    // Base cases
    for (int i = 0; i <= n; i++)
        V[i][0] = 0;
    for (int j = 0; j <= W; j++)
        V[0][j] = 0;

    // -------------------------------
    // Knapsack DP logic
    // -------------------------------
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

// Finding Items
    int i = n, k = W;
    cout << "Selected items: ";
    while (i > 0 && k > 0) {
        if (V[i][k] != V[i-1][k]) {
            cout << i << " ";   // item i selected
            k = k - w[i];
        }
        i = i - 1;
    }
    cout << endl;

    return 0;
}



