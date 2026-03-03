#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 2e5 + 10;
int n, M;
int a[N];

int phi(int m){
    int res = m;
    for (int i = 2; i * i <= m; i++)
        if (m % i == 0){
            while (m % i == 0){
                m /= i;
            }
            res -=  res / i;
        }
    if (m > 1)
        res -= res / m;
    return res;
}

vector<int> find_prime_factors(int m){
    vector<int> list_prime;
    for (int i = 2; i * i <= m; i++)
        if (m % i == 0){
            while(m % i == 0)
                m /= i;
            list_prime.push_back(i);
        }
    if (m > 1)
        list_prime.push_back(m);
    return list_prime;
}

int find_pow(int u, int k){
    int res = 1;
    while(k){
        if (k & 1)
            res = (ll) res * u % M;
        u = (ll) u * u % M;
        k >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> M;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int phi_m = phi(M);
    auto list_prime = find_prime_factors(phi_m);
    int res = 1;
    for (int i = 1; i <= n; i++){
        int k = phi_m;
        for (int p : list_prime)
            while(k % p == 0 && find_pow(a[i], k / p) == 1)
                k /= p;
        int num = 1'000'000'000 / k;
        res = (ll) res * num % M;
    }
    cout << res;

    return 0;
}
