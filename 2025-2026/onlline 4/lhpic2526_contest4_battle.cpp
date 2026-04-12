#include <bits/stdc++.h>
using namespace std;
int n, ans;
char a[9][9];
bool col[8], cheo1[16], cheo2[16];

void solve(int r)
{
    if(r == n)
    {
        ans++;
        return;
    }
    for(int c = 0; c < n; c++)
    {
        if(a[r][c] == '*' || col[c] || cheo1[r + c] || cheo2[r - c + n - 1])
            continue;
        col[c] = cheo1[r + c] = cheo2[r - c + n - 1] = true;
        solve(r + 1);
        col[c] = cheo1[r + c] = cheo2[r - c + n - 1] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> a[i][j];
        memset(col, 0, sizeof(col));
        memset(cheo1, 0, sizeof(cheo1));
        memset(cheo2, 0, sizeof(cheo2));
        ans = 0;
        solve(0);
        cout << "Case " << tc++ << ": " << ans << "\n";
    }
}
