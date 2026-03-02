#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 3;

int n;
int a[maxN], b[maxN], c[maxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	
	map<int, int> one, two, three;
	for(int i = 1; i <= n; i++) one[a[i]]++;
	for(int i = 1; i <= n; i++) two[b[i]]++;
	for(int i = 1; i <= n; i++) three[c[i]]++;

	long long answer = 0;
	for(pair<int, int> p : one) {
		answer += 1LL * p.second * two[p.first] * three[p.first];
	}

	cout << answer << endl;

	return 0;
}