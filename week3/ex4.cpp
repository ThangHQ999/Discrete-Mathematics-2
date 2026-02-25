#include <bits/stdc++.h>
using namespace std;
// DuyetTPLT với BFS
// Ngoài ra còn có thể sử dụng nhiều pp khác để xác định số tplt (DSU(Disjoint Set Union), ...)
vector<bool> vs;
int v, e;
vector<vector<int>> adj;

void BFS(int u) {
    queue<int> q;
    q.push(u);
    vs[u] = true;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (int i: adj[f]) {
            if (!vs[i]) {
                vs[i] = true;
                q.push(i);
            }
        }
    }
}

int DuyetTPLT() {
    int tplt = 0;
    for (int i=1; i<=v; i++) {
        if (!vs[i]) {
            tplt++;
            BFS(i);
        }
    }
    return tplt;
}

int main() {
    int t;
    cin>> t;
    while (t--)
    {
        cin>> v >> e;
        adj.assign(v + 5, vector<int>());
        vs.assign(v+5, false);
        for (int i=0; i<e; i++) {
            int a, b;
            cin>> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cout<< DuyetTPLT() << endl;
    }
    return 0;
}