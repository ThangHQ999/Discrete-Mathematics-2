#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int parent[105];

void floyd(int n) {
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    vector<vector<int>> next_node(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w; cin >> w;
            if (i == j) dist[i][j] = 0;
            else if (w > 0 && w < 51) {
                dist[i][j] = w;
                next_node[i][j] = j;
            }
        }
    }

    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) { 
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next_node[i][j] = next_node[i][k];
                    }
                }
            }
        }
    }
    int s = -1, t = -1, ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (dist[i][j] != INF && dist[i][j] > ans) {
                ans = dist[i][j];
                s = i; t = j;
            }   
        }
    }
    if (ans == 0) {
        cout<< 0 << endl;
    } else {
        cout<< s << " " << t << " " << ans << endl;
        int curr = s;
        while (curr != 0) {
            cout << curr << " ";
            if (curr == t) break;
            curr = next_node[curr][t];
        }
        cout << endl;
    } 
}

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    int n;
    cin>> n;
    floyd(n);
    return 0;
}