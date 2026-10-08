/* ==============================================================================
 * Algoritmo: Rolling Hash com Duplo Hash (Rabin-Karp)
 * Complexidade: Pré-computação O(N), Queries de Substring O(1)
 * Descrição: Transforma substrings em inteiros para comparações diretas.
 * ==============================================================================
 */
#include <bits/stdc++.h>
using namespace std;

const long long M1 = 1e9 + 7, M2 = 1e9 + 9;
const long long B1 = 313, B2 = 317;

struct Hash {
    vector<long long> h1, h2, p1, p2;

    Hash(const string& s) {
        int n = s.length();
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);

        for (int i = 0; i < n; i++) {
            p1[i + 1] = (p1[i] * B1) % M1;
            p2[i + 1] = (p2[i] * B2) % M2;

            h1[i + 1] = (h1[i] * B1 + s[i]) % M1;
            h2[i + 1] = (h2[i] * B2 + s[i]) % M2;
        }
    }

    // Retorna o par de hash da substring s[l...r] (0-indexed, inclusivo)
    pair<long long, long long> get(int l, int r) {
        long long hash1 = (h1[r + 1] - (h1[l] * p1[r - l + 1]) % M1 + M1) % M1;
        long long hash2 = (h2[r + 1] - (h2[l] * p2[r - l + 1]) % M2 + M2) % M2;
        return {hash1, hash2};
    }
};