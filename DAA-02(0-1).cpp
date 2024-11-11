#include <iostream>
#include <algorithm>
using namespace std;
struct Item {
    int profit, weight;
};
int knapSack(int W, Item arr[], int n) {
    int K[n + 1][W + 1]; 
    bool included[n] = {false};
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (arr[i - 1].weight <= w)
                K[i][w] = max(arr[i - 1].profit + K[i - 1][w - arr[i - 1].weight], 
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    cout << "\nKnapSack DP Matrix:\n";
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            cout << K[i][w] << "\t";
        }
        cout << endl;
    }
    int res = K[n][W];
    cout << "\nMaximum Profit: " << res << endl;
    int w = W;
    
      for (int i = n; i > 0 && res > 0; --i) {
        if (res != K[i - 1][w]) {  // Item i-1 was included
            included[i - 1] = 1;    // Mark item as included
            res -= arr[i - 1].profit;
            w -= arr[i - 1].weight;
        }
    }

    // Print included and not-included items in the desired format
    for (int i = 0; i < n; ++i) {
        cout << "item " << i + 1 << " : " << included[i] << endl;
    }

    return K[n][W];
}
int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    Item arr[n]; 
    cout << "Enter the profits and weights of the items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].profit >> arr[i].weight;
    }
    cout << "Enter the maximum weight the knapsack can hold: ";
    cin >> W;
    knapSack(W, arr, n);
    return 0;
}
