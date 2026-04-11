#include <bits/stdc++.h>
using namespace std;
int n;
int a[105][105];
vector<pair<int, int>> bridges;
int dfn[105], low[105], timer = 0;

void DFS(int u, int p = -1) {
    dfn[u] = low[u] = ++timer;
    for (int v=1; v<=n; v++) {
        if (a[u][v] == 0) continue; 
        if (v == p) continue;
        if (dfn[v]) {
            low[u] = min(low[u], dfn[v]);
        } else {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                bridges.push_back({min(u, v), max(u, v)});
            }
        }
    }
}

int main() {
    // freopen("TK.INP", "r" ,stdin);
    // freopen("TK.OUT", "w" ,stdout);
    cin>> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>> a[i][j];
        }
    }
    memset(dfn, 0, sizeof(dfn));
    for (int i=1; i<=n; i++) {
        if (!dfn[i]) DFS(i);
    }
    sort(bridges.begin(), bridges.end());
    cout<< bridges.size() << endl;
    for (auto x: bridges) {
        cout<< x.first << " " << x.second << endl;  
    }
    return 0;
}