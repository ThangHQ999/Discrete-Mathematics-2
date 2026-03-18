#include <bits/stdc++.h>
using namespace std;
int a[105][105];
vector<bool> vs;
int n;

void Reset() {
    vs.assign(n+5, false);
}

void DFS(int u, int m[105][105]) {
    vs[u] = true;
    for (int i=1; i<=n; i++) {
        if (!vs[i] && m[u][i]) {
            DFS(i, m);
        }
    }
}

bool allVisited() {
    for (int i=1; i<=n; i++) {
        if (!vs[i]) return false;
    }
    return true;
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin>> n;
    Reset();
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>> a[i][j];
        }
    }
    bool strong = false;
    DFS(1, a);
    if (allVisited()) {
        int b[105][105] = {0};
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                b[i][j] = a[j][i];
            }
        }
        Reset();
        DFS(1, b);
        if (allVisited()) strong = true;
    }
    if (strong) {
        cout<< 1 << endl;
    } else {
        int c[105][105] = {0};
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (a[i][j] == 1 || a[j][i] == 1) {
                    c[i][j] = 1;
                    c[j][i] = 1;
                }
            }
        }
        Reset();
        DFS(1, c);
        if (allVisited()) {
            cout<< 2 << endl;
        } else {
            cout<< 0 << endl;
        }
    }
    return 0;
}