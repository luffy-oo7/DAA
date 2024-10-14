/*
Name:Ashutosh Gadhave
Roll.No:TIA14
Batch:A                 */


#include <iostream>
#include <vector>
#include <algorithm> // Include for std::sort

using namespace std;

struct Item {
    int value;
    int weight;
};

// Comparator function to sort items based on value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // Sort in descending order
}

// Function to get the maximum total value in the knapsack
double fractionalKnapsack(int W, Item arr[], int n) {
    // Sort items by value-to-weight ratio
    sort(arr, arr + n, compare);

    int curWeight = 0;  
    double finalValue = 0.0;  
    cout << "Included items:\n";
    
    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
            cout << "Item " << i + 1 << ": Value = " << arr[i].value << ", Weight = " << arr[i].weight << "\n";
        } else {
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            cout << "Item " << i + 1 << ": Value = " << arr[i].value << ", Weight = " << arr[i].weight << " (partially included)\n";
            break;
        }
    }

    cout << "Excluded items:\n";
    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight > W) {
            cout << "Item " << i + 1 << ": Value = " << arr[i].value << ", Weight = " << arr[i].weight << "\n";
        }
    }

    return finalValue;
}

int main() {
    int n, W;

    // Take input from the user
    cout << "Enter the maximum weight the knapsack can hold: ";
    cin >> W;

    cout << "Enter the number of items: ";
    cin >> n;

    Item arr[n];

    cout << "Enter the value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " - Value: ";
        cin >> arr[i].value;
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> arr[i].weight;
    }

    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n) << endl;

    return 0;
}
/*Enter the maximum weight the knapsack can hold: 30
Enter the number of items: 3
Enter the value and weight of each item:
Item 1 - Value: 20
Item 1 - Weight: 10
Item 2 - Value: 30
Item 2 - Weight: 18
Item 3 - Value: 50
Item 3 - Weight: 20
Maximum value we can obtain = Included items:
Item 1: Value = 50, Weight = 20
Item 2: Value = 20, Weight = 10
Item 3: Value = 30, Weight = 18 (partially included)
Excluded items:
Item 1: Value = 50, Weight = 20
Item 2: Value = 20, Weight = 10
Item 3: Value = 30, Weight = 18
70*/