#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=50;
int n,m,k;
int a[N],pre[N];
int maxx=-1e18;
void dequy(int vt,int tong,int dem){
    if(dem==k){
        maxx=max(maxx,tong);
        return;
    }
    for(int i=vt;i<=n-m+1;i++){
        dequy(i+m,tong+pre[i+m-1]-pre[i-1],dem+1);
    }
}
signed main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    pre[0]=0;
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    dequy(1,0,0);
    cout<<maxx<<'\n';
    return 0;
}
