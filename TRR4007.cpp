#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    if (a.w != b.w) return a.w < b.w;
    else if (a.u != b.u) return a.u < b.u;
    else return a.v < b.v;
}

struct DSU
{
    vector<int> parent;
    DSU(int n) {
        parent.resize(n+1);
        for (int i=1; i<=n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b) {
            parent[root_a] = root_b;
            return true;
        }
        return false;
    }
};


void kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), cmp);
    DSU dsu(n);
    vector<Edge> mst_edge;
    int mst_weight = 0;
    for (auto edge: edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mst_weight += edge.w;
            mst_edge.push_back(edge);
        }
    }
    if (mst_edge.size() < n-1) {
        cout<< 0 << endl;
    } else {
        cout<< mst_weight << endl;
    for (auto e: mst_edge) {
        cout<< e.u << " " << e.v << " " << e.w << endl;
    }
    }
}

int main() {
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    int n, m;
    cin>> n >> m;
    vector<Edge> edges;
    for (int i=1; i<=m; i++) {
        int u, v, w;
        cin>> u >> v >> w;
        edges.push_back({u, v, w});
    }
    kruskal(n, edges);
    return 0;
}