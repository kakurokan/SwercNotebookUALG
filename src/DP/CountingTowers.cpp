/* ==============================================================================
 * Problema: Counting Towers
 * Algoritmo: State Machine DP
 * Descrição: Número de formas de construir uma torre 2 x N.
 * Estados: 0 = blocos superiores separados; 1 = bloco superior único (unido).
 * ==============================================================================
 */
ll memo[1000000 + 1][2];

// Pré-computa até 10^6 para responder a múltiplas queries rapidamente
void precompute() {
    memo[1][0] = 1;  // Linha 1 dividida
    memo[1][1] = 1;  // Linha 1 unida

    for (int i = 2; i <= 1e6; i++) {
        // Formas de prolongar/cortar blocos separados e unidos
        memo[i][0] = (4 * memo[i - 1][0] + memo[i - 1][1]) % MOD;
        memo[i][1] = (2 * memo[i - 1][1] + memo[i - 1][0]) % MOD;
    }
}

int solve() {
    int t;
    cin >> t;
    precompute();  // Executar apenas uma vez!

    while (t--) {
        int n;
        if (!(cin >> n)) return 1;
        cout << (memo[n][0] + memo[n][1]) % MOD << '\n';
    }
    return 0;
}