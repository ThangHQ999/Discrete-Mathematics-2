#include <bits/stdc++.h>
using namespace std;
int v, e;
set<int> adj[105];
int degreeIn[105] = {0};
int degreeOut[105] = {0};
int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t;
    cin>> t;
    cin>> v;
    for (int i=1; i<=v; i++) {
        int k; cin>> k;
        for (int j=1; j<=k; j++) {
            int x;
            cin>> x;
            adj[i].insert(x);
            degreeOut[i]++;
            degreeIn[x]++;
        }
    }
    if (t == 1) {
        for (int i=1; i<=v; i++) {
            cout<< degreeIn[i] << " " << degreeOut[i] << endl;
        }
    } else {
        cout<< v << endl;
        int a[v+1][v+1] = {0};
        for (int i=1; i<=v; i++) {
            for (int x: adj[i]) {
                a[i][x] = 1;
            }
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