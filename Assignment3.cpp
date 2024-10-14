/*
Name:Ashutosh Gadhave
Roll.No:TIA14
Batch:A                 
Problem Statement:  Write a program to implement Bellman-Ford Algorithm using 
Dynamic Programming and verify the time complexity.
*/
#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dst, wt;
};

int V, E; // Number of vertices and edges

void bellmanFord(vector<Edge>& edges) {
    vector<int> parent(V, -1); // To store the parent of each node
    vector<int> cost_parent(V, INT_MAX); // To store the cost of reaching each node
    vector<int> value(V, INT_MAX); // To store the minimum cost to reach each vertex
    
    // Source vertex initialization (assuming source is vertex 0)
    value[0] = 0; 

    bool updated; // To check if any update happens in a pass
    for(int i = 0; i < V - 1; ++i) { 
        updated = false;
        for(int j = 0; j < E; ++j) { 
            int U = edges[j].src;
            int V = edges[j].dst;
            int wt = edges[j].wt;

            if(value[U] != INT_MAX && value[U] + wt < value[V]) {
                value[V] = value[U] + wt;
                parent[V] = U;
                cost_parent[V] = value[V];
                updated = true;
            }
        }

        // If no updates occurred in the previous round, the algorithm can terminate early
        if(!updated) break;
    }

    // Check for negative weight cycle
    for(int j = 0; j < E; ++j) {
        int U = edges[j].src;
        int V = edges[j].dst;
        int wt = edges[j].wt;
        if(value[U] != INT_MAX && value[U] + wt < value[V]) {
            cout << "Graph contains a negative-weight cycle" << endl;
            return;
        }
    }

    // Printing the shortest paths and costs from the source
    for(int i = 1; i < V; ++i) {
        cout << "U->V: " << parent[i] << " -> " << i 
             << " | Cost to reach from source 0: " << value[i] << "\n";
    }
}

int main() {
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    
    vector<Edge> edges(E);
    cout << "Enter edges (src dst wt):" << endl;
    for(int i = 0; i < E; ++i) {
        cin >> edges[i].src >> edges[i].dst >> edges[i].wt;
    }

    bellmanFord(edges); // Run the Bellman-Ford algorithm

    return 0;
}
/*Enter number of vertices and edges: 5 8
Enter edges (src dst wt):
0 1 -1
0 2 4 
1 2 3 
1 3 2 
1 4 2 
3 2 5 
3 1 1 
4 3 -3
U->V: 0 -> 1 | Cost to reach from source 0: -1       
U->V: 1 -> 2 | Cost to reach from source 0: 2        
U->V: 4 -> 3 | Cost to reach from source 0: -2       
U->V: 1 -> 4 | Cost to reach from source 0: 1 */