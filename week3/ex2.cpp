#include <bits/stdc++.h>
using namespace std;
// BFS với danh sách cạnh
vector<bool> vs;
int v, e;
vector<pair<int, int>> edges;

void BFS(int u) {
    queue<int> q;
    q.push(u);
    vs[u] = true;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        cout<< f << " ";
        for (int i=0; i<e; i++) {
            if (edges[i].first == f) {
                int neighbor = edges[i].second;
                if (!vs[neighbor]) {
                    vs[neighbor] = true;
                    q.push(neighbor);
                }
            } 
            if (edges[i].second == f) {
                int neighbor = edges[i].first;
                if (!vs[neighbor]) {
                    vs[neighbor] = true;
                    q.push(neighbor);
                }
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
        vs.assign(v+5, false);
        edges.clear();
        for (int i=0; i<e; i++) {
            int a, b;
            cin>> a >> b;
            edges.push_back({a, b});
        }
        BFS(1);
        cout<< endl;
    }
    return 0;
}