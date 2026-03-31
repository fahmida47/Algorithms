///Topics
// 1. Basic
//2. Half of the solutions

//Topic- 01
//Without showing Diagram
#include <iostream>
using namespace std;

int x[100]; // x[k] = column position of queen in row k
int n;

// Check if queen can be placed at (k, i)
bool Place(int k, int i) {
    for (int j = 1; j < k; j++) {
        // same column OR same diagonal
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

// N-Queens recursive function
void NQueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i;

            if (k == n) {
                // Print solution
                cout << "Solution: ";
                for (int j = 1; j <= n; j++) {
                    cout << x[j] << " ";
                }
                cout << endl;
            } else {
                NQueens(k + 1, n);
            }
        }
    }
}

int main() {
    cout << "Enter number of queens: ";
    cin >> n;

    NQueens(1, n);

    return 0;
}

//Topic- 02
//Showing Diagram
#include <iostream>
#include <cmath>
using namespace std;

int x[100];
int n;

// Check valid position
bool Place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

// Print board as diagram
void PrintBoard() {
    cout << "\nBoard:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                cout << " Q ";
            else
                cout << " . ";
        }
        cout << endl;
    }
    cout << "-------------------\n";
}

// N-Queens
void NQueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i;

            if (k == n) {
                // Print solution array
                cout << "Solution: ";
                for (int j = 1; j <= n; j++) {
                    cout << x[j] << " ";
                }
                cout << endl;

                // Print diagram
                PrintBoard();
            } else {
                NQueens(k + 1, n);
            }
        }
    }
}

int main() {
    cout << "Enter number of queens: ";
    cin >> n;

    NQueens(1, n);

    return 0;
}

//Topic- 03
//half of the solutions without Diagram
#include <iostream>
#include <cmath>
using namespace std;

int x[100];
int n;
int totalSolutions = 0;
int printed = 0;

// Check valid position
bool Place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

// Count total solutions
void CountSolutions(int k) {
    for (int i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i;
            if (k == n)
                totalSolutions++;
            else
                CountSolutions(k + 1);
        }
    }
}

// Print only half solutions (NO diagram)
void NQueens(int k) {
    for (int i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i;

            if (k == n) {
                if (printed < totalSolutions / 2) {
                    printed++;

                    cout << "Solution " << printed << ": ";
                    for (int j = 1; j <= n; j++)
                        cout << x[j] << " ";
                    cout << endl;
                }
            } else {
                NQueens(k + 1);
            }
        }
    }
}

int main() {
    cout << "Enter number of queens: ";
    cin >> n;

    // Count all solutions
    CountSolutions(1);

    cout << "Total Solutions: " << totalSolutions << endl;
    cout << "Showing Half Solutions:\n";

    // Print half
    NQueens(1);

    return 0;
}
//Topic- 04
//half of the solutions with Diagram
#include <iostream>
#include <cmath>
using namespace std;

int x[100];
int n;
int totalSolutions = 0;
int printed = 0;

// Check valid position
bool Place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

// Print board
void PrintBoard() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                cout << " Q ";
            else
                cout << " . ";
        }
        cout << endl;
    }
    cout << "-------------------\n";
}

// Count total solutions first
void CountSolutions(int k) {
    for (int i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i;
            if (k == n)
                totalSolutions++;
            else
                CountSolutions(k + 1);
        }
    }
}

// Print only half solutions
void NQueens(int k) {
    for (int i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i;

            if (k == n) {
                if (printed < totalSolutions / 2) {
                    printed++;

                    cout << "Solution: ";
                    for (int j = 1; j <= n; j++)
                        cout << x[j] << " ";
                    cout << endl;

                    PrintBoard();
                }
            } else {
                NQueens(k + 1);
            }
        }
    }
}

int main() {
    cout << "Enter number of queens: ";
    cin >> n;

    // Step 1: count all solutions
    CountSolutions(1);

    cout << "Total Solutions: " << totalSolutions << endl;
    cout << "Showing Half Solutions:\n";

    // Step 2: print half
    NQueens(1);

    return 0;
}
