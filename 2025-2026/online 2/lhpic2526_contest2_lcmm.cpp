#include <bits/stdc++.h>
using namespace std;

long long compute(long long a, long long b) {
	return a / __gcd(a, b) * b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	long long answer = 0;
	for(int a = max(1, n - 36); a <= n; a++) {
		for(int b = max(1, n - 36); b <= n; b++) {
			for(int c = max(1, n - 36); c <= n; c++) {
				answer = max(answer, compute(compute(a, b), c));
			}	
		}
	}

	cout << answer << endl;

	return 0;
}