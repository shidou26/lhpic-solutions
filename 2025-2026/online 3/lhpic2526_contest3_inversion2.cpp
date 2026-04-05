#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3;

int n;
int a[N], temp[N];
long long inversion = 0;

void merge_sort(int l, int r) {
    if(l == r) return;
    int mid = (l + r) / 2;

    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    int i = l, j = mid + 1, k = l;
    while(k <= r) {
        if(i == mid + 1) temp[k++] = a[j++];
        else if(j == r + 1) temp[k++] = a[i++]; 
        else {
            if(a[i] > a[j]) {
                inversion += mid - i + 1; // Các phần tử nằm đằng sau i cũng thỏa mãn điều kiện
                temp[k++] = a[j++];
            }else temp[k++] = a[i++];
        }
    }

    for(int i = l; i <= r; i++) a[i] = temp[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    merge_sort(1, n);
    cout << inversion << endl;

    return 0;
}