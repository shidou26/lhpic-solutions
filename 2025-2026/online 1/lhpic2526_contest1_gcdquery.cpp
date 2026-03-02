#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 3;

int n;
int a[maxN], prefix[maxN], suffix[maxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for(int i = 1; i <= n; i++) prefix[i] = __gcd(prefix[i - 1], a[i]);
	for(int i = n; i >= 1; i--) suffix[i] = __gcd(suffix[i + 1], a[i]);

	int best = 0;
	for(int i = 1; i <= n; i++) best = max(best, __gcd(prefix[i - 1], suffix[i + 1]));
	for(int i = 1; i <= n; i++) {
		if(best ==  __gcd(prefix[i - 1], suffix[i + 1])) cout << i << " ";
	}

	return 0;
}