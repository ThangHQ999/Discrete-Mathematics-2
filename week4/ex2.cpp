#include <bits/stdc++.h>
using namespace std;
// Liệt kê các cạnh cầu dùng DFS
vector<bool> vs;
int v, e;
vector<vector<int>> adj;
vector<pair<int, int>> edges; 

void ReInit() {
    vs.assign(v + 1, false);
}

void DFS2(int u, int x, int y) {
    vs[u] = true;
    for (int i: adj[u]) {
        if ((u == x && i == y) || (u == y && i == x)) continue;
        if (!vs[i]) {
            DFS2(i, x, y);
        }
    }
}

void DFS(int u) {
    vs[u] = true;
    for (int i: adj[u]) {
        if (!vs[i]) {
            DFS(i);
        }
    }
}

void findBridges() {
    int tplt = 0;
    for (int i=1; i<=v; i++) {
        if (!vs[i]) {
            tplt++;
            DFS(i);
        }
    }
    for (auto it: edges) {
        ReInit();
        int dem = 0;
        int x = it.first, y = it.second;
        for (int j=1; j<=v; j++) {
            if (!vs[j]) {
                dem++;
                DFS2(j, x, y);
            }
        }
        if (dem > tplt) {
            cout<< x << " " << y << endl;
        }
    }
}

int main() {
    int t;
    cin>> t;
    while (t--)
    {
        cin>> v >> e;
        adj.assign(v + 1, vector<int>());
        vs.assign(v+1, false);
        edges.clear();
        for (int i=0; i<e; i++) {
            int a, b;
            cin>> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            edges.push_back({a, b});
        }
        findBridges();
    }
    return 0;
}