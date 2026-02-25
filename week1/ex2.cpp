#include <bits/stdc++.h>
using namespace std;
// Chuyển từ ma trận kề sang danh sách cạnh (có hướng)

int main() {
    int n;
    cin>> n;
    int a[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}
