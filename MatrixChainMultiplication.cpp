#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to compute minimum multiplication cost
void matrixChainOrder(vector<int> &p,
                      vector<vector<int>> &m,
                      vector<vector<int>> &s) {

    int n = p.size() - 1;

    // Cost is zero when multiplying one matrix
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;

    // l = chain length
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int q = m[i][k]
                      + m[k + 1][j]
                      + p[i - 1] * p[k] * p[j];

                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;   // store split point
                }
            }
        }
    }
}

// Function to print optimal parenthesization
void printOptimalParens(vector<vector<int>> &s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);

    cout << "Enter the dimensions of the matrices (p0 p1 p2 ... pn): ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    // Create DP tables
    vector<vector<int>> m(n + 1, vector<int>(n + 1));
    vector<vector<int>> s(n + 1, vector<int>(n + 1));

    // Compute minimum cost and split table
    matrixChainOrder(p, m, s);

    cout << "Minimum number of multiplications: "
         << m[1][n] << endl;

    cout << "Optimal Parenthesization: ";
    printOptimalParens(s, 1, n);
    cout << endl;

    return 0;
}
