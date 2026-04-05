#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int a[N][N], p[N][N];
int n, m, x, y;

bool check(int mid) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int val = (a[i][j] >= mid) ? 1 : -1;
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + val; 
        }
    }

    for (int i = x; i <= n; ++i) {
        for (int j = y; j <= m; ++j) {
            int sum = p[i][j] - p[i-x][j] - p[i][j-y] + p[i-x][j-y];
            if (sum > 0) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n >> m >> x >> y
    int max_val = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            max_val = max(max_val, a[i][j]);
        }
    }


    int l = 1, r = max_val, ans = 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}