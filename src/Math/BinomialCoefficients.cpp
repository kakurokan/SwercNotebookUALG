#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1'000'000'007;
const int MAXN = 1'000'000 + 5;

ll fact[MAXN], invFact[MAXN];

/*
 * Pré-computação de fatoriais para responder combinações em O(1).
 */
void precompute_factorials() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    invFact[MAXN - 1] = 1;
    ll last = fact[MAXN - 1];
    ll invLast = 1;
    // Usando o inverso modular do último fatorial
    ll power = MOD - 2;
    ll base = last % MOD;
    while (power > 0) {
        if (power & 1) invLast = (invLast * base) % MOD;
        base = (base * base) % MOD;
        power >>= 1;
    }
    invFact[MAXN - 1] = invLast;

    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}
