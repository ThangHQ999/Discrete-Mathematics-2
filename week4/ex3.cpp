#include <bits/stdc++.h>
using namespace std;
// Tìm đường đi giữa 2 đỉnh bằng DFS
vector<bool> vs;
int v, e, s, t;
vector<vector<int>> adj;
vector<int> parent;

void ReInit() {
    vs.assign(v + 5, false);
    parent.assign(v + 5, 0);
    adj.assign(v + 5, vector<int>());
}

void DFS(int a) {
    vs[a] = true;
    for (int x: adj[a]) {
        if (!vs[x]) {
            parent[x] = a;
            DFS(x);
        }
    }
}

void Path(int s, int t) {
    DFS(s);
    if (!vs[t]) {
        cout<< -1;
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
    int test;
    cin>> test;
    while (test--)
    {
        cin>> v >> e >> s >> t;
        ReInit();
        for (int i=0; i<e; i++) {
            int a, b;
            cin>> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        Path(s, t);
        cout<< endl;
    }
    return 0;
}