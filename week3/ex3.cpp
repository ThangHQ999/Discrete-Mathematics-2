#include <bits/stdc++.h>
using namespace std;
// BFS với ma trận kề
vector<bool> vs;
int v, e;
int a[100][100];

void BFS(int u) {
    queue<int> q;
    q.push(u);
    vs[u] = true;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        cout<< f << " ";
        for (int i=1; i<=v; i++) {
            if (!vs[i] && a[f][i] == 1) {
                q.push(i);
                vs[i] = true;
            }
        }
    }
}

int main() {
    int t;
    cin>> t;
    while (t--)
    {
        cin>> v >> e;
        vs.assign(v+5, false);
        for (int i=1; i<=e; i++) {
            for (int j=1; j<=e; j++) {
                cin>> a[i][j];
            }
        }
        BFS(1);
        cout<< endl;
    }
    return 0;
}