/* ==============================================================================
 * Categoria: Matemática e Teoria dos Números
 * Descrição: Ferramentas essenciais para aritmética modular, combinatória e primos.
 * ============================================================================== */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

/* ==============================================================================
 * 1. Exponenciação Modular Rápida - O(log b)
 * Calcula (a^b) % m eficientemente.
 * ============================================================================== */
ll binpow(ll a, ll b, ll m = MOD) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

/* ==============================================================================
 * 2. Inverso Multiplicativo Modular - O(log m)
 * Requisito: 'm' tem de ser primo (Pequeno Teorema de Fermat: a^(m-2) ≡ a^-1 mod m)
 * Usado para divisão modular: (a / b) % m == (a * modInverse(b)) % m
 * ============================================================================== */
ll modInverse(ll n, ll m = MOD) {
    return binpow(n, m - 2, m);
}

/* ==============================================================================
 * 3. Combinatória: Coeficientes Binomiais (nCr % MOD)
 * Pré-computação: O(N) | Queries: O(1)
 * ============================================================================== */
const int MAXN = 1e6 + 5;
ll fact[MAXN], invFact[MAXN];

void precompute_factorials() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    // Computa o inverso do último fatorial e preenche para trás
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

/* ==============================================================================
 * 4. Crivo de Eratóstenes e Fatorização Rápida (SPF)
 * Crivo: O(N log log N) | Fatorização: O(log X)
 * SPF (Smallest Prime Factor) guarda o menor divisor primo de um número.
 * ============================================================================== */
const int MAX_SIEVE = 1e6 + 5;
int spf[MAX_SIEVE];

void sieve() {
    for (int i = 1; i < MAX_SIEVE; i++) spf[i] = i; // Inicialmente, spf de i é i
    for (int i = 2; i * i < MAX_SIEVE; i++) {
        if (spf[i] == i) { // Se i é primo
            for (int j = i * i; j < MAX_SIEVE; j += i) {
                if (spf[j] == j) spf[j] = i; // Marca o menor fator primo
            }
        }
    }
}

// Retorna os fatores primos de x. Ex: 12 -> {2, 2, 3}
vector<int> getFactorization(int x) {
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

/* ==============================================================================
 * 5. GCD (Máximo Divisor Comum) e LCM (Mínimo Múltiplo Comum)
 * ============================================================================== */
// Nota: Em C++17 podes usar std::gcd(a, b) diretamente da biblioteca <numeric>
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b; // Divide primeiro para evitar overflow
}

void solve() {
    // Exemplo de uso:
    precompute_factorials();
    sieve();
    
    // Calcular 10 Escolhe 3
    // cout << nCr(10, 3) << "\n";
    
    // Fatorizar 120
    // vector<int> fatores = getFactorization(120);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
