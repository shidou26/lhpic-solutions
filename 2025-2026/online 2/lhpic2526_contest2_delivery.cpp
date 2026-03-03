#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 3;

int phi[maxN], step[maxN];

void sievePhi()
{
    for (int i = 1; i < maxN; i++)
        phi[i] = i;

    for (int i = 1; i < maxN; i++)
        for (int j = i + i; j < maxN; j += i)
            phi[j] -= phi[i];
}

void countStep()
{
    step[0] = -1;
    step[1] = 0;

    for (int i = 2; i < maxN; i++)
        step[i] = step[phi[i]] + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sievePhi();
    countStep();

    int n;
    cin >> n;

    while (n--)
    {
        int dest;
        cin >> dest;
        cout << step[dest] << '\n';
    }

    return 0;
}
