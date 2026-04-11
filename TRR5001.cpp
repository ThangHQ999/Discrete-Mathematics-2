#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, s, t;
struct Edge
{
    int to, weight;
};
int parent[105];
vector<vector<Edge>> edges;
void dijkstra() {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(n+1, INF);
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty())
    {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto &edge: edges[u]) {
            int v = edge.to;
            int w = edge.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
    if (dist[t] != INF) {
        cout<< dist[t] << endl;
        vector<int> path;
        while (t != s)
        {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        for (int i=path.size() -1; i>= 0; i--) {
            cout<< path[i] <<  " ";
        }
        cout<< endl;
    } else {
        cout<< 0 << endl;
    }

}

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    cin>> n >> s >> t;
    edges.resize(n+5);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int x;
            cin>> x;
            if (x >0 && x<51) edges[i].push_back({j, x});
        }
    }
    dijkstra();
    return 0;
}