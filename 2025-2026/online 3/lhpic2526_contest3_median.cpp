#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, m, a[MAXN], Prefixsum[MAXN];
int Sort_a[MAXN]; // mảng a sau khi sắp xếp

bool check_max_median(int k, int val) {
    for(int i = 1; i <= n; i++) {
        Prefixsum[i] = Prefixsum[i - 1] + (a[i] < val ? -1 : 1);
        // gán giá trị cho các phần tử a[i] và tính Prefix sum
    }

    int mi = 0;

    for(int i = 1; i <= n; i++) {
        if(i >= k && (Prefixsum[i] - mi) >= 1) {
            return true;
        }
        if(i >= k) {
            mi = min(mi , Prefixsum[i - k + 1]);
            // lưu lại Prefixsum[j] bé nhất nếu (i - j + 1) >= k
        }
    }

    return false;
}

int find_max_median(int k) {
    int L = 1, R = n, Best = 0;
    // chặt nhị phân các giá trị a[i]
    while(L <= R) {
        int Mid = (L + R) / 2;
        if(check_max_median(k, Sort_a[Mid])) {
            Best = Mid;
            L = Mid + 1;
        }
        else R = Mid - 1;
    }

    return Sort_a[Best];
}

bool check_min_median(int k, int val) {
    for(int i = 1; i <= n; i++) {
        Prefixsum[i] = Prefixsum[i - 1] + (a[i] > val ? -1 : 1);
        // gán giá trị cho các phần tử a[i] và tính Prefix sum
    }

    int mi = 0;
    
    for(int i = 1; i <= n; i++) {
        if(i >= k && (Prefixsum[i] - mi) >= 0) {
            return true;
        }
        if(i >= k) {
            mi = min(mi , Prefixsum[i - k + 1]);
            // lưu lại Prefixsum[j] bé nhất nếu (i - j + 1) >= k
        }
    }

    return false;
}

int find_min_median(int k) {
    int L = 1, R = n, Best = 0;
    // chặt nhị phân các giá trị a[i]
    while(L <= R) {
        int Mid = (L + R) / 2;
        if(check_min_median(k, Sort_a[Mid])) {
            Best = Mid;
            R = Mid - 1;
        }
        else L = Mid + 1;
    }

    return Sort_a[Best];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        Sort_a[i] = a[i];
    }

    sort(Sort_a + 1, Sort_a + n + 1);

    int L_k = 1 , R_k = n, Best_k = -1;
    // chặt nhị phân độ dài k bé nhất thỏa mãn
    while(L_k <= R_k) {
        int Mid_k = (L_k + R_k) / 2;
        if(find_max_median(Mid_k) - find_min_median(Mid_k) <= m) {
            Best_k = Mid_k;
            R_k = Mid_k - 1;
        }
        else{
            L_k = Mid_k + 1;
        }
    }

    cout << Best_k;
    return 0;
}