#include <bits/stdc++.h>

using namespace std;

const int e = 1e9;
int n, x, y;
int d[75][75];
int ans = e;
int dx[8] = {-1, -2, -1, -2, 1, 2, 1, 2};
int dy[8] = {-2, -1, 2, 1, 2, 1, -2, -1};

void dfs(int i, int j, int step) {
    if(step >= ans) return;
    if(d[i][j] <= step) return;
    d[i][j] = step;
    if(n-i+1 == j) {
        ans = min(ans, step);
        return;
    }
    for(int k = 0; k < 8; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if(ni >= 1 && ni <= n && nj >= 1 && nj <= n) dfs(ni, nj, step + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin >> x >> y;
    if(n-x+1 == y) {
        cout << 0;
        return 0;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            d[i][j] = e;
    dfs(x, y, 0);
    cout << ans;
    return 0;
}
