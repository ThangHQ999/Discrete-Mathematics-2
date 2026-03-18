#include <bits/stdc++.h>
using namespace std;
int n;
set<int> adj[105];
int dfn[105], low[105], timer = 0;
bool isArticulation[105];

void DFS(int u, int p = -1) {
    dfn[u] = low[u] = ++timer;
    int children = 0;
    for (int v: adj[u]) {
        if (v == p) continue;
        if (dfn[v]) {
            low[u] = min(low[u], dfn[v]);
        } else {
            children++;
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if (p != -1 && low[v] >= dfn[u]) {
                isArticulation[u] = true;
            }
        }
    }
    if (p == -1 && children > 1) {
        isArticulation[u] = true;
    }
}

int main() {
    freopen("TK.INP", "r" ,stdin);
    freopen("TK.OUT", "w" ,stdout);
    cin>> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int x;
            cin>> x;
            if (x == 1) adj[i].insert(j);
        }
    }
    for (int i=1; i<=n; i++) {
        DFS(i, -1);
    }
    vector<int> e;
    for (int i=1; i<=n; i++) {
        if (isArticulation[i]) e.push_back(i);
    }
    cout<< e.size() << endl;
    for (int x: e) {
        cout<< x << " ";  
    }
    return 0;
}