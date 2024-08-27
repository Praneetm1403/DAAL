// #include <iostream>
// #include <vector>
// #include <climits>
// using namespace std;

// // Function to find the vertex with the minimum key value that is not included in MST
// int minKey(vector<int>& key, vector<bool>& mstSet, int V) {
//     int min = INT_MAX, minIndex;

//     for (int v = 0; v < V; v++) {
//         if (!mstSet[v] && key[v] < min) {
//             min = key[v];
//             minIndex = v;
//         }
//     }
//     return minIndex;
// }

// // Function to print the constructed MST
// void printMST(vector<int>& parent, vector<vector<int>>& graph, int V) {
//     cout << "Edge \tWeight\n";
//     for (int i = 1; i < V; i++) {
//         cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
//     }
// }

// // Function to construct and print MST using Prim's algorithm
// void primMST(vector<vector<int>>& graph, int V) {
//     // Array to store constructed MST
//     vector<int> parent(V);
//     // Key values to pick minimum weight edge in cut
//     vector<int> key(V, INT_MAX);
//     // To represent set of vertices included in MST
//     vector<bool> mstSet(V, false);

//     // Always include first 1st vertex in MST.
//     key[0] = 0;      // Make key 0 so that this vertex is picked as first vertex
//     parent[0] = -1;  // First node is always root of MST

//     for (int count = 0; count < V - 1; count++) {
//         // Pick the minimum key vertex from the set of vertices not yet included in MST
//         int u = minKey(key, mstSet, V);

//         // Add the picked vertex to the MST Set
//         mstSet[u] = true;

//         // Update key value and parent index of the adjacent vertices of the picked vertex.
//         for (int v = 0; v < V; v++) {
//             // Update the key only if graph[u][v] is smaller than key[v]
//             if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
//                 parent[v] = u, key[v] = graph[u][v];
//             }
//         }
//     }

//     // Print the constructed MST
//     printMST(parent, graph, V);
// }

// int main() {
//     int V;
//     cout << "Enter the number of vertices: ";
//     cin >> V;

//     vector<vector<int>> graph(V, vector<int>(V));

//     cout << "Enter the adjacency matrix (enter 0 for no edge):\n";
//     for (int i = 0; i < V; i++) {
//         for (int j = 0; j < V; j++) {
//             cin >> graph[i][j];
//         }
//     }

//     primMST(graph, V);

//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int> > matrix; 

public:
    Graph(int vertices) {
        V = vertices;
        matrix.resize(V, vector<int>(V, 0)); 
    }


    void addedge(int weight, int i, int j) {
        if (i < V && j < V) {
            matrix[i][j] = weight;
            matrix[j][i] = weight;
            return;
        }
        return; 
    }

    void printgraph() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices,noedges;
    cout << "Enter vertices: ";
    cin >> vertices;
    Graph g(vertices);

    g.addedge(1, 0, 1);
    g.addedge(2, 0, 2);
    g.addedge(3, 0, 3);
    g.addedge(4, 0, 4);
    g.addedge(5, 1, 2);
    g.addedge(6, 1, 3);
    g.addedge(7, 1, 4);
    g.addedge(8, 2, 3);
    g.addedge(9, 2, 4);
    g.addedge(10, 3, 4);
    g.printgraph();
    return 0;
}