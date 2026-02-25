#include <bits/stdc++.h>
using namespace std;
// Chuyển đổi từ danh sách kề sang ma trận kề
int main() {
    int n;
    cin>> n;
    cin.ignore();
    vector<vector<int>> a(n+1, vector<int>(n+1, 0));
    for (int i=1; i<=n; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int token;
        while (ss >> token)
        {
            a[i][token] = 1;
        }        
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout<< a[i][j] << " "; 
        }
        cout<< endl;
    }
    return 0;
}