#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x, y;
	long long limit;
	cin >> x >> y >> limit;

	if(limit < y) {
		int answer = 0;
		for(int i = 0; i <= limit; i++) 
			if(__gcd(x, y) == __gcd(x + i, y)) answer += 1;
		return cout << answer << "\n", 0;
	}

	long long numberOfPeriod = limit / y, position = limit % y;

	int first = 0;
	for(int i = 0; i < y; i++) 
		if(__gcd(x, y) == __gcd(x + i, y)) first += 1;

	int remains = 0;
	for(int i = 0; i <= position; i++) 
		if(__gcd(x, y) == __gcd(x + i, y)) remains += 1;

	cout << remains + numberOfPeriod * first << "\n";

	return 0;
}