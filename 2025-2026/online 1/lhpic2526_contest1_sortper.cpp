#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 3;

int n, q;
int diff[maxN];
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
    	int p; cin >> p;
    	diff[min(i, p)]++;
    	diff[max(i, p)]--;
    }

    cin >> s;

    set<int> barrier;
    for(int i = 1; i < n; i++) {
    	diff[i] += diff[i - 1];
    	if(s[i - 1] == 'L' && s[i] == 'R' && diff[i] > 0) barrier.insert(i);
    }

    while(q--) {
    	int x; cin >> x;
    	x--;

    	if(s[x] == 'L') {
    		s[x] = 'R';
    		if(s[x + 1] == 'R' && diff[x + 1] > 0) barrier.erase(x + 1);
    		if(s[x - 1] == 'L' && diff[x] > 0) barrier.insert(x);
    	}else {
    		s[x] = 'L';
    		if(s[x - 1] == 'L' && diff[x] > 0) barrier.erase(x);
    		if(s[x + 1] == 'R' && diff[x + 1] > 0) barrier.insert(x + 1);
    	}

    	if(barrier.empty()) cout << "YES" << endl;
    	else cout << "NO" << endl;
    }

	return 0;
}