/* ==============================================================================
 * Algoritmo: Z-Algorithm
 * Complexidade: O(N)
 * Descrição: z[i] é o tamanho do maior prefixo comum entre s[0...N-1] e
 * s[i...N-1]. A otimização baseia-se em manter um intervalo de correspondência
 * [l, r].
 * ==============================================================================
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> z_algorithm(const string& s) {
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}