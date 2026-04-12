#include <bits/stdc++.h>

using namespace std;

int a[21];
int ans = 0;
int n, m;

void recursion(int i, long long left){
    if (i == n){
        if (left >= 0)
            ++ans;
        return;
    }
    recursion(i + 1, left - a[i]);
    recursion(i + 1, left);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    recursion(0, m);
    cout << ans - 1;

    return 0;
}
