#include <bits/stdc++.h>
using namespace std;
int n, m, u;
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
        return;
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
    cin>> n >> m >> u;
    memset(a, 0, sizeof(a));
    for (int i=0; i<m; i++) {
        int x, y;
        cin>> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    memset(vs, false, sizeof(vs));
    path[0] = u;
    vs[u] = true;
    findHamilton(1);
    cout<< results.size() << endl;
    for (const auto& res: results) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << (i == res.size() - 1 ? "" : " ");
        }
        cout<< endl;
    }
    return 0;
}