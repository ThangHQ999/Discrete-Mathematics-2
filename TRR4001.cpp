#include <bits/stdc++.h>
using namespace std;
int n, s, t;
int a[105][105] = {0};
bool vs[105];
vector<pair<int, int>> tree;

void Reset() {
    for(int i=0; i<105; i++) {
        vs[i] = false;
        for(int j=0; j<105; j++) a[i][j] = 0;
    }
    tree.clear();
}

void DFS(int u) {
    vs[u] = true;
    for (int v=1; v<=n; v++) {
        if (!vs[v] && a[u][v] == 1) {
            tree.push_back({min(v, u), max(v, u)});
            DFS(v);
        }
    }
}

void BFS(int u) {
    queue<int> q;
    q.push(u);
    vs[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int x=1; x<=n; x++) {
            if (!vs[x] && a[v][x] == 1) {
                vs[x] = true;
                tree.push_back({min(v, x), max(v, x)});
                q.push(x);
            }
        }
    }
    
}


int main() {
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    
    if (!(cin >> t)) return 0;
    if (!(cin >> n >> s)) return 0;
    Reset();
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>> a[i][j];
        }
    }
    if (t == 1) {
        DFS(s);
    } else {
        BFS(s);
    }
        if (tree.size() == n-1) {
            cout<< n-1 << endl;
            for (auto edge: tree) {
                cout<< edge.first << " " << edge.second << endl;
            }
        } else {
            cout<< 0 << endl;
        }
    
    return 0;
}