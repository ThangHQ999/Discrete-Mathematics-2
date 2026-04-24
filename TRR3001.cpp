#include <bits/stdc++.h>
using namespace std;
int n, m = 0, u_start;
set<int> adj[105];
int degree[105] = {0};
vector<bool> vs;

void DFS(int u) {
    vs[u] = true;
    for (int i: adj[u]) {
        if (!vs[i]) {
            DFS(i);
        }
    }
}

void euler() {
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (degree[i] % 2 == 1) cnt++;
    }
    if (cnt == 0) {
        cout<< 1 << endl;
    } else if (cnt == 2) {
        cout<< 2 << endl;
    } else {
        cout<< 0 << endl;
    }
}

bool isConnected() {
    vs.assign(n+5, false);
    DFS(1);
    for (int i=1; i<=n; i++) {
        if (!vs[i]) return false;
    }
    return true;
}

void findEulerCycle(int start) {
    vector<int> ce;
    stack<int> st;
    st.push(start);

    while (!st.empty())
    {
        int u = st.top();
        if (!adj[u].empty()) {
            int v = *adj[u].begin();
            adj[u].erase(adj[u].begin());
            adj[v].erase(adj[v].find(u));
            st.push(v);
        } else {
            ce.push_back(u);
            st.pop();
        }
    }
    for (int i = ce.size() - 1; i >= 0; i--) {
        cout << ce[i] << (i == 0 ? "" : " ");
    }
    cout << endl;
}
int main() {
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    int t;
    cin>> t;
    cin>> n;
    if (t == 2) cin>> u_start;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int x;
            cin>> x;
            if (x == 1) {
                adj[i+1].insert(j+1);
                degree[i+1]++;
                m++;
            }
        }
    }
    m/=2;
    if (t == 1) {
        if (isConnected()) euler();
        else cout<< 0 << endl;
    } else if (t == 2) {
        findEulerCycle(u_start);
    }
    return 0;
}