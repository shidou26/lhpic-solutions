#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;

const int N = 26;

int n;
int masks[N];

ll total = 0;

void prepare() {

}

void input() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        string s; cin >> s;
        for(char c : s) masks[i] |= (1 << (c - 'a'));
    }
}

void backtrack(int pos, int mask) {
    if(mask == 67108863) {
        total += (1LL << (n - pos + 1));
    }else {
        if(pos <= n) {
            backtrack(pos + 1, mask);
            backtrack(pos + 1, mask | masks[pos]);
        }
    }
}

void process() {
    backtrack(1, 0);
    cout << total << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #define task "main"
    if(fopen(task".INP", "r")) {
        freopen(task".INP", "r", stdin);
        freopen(task".OUT", "w", stdout);
    }

    prepare();

    int testcase = 1; // cin >> testcase;
    for(int i = 1; i <= testcase; i++) {
        input();
        process();
    }

    return 0;
}
