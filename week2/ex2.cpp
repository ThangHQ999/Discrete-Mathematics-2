#include <bits/stdc++.h>
using namespace std;
// Dùng ma trận kề
int n; 
vector<vector<int>> adj;
vector<bool> visited;

void DFS(int u) {
    cout << u << " ";
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int main() {
    int t;
    cin>> t;
    while (t--) {
        cin >> n;
        
        adj.assign(n + 1, vector<int>());
        visited.assign(n + 1, false);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int x;
                cin >> x;
                if (x == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        DFS(1);
        cout << endl;
    }
    return 0;
}