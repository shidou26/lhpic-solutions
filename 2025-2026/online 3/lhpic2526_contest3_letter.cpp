#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
long long a[N], pre[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    long long b, d, k;
    cin >> n >> q;
    
    pre[0] = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    while (q--) {
        cin >> b;
        d = lower_bound(pre + 1, pre + n + 1, b) - pre;
        k = b - pre[d - 1];
        cout << d << " " << k << "\n";
    }

    return 0;
}