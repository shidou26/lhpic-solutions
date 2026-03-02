#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e4 + 3;
const int maxA = 1e6 + 3;

int n;
int a[maxN];
int counts[maxA], answer[maxA];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];

		for(int j = 1; j * j <= a[i]; j++) {
			if(a[i] % j == 0) {
				counts[j]++;
				if(a[i] / j != j) counts[a[i] / j]++;
			}
		}
	}

	for(int j = 1; j < maxA; j++) answer[counts[j]] = max(answer[counts[j]], j);
	for(int j = maxA - 1; j > 1; j--) answer[j - 1] = max(answer[j - 1], answer[j]);

	for(int i = 1; i <= n; i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}
