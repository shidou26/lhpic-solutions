#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y;
};

struct PrefixSum {
	long long x, y, x_square, y_square;
};

const int maxN = 1e5 + 3;

int n, q;
Point point[maxN];
PrefixSum prefix[maxN];

long long square(int x) {
	return 1LL * x * x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	for(int i = 1; i <= n; i++) cin >> point[i].x;
	for(int i = 1; i <= n; i++) cin >> point[i].y;

	for(int i = 1; i <= n; i++) {
		prefix[i] = {prefix[i - 1].x + point[i].x,
					 prefix[i - 1].y + point[i].y,
					 prefix[i - 1].x_square + square(point[i].x),
					 prefix[i - 1].y_square + square(point[i].y)
		};
	}

	while(q--) {
		int l, r; cin >> l >> r; 
		long long x, y; cin >> x >> y;

		long long answer = prefix[r].x_square - prefix[l - 1].x_square  
						 + prefix[r].y_square - prefix[l - 1].y_square 
						 - 2LL * x * (prefix[r].x - prefix[l - 1].x) 
						 - 2LL * y * (prefix[r].y - prefix[l - 1].y) 
						 + 1LL * (r - l + 1) * (square(x) + square(y));

		cout << answer << endl;
	}

	return 0;
}