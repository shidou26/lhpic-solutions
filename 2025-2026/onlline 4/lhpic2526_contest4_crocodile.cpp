#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define task "hung"
typedef pair<int,int> pii;
const int maxn=1e6,MOD=1e9+7;
const ll INF=1e18;
int n;
ll a[maxn],tong = 0;;
vector<ll> sum1,sum2;
ll check(ll x,ll m){
    return llabs(x + m - (tong - x - m));
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        tong += a[i];
    }
    int l = n/2;
    int r = n/2+1;
    for(int mask=0;mask < (1 << l);mask++){
        ll sum = 0;
        for(int s = mask; s ; s -= s & -s){
            int t = __builtin_ctz(s);
            sum += a[t+1];
        }
        sum1.pb(sum);
    }
    for(int mask=0;mask < (1 << (n-l));mask++){
        ll sum = 0;
        for(int s = mask; s ; s -= s & -s){
            int t = __builtin_ctz(s);
            sum += a[r+t];
        }
        sum2.pb(sum);
    }
    sort(all(sum2));
    ll ans = INF;
    for(ll x : sum1){
        l = 0,r = (int)sum2.size()-1;
        while(l<r){
            int mid = (l+r) >> 1;
            ll m = sum2[mid];
            ll val1 = check(x,m) , val2 = check(x,m+1);
            if(val1 <= val2){
                r = mid;
            }else l = mid+1;
        }
        ans = min(ans,check(x,sum2[l]));
    }
    cout << ans;
    return 0;
}
