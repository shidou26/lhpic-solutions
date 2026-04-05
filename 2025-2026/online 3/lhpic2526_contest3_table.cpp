#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;

    ll l = 1, r = n * m;

    while (l < r) {
        ll mid = (l + r) / 2;
        ll cnt = 0;

        for (int i = 1; i <= n; i++) {
            cnt += min(m, mid / i);
        }

        if (cnt >= k) r = mid;
        else l = mid + 1;
    }

    cout << l;

    return 0;
}