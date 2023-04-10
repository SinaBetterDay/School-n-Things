#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100;

vector<int> adjList[MAXN];
int adjMatrix[MAXN][MAXN];

int main() {
    int n = 7, m = 12;
    int edges[][2] = {{1, 2}, {1, 3}, {1, 4}, {2, 4}, {2, 5}, {3, 6}, {4, 3}, {4, 6}, {4, 7}, {5, 4}, {5, 7}, {7, 6}};
    
    for (int i = 0; i < m; i++) {
        int u = edges[i][0], v = edges[i][1];
        adjList[u].push_back(v);
        adjMatrix[u][v] = 1;
    }

    cout << "Adjacency List:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
