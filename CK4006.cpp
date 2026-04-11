// Bài này t chưa AC đâu (ảo lắm)
#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
};

bool cmpEdge(const Edge& a, const Edge& b) {
    return a.w < b.w;
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
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            parent[rootB] = rootA;
            return true;
        }
        return false;
    }
};

void kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), cmpEdge);
    DSU dsu(n);
    vector<Edge> mst;
    int mst_weight = 0;
    for (Edge e: edges) {
        if (dsu.unite(e.u, e.v)) {
            mst_weight += e.w;
            mst.push_back(e);
        }
    }
    if (mst.size() == n-1) {
        cout<< mst_weight << endl;
        for (Edge e: mst) {
            cout<< e.u << " " << e.v << " " << e.w << endl;
        }
    } else {
        cout<< 0 << endl;
    }
}


int main() {
    // freopen("CK.INP", "r", stdin);
    // freopen("CK.OUT", "w", stdout);
    int n;
    cin>> n;
    vector<Edge> edges;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int w; cin>> w;
            if (w > 0 && w < 10000) {
                edges.push_back({i, j, w});
            }
        }
    }
    kruskal(n, edges);
    return 0;
}