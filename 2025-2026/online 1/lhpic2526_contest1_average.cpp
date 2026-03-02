#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 3;

int n, q;
int grades[maxN];
long long prefix[maxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	for(int i = 1; i <= n; i++) {
		cin >> grades[i];
	}

	for(int i = 1; i <= n; i++) {
		prefix[i] = prefix[i - 1] + grades[i];
	}

	cout << fixed << setprecision(1) << 1.0 * prefix[n] / n << endl;
	while(q--) {
		int l, r; cin >> l >> r;
		double average = 1.0 * (prefix[r] - prefix[l - 1]) / (r - l + 1);
		cout << fixed << setprecision(1) << average << endl;
	}

	return 0;
}