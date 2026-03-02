#include <bits/stdc++.h>
using namespace std;

const int maxN = 3e5 + 3;

int n, m;
int p[maxN], prefix[maxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int median = 0;
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
		if(p[i] == m) median = i;
	}

	for(int i = 1; i <= n; i++) {
		int value = 0;
		if(p[i] > m) value = 1;
		if(p[i] < m) value = -1;
		prefix[i] = prefix[i - 1] + value;
	}

	long long answer = 0;
	map<int, int> freq;
	for(int i = 0; i < median; i++) freq[prefix[i]]++;
	for(int i = median; i <= n; i++) answer += freq[prefix[i]];

	cout << answer << endl;

	return 0;
}