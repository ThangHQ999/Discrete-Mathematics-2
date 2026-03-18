#include <bits/stdc++.h>
using namespace std;
int v, e;
vector<pair<int, int>> edges;
int degreeIn[105] = {0};
int degreeOut[105] = {0};
int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t;
    cin>> t;
    cin>> v;
    int a[v][v] = {0};
    for (int i=0; i<v; i++) {
        for (int j=0; j<v; j++) {
            cin>> a[i][j];
        }
    }
    for (int i=0; i<v; i++) {
        for (int j=0; j<v; j++) {
            if (a[i][j] == 1) {
                edges.push_back({i + 1, j + 1});
                degreeOut[i+1]++;
                degreeIn[j+1]++;
            }
        }
    }
    e = edges.size();
    sort(edges.begin(), edges.end());
    if (t == 1) {
        for (int i=1; i<=v; i++) {
            cout<< degreeIn[i] << " " << degreeOut[i] << endl;
        }
    } else {
        cout<< v << " " << e << endl;
        for (auto it: edges) {
            cout<< it.first << " " << it.second << endl;
        }
    }
    return 0;
}