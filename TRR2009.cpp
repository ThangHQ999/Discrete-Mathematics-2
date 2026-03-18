#include <bits/stdc++.h>
using namespace std;
set<int> adj[105];
vector<bool> vs;
set<int> res[105];
int cnt = 0;
int n;

void DFS(int u) {
    res[cnt].insert(u);
    vs[u] = true;
    for (int v: adj[u]) {
        if (!vs[v]) {
            DFS(v);
        }
    }
}

void cntConnected() {
    for (int i=1; i<=n; i++) {
        if (!vs[i]) {
            cnt++;
            DFS(i);
        }
    }
    cout<< cnt << endl;
    for (int i=1; i<=cnt; i++) {
        for (int x: res[i]) {
            cout<< x << " ";
        }
        cout<< endl;
    }
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin>> n;
    vs.assign(n+5, false);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int x;
            cin>> x;
            if (x == 1) adj[i].insert(j);
        }
    }
    cntConnected();
    return 0;
}