/* ==============================================================================
 * Algoritmo: KMP (Prefix Function / Pi Array)
 * Complexidade: O(N)
 * Descrição: Encontra ocorrências de um padrão num texto em tempo linear.
 * Para usar em pattern matching, basta processar a string s = "padrao#texto".
 * ==============================================================================
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> compute_pi(const string& s) {
    int n = s.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];  // Recua usando as bordas já calculadas
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}