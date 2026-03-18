#include <bits/stdc++.h>
using namespace std;

int V, k, u;
vector<set<int>> adj;
vector<set<int>> dsk;
vector<bool> vs;
vector<int> ec;
int degc[105], degt[105];
int mtk[105][105];

void dfs(int x) {
    vs[x] = true;
    for (int v : dsk[x]) {
        if (!vs[v]) dfs(v);
    }
}

bool lienthong() {
    vs.assign(V + 5, false);
    dfs(1);
    for (int i = 1; i <= V; i++) {
        if (!vs[i]) return false;
    }
    return true;
}

int Ktra() {
    if (!lienthong()) return 0;
    int cnt = 0;
    for (int i = 1; i <= V; i++) {
        int x = abs(degc[i] - degt[i]);
        if (x == 1) cnt++;
        if (x > 1) return 0;
    }
    if (cnt == 0) return 1;
    else if (cnt == 2) return 2;
    else return 0;
}

void euler(int v) {
    stack<int> st;
    st.push(v);
    while (!st.empty()) {
        int x = st.top();
        if (!adj[x].empty()) {
            int y = *adj[x].begin();
            st.push(y);
            adj[x].erase(y);
        } else {
            st.pop();
            ec.push_back(x);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;

    if (T == 1) {
        cin >> V;
    } else if (T == 2) {
        cin >> V >> u;
    }

    adj.assign(V + 5, set<int>());
    dsk.assign(V + 5, set<int>());
    vs.assign(V + 5, false);
    memset(mtk, 0, sizeof(mtk));
    memset(degc, 0, sizeof(degc));
    memset(degt, 0, sizeof(degt));
    ec.clear();

    for (int i = 1; i <= V; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            int l; cin >> l;
            mtk[i][l] = 1;
        }
    }

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (mtk[i][j]) {
                degc[i]++;
                degt[j]++;
                adj[i].insert(j);
                dsk[i].insert(j);
                dsk[j].insert(i);
            }
        }
    }

    if (T == 1) {
        cout << Ktra();
    } else if (T == 2) {
        if (Ktra() != 1) return 0;
        euler(u);
        reverse(ec.begin(), ec.end());
        for (int x : ec) cout << x << " ";
    }

    return 0;
}