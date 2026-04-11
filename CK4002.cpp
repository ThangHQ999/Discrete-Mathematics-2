#include <bits/stdc++.h>
using namespace std;
int n, start, e;
set<int> adj[105];
vector<bool> vs;
vector<pair<int, int>> tree;

void hienthi() {
    if (tree.size() == n-1) {
        cout<< tree.size() << endl;
        for (auto it: tree) {
            cout<< it.first << " " << it.second << endl;
        }
        return;
    } else {
        cout<< 0 << endl;
    }
    
}

void DFS(int u) {
    vs[u] = true;
    for (int v: adj[u]) {
        if (!vs[v]) {
            tree.push_back({u, v});
            DFS(v);
        }
    }
}

void BFS(int u) {
    queue<int> q;
    vs[u] = true;
    q.push(u);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i: adj[v]) {
            if (!vs[i]) {
                tree.push_back({v, i});
                q.push(i);
                vs[i] = true;
            }
        }
    }
}

int main() {
    // freopen("CK.in", "r", stdin);
    // freopen("CK.OUT", "w", stdout);
    int t;
    cin>> t;
    cin>> n >> e >> start;
    vs.assign(n+5, false);
    for (int i=1; i<=e; i++) {
        int a, b;
        cin>> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    if (t == 1) {
        DFS(start);
    } else {
        BFS(start);
    }
    hienthi();
    return 0;
}