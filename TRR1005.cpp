#include <bits/stdc++.h>
using namespace std;
int v, e;
vector<pair<int, int>> edges;
int degree[105] = {0};
int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t;
    cin>> t;
    cin>> v >> e;
    for (int i=0; i<e; i++) {
        int a, b;
        cin>> a >> b;
        if (a > b) swap(a, b);
        edges.push_back({a, b});
        degree[a]++;
        degree[b]++;
    }
    sort(edges.begin(), edges.end());
    if (t == 1) {
        for (int i=1; i<=v; i++) {
            cout<< degree[i] << " ";
        }
    } else {
        cout<< v << endl;
        vector<int> adj[105];
        for (auto it: edges) {
            adj[it.first].push_back(it.second);
            adj[it.second].push_back(it.first);
        }
        for (int i=1; i<=v; i++) {
            cout<< adj[i].size() << " ";
            for (int x: adj[i]) {
                cout<< x << " ";
            }
            cout<< endl;
        }
    }
    return 0;
}