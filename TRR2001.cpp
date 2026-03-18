#include <bits/stdc++.h>
using namespace std;
int n, u, v;
vector<bool> vs;
int parent[105] = {0};
set<int> adj[105];
int a[105][105];

void cntPath(int start, int en) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[start][i] == 1 && a[i][en] == 1) {
            cnt++;
        }
    }
    cout << cnt << endl;
}

void DFS(int s) {
    vs[s] = true;
        for (int x: adj[s]) {
            if (!vs[x]) {
                parent[x] = s;
                DFS(x);
            }
        }
}

void Path(int s, int t) {
    DFS(s);
    if (!vs[t]) {
        cout<< 0 << endl;
    } else {
        vector<int> path;
        while (t != s)
        {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (int x: path) {
            cout<< x << " ";
        }
    }
}


int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    int t;
    cin>> t;
    cin>> n >> u >> v;
    vs.assign(n+5, false);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>> a[i][j];
            if (a[i][j] == 1) adj[i].insert(j);
        }
    }
    if (t == 1) {
        cntPath(u, v);
    } else {
        Path(u, v);
    }
    return 0;
}