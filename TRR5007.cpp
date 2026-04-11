#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, s, t;
int parent[105];

struct Edge
{
    int u, v, w;
};

vector<Edge> edges;

void bellmanFord() {
    vector<int> dist(n+5, INF);
    dist[s] = 0;

    for (int i=1; i<n; i++) {
        for (auto e: edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
            }
        }
    }

    bool hasNegativeCycle = false;
    for (auto e: edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout<< -1 << endl;
    } else if (dist[t] == INF) {
        cout<< 0 << endl;
    } else {
        cout<< dist[t] << endl;
        vector<int> path;
        while (s != t)
        {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        for (int i=path.size() -1; i>=0; i--) {
            cout<< path[i] << " ";
        }
        cout<< endl;
    }
}

int main() {
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);
    cin>> n >> s >> t;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int x;
            cin>> x;
            if (x!=10000 && x!= 0) {
                edges.push_back({i, j, x});
            }
        }
    }
    bellmanFord();
    return 0;
}