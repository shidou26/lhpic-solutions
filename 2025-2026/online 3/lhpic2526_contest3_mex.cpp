#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n,k;
int a[N];

bool check(int x) {
    if (x == 0) return true;

    vector<int> cnt(x + 1, 0);
    int need = x;
    int segment = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] < x){
            if(cnt[a[i]] == 0) need--;
            cnt[a[i]]++;
        }
        if (need == 0) {
            segment++;
            if (segment >= k) return true;
            fill(cnt.begin(), cnt.end(),0);
            need = x;
        }
    }
    return segment >= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int l = 0, r = n, ans = 0;
    while (l <= r) {
        int mid=(l + r) / 2;
        if (check(mid) == true) {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}