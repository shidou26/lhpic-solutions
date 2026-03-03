#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e3 + 3;
const int maxA = 1e6 + 5;

int n, m;
int increase[maxA];
int a[maxN][maxN], prefix[maxN][maxN];
bool isPrime[maxA];

int get(int x, int y, int u, int v) {
	return prefix[u][v] - prefix[u][y - 1] - prefix[x - 1][v] + prefix[x - 1][y - 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;

	for(int i = 2; i * i < maxA; i++) {
		if(isPrime[i]) {
			for(int j = i * i; j < maxA; j += i) isPrime[j] = false;
		}
	}

	int nearest = (int)1e6 + 3;
	for(int i = nearest; i >= 1; i--) {
		if(isPrime[i]) nearest = i;
		increase[i] = nearest - i;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + increase[a[i][j]];
		}
	}

	int answer = INT_MAX;
	for(int row = 1; row <= n; row++) answer = min(answer, get(row, 1, row, m));
	for(int column = 1; column <= m; column++) answer = min(answer, get(1, column, n, column));

	cout << answer << endl;

	return 0;
}