#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e3 + 3;
const int maxA = 6e5 + 3;

int n, k;
int a[maxN];
int freq[maxA + maxA];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	long long answer = 0;
    for(int y = 2; y <= n; y++) {
        for(int x = 1; x < y; x++) freq[a[x] + maxA]++;
        for(int z = y + 1; z <= n; z++) answer += freq[k - a[y] - a[z] + maxA];
        for(int x = 1; x < y; x++) freq[a[x] + maxA]--;
    }

    cout << answer << endl;

	return 0;	
}