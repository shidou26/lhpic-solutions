#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int multiply(int x, int y) {
	return 1LL * x * y % MOD;
}

int power(int x, int y) {
	int total = 1;
	while(y) {
		if(y & 1) total = multiply(total, x);
		x = multiply(x, x);
		y >>= 1;
	}
	return total;
}

const int maxV = 1e5 + 3;

int n;
int counts_a[maxV], counts_b[maxV], minPrime[maxV];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for(int i = 2; i * i < maxV; i++) 
		for(int j = i * i; j < maxV; j += i) if(!minPrime[j]) minPrime[j] = i;
	for(int i = 2; i < maxV; i++) if(!minPrime[i]) minPrime[i] = i;

	cin >> n;

	for(int i = 1; i <= n; i++) {
		int x; cin >> x;
		
		while(x > 1) {
			int p = minPrime[x], a = 0;
			while(x % p == 0) {
				x /= p;
				a++;
			}

			counts_a[p] += a;
		}
	}

	for(int i = 1; i <= n; i++) {
		int x; cin >> x;

		while(x > 1) {
			int p = minPrime[x], a = 0;
			while(x % p == 0) {
				x /= p;
				a++;
			}

			counts_b[p] += a;
		}
	}

	int answer = 1;
	for(int i = 2; i < maxV; i++) {
		if(minPrime[i] == i) {
			answer = multiply(answer, power(i, min(counts_a[i], counts_b[i])));
		}
	}

	cout << answer << "\n";

	return 0;
}