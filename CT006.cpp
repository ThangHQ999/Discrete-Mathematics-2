#include <bits/stdc++.h>
using namespace std;
int n, u;
int a[101][101];
bool vs[101];
int path[102];
int total = 1e6;
vector<int> res;

void findHamilton(int cnt) {
    if (cnt == n) {
        if (a[path[cnt - 1]][u] > 0 && a[path[cnt - 1]][u] < 51) {
            vector<int> currCycle;
            int curTotal = 0;
            for (int i=0; i<n; i++) {
                currCycle.push_back(path[i]);
            }
            for (int i=1; i<n; i++) {
                curTotal += a[currCycle[i-1]][currCycle[i]];
            }
            curTotal += a[currCycle[n-1]][u];
            currCycle.push_back(u);
            if (curTotal < total) {
                total = curTotal;
                res = currCycle;
            }
        }
    }
    int lastNode = path[cnt - 1];
    for (int v=1; v<=n; v++) {
        if (a[lastNode][v] > 0 && a[lastNode][v] < 51 && !vs[v]) {
            vs[v] = true;
            path[cnt] = v;
            findHamilton(cnt+1);
            vs[v] = false;
        }
    }
}

int main() {
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
    cout<< (res.size() > 0 ? total : 0 )<< endl;
        for (int x: res) {
            cout<< x << " ";
        }
        cout<< endl;
    return 0;
}