#include <bits/stdc++.h>

using namespace std;

const int maxN = 5e6 + 3;

int p[maxN], pos[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        pos[p[i]] = i;   
    }

    for (int i = 1; i <= k; i++)
    {
        swap(p[i], p[pos[i]]);
        pos[p[pos[i]]] = pos[i];
    }

    for (int i = 1; i <= n; i++)
        cout << p[i] << ' ';

    return 0;
}
