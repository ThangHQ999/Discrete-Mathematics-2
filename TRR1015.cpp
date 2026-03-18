#include <bits/stdc++.h>
using namespace std;
int v, e;
vector<pair<int, int>> edges;
int degreeOut[105] = {0};
int degreeIn[105] = {0};
int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t;
    cin>> t;
    cin>> v >> e;
    for (int i=0; i<e; i++) {
        int a, b;
        cin>> a >> b;
        edges.push_back({a, b});
        degreeOut[a]++;
        degreeIn[b]++;
    }
    sort(edges.begin(), edges.end());
    if (t == 1) {
        for (int i=1; i<=v; i++) {
            cout<< degreeIn[i] << " " << degreeOut[i] << endl;
        }
    } else {
        cout<< v << endl;
        int a[v+1][v+1] = {0};
        for (auto it: edges) {
            a[it.first][it.second] = 1; 
        }
        for (int i=1; i<=v; i++) {
            for (int j=1; j<=v; j++) {
                cout<< a[i][j] << " ";
            }
            cout<< endl;
        }
    }
    return 0;
}