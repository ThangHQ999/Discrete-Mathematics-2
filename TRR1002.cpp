#include <bits/stdc++.h>
using namespace std;
int v, e;
vector<int> adj[105];
int degree[105] = {0};
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
        for (int j=i; j<v; j++) {
            if (a[i][j] == 1) {
                adj[i+1].push_back(j+1);
                adj[j+1].push_back(i+1);
                degree[i+1]++;
                degree[j+1]++;
            }
        }
    }
    
    if (t == 1) {
        for (int i=1; i<=v; i++) {
            cout<< degree[i] << " ";
        }
    } else {
        cout<< v << endl;
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