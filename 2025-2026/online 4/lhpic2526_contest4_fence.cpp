#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define int long long

const int MAX = 1e6 + 5;
const int MOD = 1e9 + 7;
const int LOG = 21;
const int ha = 1;
using pii = pair <int, int>;
using tpl = tuple <int, int, int>;

int n;
int a[MAX];

int solve(int l, int r, int cur){
    int res1 = r - l + 1;
    int mi = INT_MAX;
    for(int i = l; i <= r; i++) mi = min(mi, a[i]);

    int res2 = mi - cur;
    int x = 0, y = 0;
    for(int i = l; i <= r; i++){
        if(a[i] > mi){
            if(x == 0) x = y = i;
            else y = i;
        }
        else{
            if(x != 0) res2 += solve(x, y, mi);
            x = y = 0;
        }
    }
    if(x != 0) res2 += solve(x, y, mi);

    return min(res1, res2);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << solve(1, n, 0);

    return 0;
}
