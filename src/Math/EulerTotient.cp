/* ==============================================================================
 * Algoritmo: Função Totiente de Euler (Phi - φ)
 * Descrição: Conta o número de inteiros <= N que são coprimos com N.
 * ============================================================================== */
#include <bits/stdc++.h>
using namespace std;

// 1. Calcula phi(N) para um único número em O(sqrt(N))
long long phi(long long n) {
    long long result = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

// 2. Pré-computa phi(N) para todos os números até MAXN em O(N log log N)
const int MAXN = 1e6 + 5;
int phi_arr[MAXN];

void sieve_phi() {
    for (int i = 0; i < MAXN; i++) phi_arr[i] = i;
    for (int i = 2; i < MAXN; i++) {
        if (phi_arr[i] == i) { // Se for primo
            for (int j = i; j < MAXN; j += i) {
                phi_arr[j] -= phi_arr[j] / i;
            }
        }
    }
}