#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int a[MAXN];
long long pre[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 1;i <= n; i++) {
        cin >> a[i];
    }
    
    sort(a + 1,a + n + 1);
    
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i]; //prefix sum để lấy tổng
    }
    
    while(q--) {
        int k, m;
        cin >> k >> m;
        int pos = lower_bound(a + 1, a + n + 1, k) - a; // vị trí cắt của 2 phần 
        
        int l = 0, r = min(m, pos);
        // chặt nhị phân tìm kiếm loại hoa nào có giá trị U - V nhỏ nhất.
        while(l < r) {
            int mid = (l + r) / 2;

            long long add1 = 1ll * k * (m - mid);
            long long add2 = 1ll * k * (m - mid - 1);
            
            long long U1 = pre[mid] + add1;
            long long U2 = pre[mid + 1] + add2;
            
            long long V1 = pre[n] - pre[n - m + mid] - add1;
            long long V2 = pre[n] - pre[n - m + mid + 1] - add2;
            
            if(U1 - V1 < U2 - V2){
                r = mid;
            }else l = mid + 1;

        } 
        long long add = 1ll * k * (m - l);
        long long U = pre[l] + add;
        long long V = pre[n] - pre[n - m + l] - add;
        cout << U - V << '\n';
    }
    return 0;
}