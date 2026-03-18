#include <bits/stdc++.h>
using namespace std;
int n, u;
int a[101][101];
bool vs[101];
int path[102];
vector<vector<int>> results;

void findHamilton(int cnt) {
    if (cnt == n) {
        if (a[path[cnt - 1]][u] == 1) {
            vector<int> currCycle;
            for (int i=0; i<n; i++) {
                currCycle.push_back(path[i]);
            }
            currCycle.push_back(u);
            results.push_back(currCycle);
        }
    }
    int lastNode = path[cnt - 1];
    for (int v=1; v<=n; v++) {
        if (a[lastNode][v] == 1 && !vs[v]) {
            vs[v] = true;
            path[cnt] = v;
            findHamilton(cnt+1);
            vs[v] = false;
        }
    }
}

int main() {
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin>> n >> u;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) vs[i] = false;
    path[0] = u;
    vs[u] = true;
    findHamilton(1);
    for (auto res: results) {
        for (int x: res) {
            cout<< x << " ";
        }
        cout<< endl;
    }
    cout<< results.size() << endl;
    return 0;
}