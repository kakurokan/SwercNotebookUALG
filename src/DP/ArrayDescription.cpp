/* =============================================================================
 * Problema: Array Description
 * Algoritmo: DP Local (Adjacencia)
 * Descricao: Modificar um array preenchendo zeros, sendo que valores
 * adjacentes podem diferir no maximo em 1. Conta todas as combinacoes validas.
 * =============================================================================
 */
int solve(int arraySize, int upperBound, int array[]) {
    // memo[i][k] = n de formas de criar prefixo i terminado no valor k
    vector<vi> memo(arraySize + 1, vi(upperBound + 1, 0));

    // Caso base: primeiro elemento do array (i=1)
    for (int k = 1; k <= upperBound; k++) {
        if (array[0] == k || array[0] == 0) {
            memo[1][k] = 1;
        }
    }

    // Transicao para os restantes elementos
    for (int i = 2; i <= arraySize; i++) {
        for (int k = 1; k <= upperBound; k++) {
            // Se a posicao nao e zero, apenas transita para o valor fixo
            if (array[i - 1] != 0 && array[i - 1] != k) {
                memo[i][k] = 0;
                continue;
            }
            // Soma as 3 opcoes do vizinho anterior: [k-1, k, k+1]
            for (int prev = k - 1; prev <= k + 1; prev++) {
                if (prev < 1 || prev > upperBound) continue;
                memo[i][k] = (memo[i][k] + memo[i - 1][prev]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int k = 1; k <= upperBound; k++) {
        ans = (ans + memo[arraySize][k]) % MOD;
    }
    return ans;
}
