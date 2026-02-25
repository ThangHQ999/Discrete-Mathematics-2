#include <bits/stdc++.h>
using namespace std;
// Dùng danh sách kề
vector<bool> vs;
int v, e, u;
vector<vector<int>> l;

void DFS(int u) {
    cout<< u << " ";
    vs[u] = true;
    for (int i: l[u]) {
        if (!vs[i]) {
            DFS(i);
        }
    }
}

int main() {
    int t;
    cin>> t;
    while (t--)
    {
        cin>> v >> e >> u;
        l.assign(v + 1, vector<int>());
        vs.assign(v+1, false);
        for (int i=0; i<e; i++) {
            int a, b;
            cin>> a >> b;
            l[a].push_back(b);
            l[b].push_back(a);
        }
        DFS(u);
        cout<< endl;
    }
    return 0;
}