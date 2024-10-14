/*
Name:Ashutosh Gadhave
Roll.No:TIA14
Batch:A                 */

#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    // Build the matrix
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // Printing the DP Matrix
    cout << "KnapSack DP Matrix: \n";
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            cout << K[i][w] << "\t";
        }
        cout << endl;
    }

    // Track which items were included in the optimal solution
    int res = K[n][W];
    cout << "\nMaximum Profit: " << res << endl;
    cout << "Items included (0-based index): ";

    w = W;
    vector<int> included_items;
    for (i = n; i > 0 && res > 0; i--) {
        if (res == K[i - 1][w]) // Item i-1 was excluded
            continue;
        else {
            included_items.push_back(i - 1); // Item i-1 was included
            res -= val[i - 1];
            w -= wt[i - 1];
        }
    }

    // Print included items
    for (int idx : included_items)
        cout << idx << " ";
    cout << endl;

    return K[n][W];
}

int main() {
    int n, W;

    // Take input from the user
    cout << "Enter the number of items: ";
    cin >> n;
    
    int profit[n], weight[n];

    cout << "Enter the profits of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter the maximum weight the knapsack can hold: ";
    cin >> W;

    // Call knapSack function
    knapSack(W, weight, profit, n);

    return 0;
}
/*Enter the number of items: 
4
Enter the profits of the items: 10
23
16
19
Enter the weights of the items: 5
10
8
6
Enter the maximum weight the knapsack can hold: 13
KnapSack DP Matrix: 
0       0       0       0       0       0       0       0       0       0       0      00       0
0       0       0       0       0       10      10      10      10      10      10     10       10      10
0       0       0       0       0       10      10      10      10      10      23     23       23      23
0       0       0       0       0       10      10      10      16      16      23     23       23      26
0       0       0       0       0       10      19      19      19      19      23     29       29      29

Maximum Profit: 29
Items included (0-based index): 3 0*/