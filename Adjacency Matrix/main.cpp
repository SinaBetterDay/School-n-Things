#include<bits/stdc++.h>
using namespace std;

int findNewVertexOfIndegreeZero(vector<vector<int>> edge, int n) {
    for(int i = 1; i <= n; i++) {
        int c = 0;
        for(int j = 1; j <= n; j++) {
            if(edge[j][i] == 1) {
                c++;
            }
        }
        if(c == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n = 7;
    int m = 12;

    vector<vector<int>> edge(n + 1, vector<int>(n + 1, 0));
    edge[1][2] = 1;
    edge[1][3] = 1;
    edge[1][4] = 1;
    edge[2][4] = 1;
    edge[2][5] = 1;
    edge[3][6] = 1;
    edge[4][3] = 1;
    edge[4][6] = 1;
    edge[4][7] = 1;
    edge[5][4] = 1;
    edge[5][7] = 1;
    edge[7][6] = 1;

    int ans = findNewVertexOfIndegreeZero(edge, n);
    if(ans == -1) {
        cout << "There is no vertex with indegree 0." << endl;
    }
    else {
        cout << "The vertex with indegree 0 is " << ans << "." << endl;
    }

    return 0;
}
