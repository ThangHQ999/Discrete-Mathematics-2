#include <bits/stdc++.h>
using namespace std;
// Dùng danh sách cạnh
int n, m;
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
    cin >> t;
    while (t--) {
        cin >> n >> m;
        
        adj.assign(n + 1, vector<int>());
        visited.assign(n + 1, false);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            sort(adj[i].begin(), adj[i].end());
        }

        DFS(1);
        cout << endl;
    }
    return 0;
}