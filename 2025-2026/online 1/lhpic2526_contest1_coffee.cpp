#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 3;

int n, k, q;
int prefix[maxN], diff[maxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> q;

	for(int i = 1; i <= n; i++) {
		int l, r; cin >> l >> r;
		diff[l]++;
		diff[r + 1]--;
	}

	for(int i = 1; i < maxN; i++) {
		diff[i] += diff[i - 1];
		prefix[i] = prefix[i - 1] + (diff[i] >= k);
	}

	while(q--) {
		int a, b; cin >> a >> b;
		cout << prefix[b] - prefix[a - 1] << endl;
	}

	return 0;
}