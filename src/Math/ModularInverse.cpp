#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1'000'000'007LL;

/*
 * Inverso multiplicativo modular - O(log m)
 * Requisito: m deve ser primo.
 */
ll modInverse(ll n, ll m = MOD) {
    if (n % m == 0) return 0; // evita divisão por zero em casos inválidos
    return binpow(n, m - 2, m);
}

ll binpow(ll a, ll b, ll m = MOD) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
