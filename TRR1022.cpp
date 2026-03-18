#include <bits/stdc++.h>
using namespace std;
const int mod = 10000;
struct Edge {
    int u, v, w;
};
bool cmp(Edge a, Edge b) {
    if (a.u == b.u) return a.v < b.v;
    return a.u < b.u;
}
int v, e;

vector<Edge> edges;
int degreeIn[105] = {0};
int degreeOut[105] = {0};
int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t;
    cin>> t;
    cin>> v >> e;
    for (int i=0; i<e; i++) {
        int a, b, w;
        cin>> a >> b >> w;
        edges.push_back({a, b, w});
        degreeOut[a]++;
        degreeIn[b]++;
    }
    sort(edges.begin(), edges.end(), cmp);
    if (t == 1) {
        for (int i=1; i<=v; i++) {
            cout<< degreeIn[i] << " " << degreeOut[i] << endl;
        }
    } else {
        cout<< v << endl;
        vector<vector<int>> a(v, vector<int>(v, mod));
        for (int i=0; i<v; i++) a[i][i] = 0;
        for (auto edge: edges) {
            a[edge.u-1][edge.v-1] = edge.w;
        }
        for (int i=0; i<v; i++) {
            for (int j=0; j<v; j++) {
                cout<< a[i][j] << " ";
            }
            cout<< endl;
        }
    }
    return 0;
}