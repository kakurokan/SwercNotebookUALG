#include <bits/stdc++.h>
using namespace std;

const int MAX_SIEVE = 1'000'000 + 5;
int spf[MAX_SIEVE];

/*
 * Crivo de Eratóstenes para calcular o menor fator primo de cada número.
 */
void sieve() {
    for (int i = 1; i < MAX_SIEVE; i++) spf[i] = i;
    for (int i = 2; i * i < MAX_SIEVE; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX_SIEVE; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

vector<int> getFactorization(int x) {
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x /= spf[x];
    }
    return ret;
}
