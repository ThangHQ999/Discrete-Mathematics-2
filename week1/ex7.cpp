#include <bits/stdc++.h>
using namespace std;
// CHUYỂN TỪ DANH SÁCH KỀ SANG DANH SÁCH CẠNH
int main() {
    int n;
    cin>> n;
    cin.ignore();
    vector<pair<int, int>> edges;
    for (int i=1; i<=n; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int token;
        while (ss >> token)
        {
            if (i < token) edges.push_back({i, token});
        }
    }
    sort(edges.begin(), edges.end());
    for (auto x : edges) {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}