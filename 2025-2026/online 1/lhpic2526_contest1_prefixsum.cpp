#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 3;

int n, q;
int a[maxN];
long long prefix[maxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for(int i = 1; i <= n; i++) {
		prefix[i] = prefix[i - 1] + a[i];
	}

	while(q--) {
		int l, r; cin >> l >> r;
		cout << prefix[r] - prefix[l - 1] << endl;
	}

	return 0;
}
