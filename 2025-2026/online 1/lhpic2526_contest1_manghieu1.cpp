#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 3;

int a[maxN];
long long diffMinus[maxN], diffCount[maxN]; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
        
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        diffMinus[l] -= (l - 1);
        diffMinus[r + 1] += (l - 1);
        diffCount[l]++;
        diffCount[r + 1]--;
    }
    
    for(int i = 1; i <= n; i++) {
        diffMinus[i] += diffMinus[i - 1];
        diffCount[i] += diffCount[i - 1];
        cout << a[i] + diffMinus[i] + diffCount[i] * i << " ";
    }
    
    return 0;
}
