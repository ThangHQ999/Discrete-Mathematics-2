#include <bits/stdc++.h>
using namespace std;
// BFS với danh sách kề
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
        cout<< f << " ";
        for (int i: adj[f]) {
            if (!vs[i]) {
                vs[i] = true;
                q.push(i);
            }
        }
    }
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
        BFS(1);
        cout<< endl;
    }
    return 0;
}