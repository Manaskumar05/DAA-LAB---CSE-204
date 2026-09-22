#include <iostream>
#include <climits>
using namespace std;

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int graph[100][100];

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int key[100], parent[100];
    bool visited[100];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {

        int u = -1;

        
        for (int i = 0; i < V; i++) {
            if (!visited[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        visited[u] = true;

        
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !visited[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nEdges in MST:\n";
    int total = 0;

    for (int i = 1; i < V; i++) {
        cout << char(parent[i] + 'A') << " - "
             << char(i + 'A')
             << " : " << key[i] << endl;

        total += key[i];
    }

    cout << "Total weight = " << total << endl;

    return 0;
}