#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1'000'000'007LL;

/*
 * Exponenciação modular rápida - O(log b)
 * Calcula (a^b) % m eficientemente.
 */
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
