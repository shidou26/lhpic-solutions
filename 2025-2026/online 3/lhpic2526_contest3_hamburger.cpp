#include <bits/stdc++.h>
using namespace std;

long long b = 0, s = 0, c = 0, nb, ns, nc, pb, ps, pc, r, ans = 0;

bool check(long long x) {
    long long res = 0;
    res += max(0ll, b * x - nb) * pb;
    res += max(0ll, s * x - ns) * ps;
    res += max(0ll, c * x - nc) * pc;
    return res <= r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string st;
    cin >> st;
    for(int i = 0; i < (int)st.size(); i++) {
        if(st[i] == 'B') b ++;
        if(st[i] == 'S') s ++;
        if(st[i] == 'C') c ++;
    }
    cin >> nb >> ns >> nc >> pb >> ps >> pc >> r;

    long long l = 0, r = 1e15;
    while(l <= r) {
        long long mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;

    return 0;
}