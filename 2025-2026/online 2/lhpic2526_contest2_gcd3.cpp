#include <bits/stdc++.h>
using namespace std;

const int maxA = 1e6 + 3;

int counts[maxA];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for(int i = 1; i <= n; i++) {
		int x; cin >> x;
		counts[x]++;
	}

	for(int i = maxA - 1; i >= 1; i--) {
		for(int j = 2 * i; j < maxA; j += i) {
			counts[i] += counts[j];
		}

		if(counts[i] >= 2) return cout << i << "\n", 0;
	}	

	return 0;
}