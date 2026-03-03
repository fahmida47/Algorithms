#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to compute minimum multiplication cost
void matrixChainOrder(vector<int> &p,
                      vector<vector<int>> &m,
                      vector<vector<int>> &s) {

    int n = p.size() - 1;

    for (int i = 1; i <= n; i++)
        m[i][i] = 0;

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
                    s[i][j] = k;
                }
            }
        }
    }
}

// Print Optimal Parenthesization
void printOptimalParens(vector<vector<int>> &s, int i, int j) {
    if (i == j)
        cout << "A" << i;
    else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {

    int r1, c1, r2, c2;

    cout << "Enter first matrix (row col): ";
    cin >> r1 >> c1;

    cout << "Enter second matrix (row col): ";
    cin >> r2 >> c2;

    vector<int> p = {r1, c1, r2, c2};

    int n = p.size() - 1;

    vector<vector<int>> m(n + 1, vector<int>(n + 1));
    vector<vector<int>> s(n + 1, vector<int>(n + 1));

    matrixChainOrder(p, m, s);

    cout << "\nMatrix Chain:\n";
    cout << "A1 = " << r1 << "x" << c1 << endl;
    cout << "A2 = " << c1 << "x" << r2 << endl;
    cout << "A3 = " << r2 << "x" << c2 << endl;

    cout << "\nMinimum number of multiplications: "
         << m[1][n] << endl;

    cout << "Optimal Parenthesization: ";
    printOptimalParens(s, 1, n);
    cout << endl;

    return 0;
}
