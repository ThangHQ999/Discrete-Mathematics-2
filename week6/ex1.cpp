#include <bits/stdc++.h>
using namespace std;
// Thuật toán tìm đường đi Euler của đồ thị có hướng liên thông yếu được biểu diễn dưới dạng danh sách kề
int n, m = 0, u_start = 1;
set<int> adj[105];
int degreeOut[105] = {0};
int degreeIn[105] = {0};

void findEulerPath(int start) {
    vector<int> ce;
    stack<int> st;
    st.push(start);

    while (!st.empty())
    {
        int u = st.top();
        if (!adj[u].empty()) {
            int v = *adj[u].begin();
            adj[u].erase(adj[u].begin());
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
    cin>> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int x;
            cin>> x;
            if (x == 1) {
                adj[i].insert(j);
                degreeOut[i]++;
                degreeIn[j]++;
                m++;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (degreeOut[i] - degreeIn[i] == 1) {
            u_start = i;
            break;
        } 
    }
    findEulerPath(u_start);
    return 0;
}