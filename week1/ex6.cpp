#include <bits/stdc++.h>
using namespace std;
// CHUYỂN DANH SÁCH CẠNH SANG DANH SÁCH KỀ

int main() {
    int t;
    cin>> t;
    while (t--)
    {
        int v, e;
        cin>> v >> e;
        vector<vector<int>> l(v+1);
        for (int i=0; i<e; i++) {
            int a, b;
            cin>> a >> b;
            l[a].push_back(b);
            l[b].push_back(a);// nếu có hướng thì xóa bỏ dòng này
        }
        for (int i=1; i<=v; i++) {
            cout<< i << ":";
            sort(l[i].begin(), l[i].end());
            for (int k: l[i]) {
                cout<< " " << k;
            }
            cout<< endl;
        }
    }
    return 0;
}