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

    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        vector<bool> visited(V, false);

        for (int count = 0; count < V - 1; count++) {
            int u = -1;
            for (int i = 0; i < V; i++) {
                if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                    u = i;
            }
            visited[u] = true;

            
            for (int v = 0; v < V; v++) {
                if (!visited[v] && matrix[u][v] && dist[u] != INT_MAX 
                    && dist[u] + matrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + matrix[u][v];
                }
            }
        }

        cout << "Vertex\tDistance from Source\n";
        for (int i = 0; i < V; i++) {
            cout << i << "\t" << dist[i] << endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addedge(10, 0, 1);
    g.addedge(5, 0, 2);
    g.addedge(33, 1, 3);
    g.addedge(12, 2, 3);
    g.addedge(21, 3, 4);

    cout << "Graph adjacency matrix:\n";
    g.printgraph();

    cout << "\nShortest paths from vertex 0:\n";
    g.dijkstra(0);

}
