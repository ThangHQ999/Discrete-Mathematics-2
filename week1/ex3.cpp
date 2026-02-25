#include <bits/stdc++.h>
using namespace std;
// Chuyển từ danh sách cạnh sang ma trận kề (vô hướng)

int main() {
    int e, v;
    cin>> e >> v;
    int m[v+1][v+1];
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        m[a][b] = 1;
        m[b][a] = 1; // nếu có hướng thì xóa bỏ dòng này
    }

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
