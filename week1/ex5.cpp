#include <bits/stdc++.h>
using namespace std;
// Chuyển đổi từ ma trận kề danh sách kề

int main() {
    int n;
    cin>> n;
    cin.ignore();
    vector<vector<int>> a(n+1, vector<int>(n+1, 0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>> a[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i][j]) {
                cout<< j << " ";
            }
        }
        cout<< endl;
    }
    return 0;
}