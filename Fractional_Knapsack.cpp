#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    float profit;
    float weight;
    float ratio;
    int index; // Original position
};

// Sort in decreasing order of profit/weight ratio
bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter profits:\n";
    for(int i = 0; i < n; i++) {
        cin >> items[i].profit;
        items[i].index = i; // store original index
    }

    cout << "Enter weights:\n";
    for(int i = 0; i < n; i++) {
        cin >> items[i].weight;
        items[i].ratio = items[i].profit / items[i].weight; // compute profit/weight
    }

    float capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Sort items by profit/weight ratio
    sort(items.begin(), items.end(), cmp);

    vector<float> x(n, 0.0); // solution vector initialized to 0
    float remaining = capacity;
    float maxProfit = 0.0;

    for(int i = 0; i < n; i++) {
        if(items[i].weight <= remaining) {
            x[items[i].index] = 1.0;
            remaining -= items[i].weight;
            maxProfit += items[i].profit;
        } else {
            x[items[i].index] = remaining / items[i].weight;
            maxProfit += items[i].profit * (remaining / items[i].weight);
            break;
        }
    }


    // Print solution vector
    cout << "\nSolution vector (fractions taken in original order):\n";
    for(int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;

    cout << "\nMaximum Profit: " << maxProfit << endl;

    return 0;
}
