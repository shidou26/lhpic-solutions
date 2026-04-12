#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1000000000LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= mod;
    }

    int n1 = n / 2;
    int n2 = n - n1;

    vector<ll> p(1 << n1);
    for (int i = 0; i < (1 << n1); i++) {
        ll s = 0;
        for (int j = 0; j < n1; j++) {
            if ((i >> j) & 1) {
                s = (s + a[j]) % mod;
            }
        }
        p[i] = s;
    }

    vector<ll> q(1 << n2);
    for (int i = 0; i < (1 << n2); i++) {
        ll s = 0;
        for (int j = 0; j < n2; j++) {
            if ((i >> j) & 1) {
                s = (s + a[n1 + j]) % mod;
            }
        }
        q[i] = s;
    }

    sort(q.begin(), q.end());
    q.erase(unique(q.begin(), q.end()), q.end());

    ll ans = 0;
    for (ll x : p) {
        auto it = lower_bound(q.begin(), q.end(), mod - x);
        if (it != q.begin()) {
            ans = max(ans, (x + *prev(it)) % mod);
        }
        ans = max(ans, (x + q.back()) % mod);
    }

    cout << ans << "\n";

    return 0;
}
