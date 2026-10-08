/* ==============================================================================
 * Problema: Array Description
 * Algoritmo: DP Local (Adjacência)
 * Descrição: Modificar um array preenchendo zeros, sendo que valores
 * adjacentes podem diferir no máximo em 1. Conta todas as combinações válidas.
 * ==============================================================================
 */
int solve(int arraySize, int upperBound, int array[]) {
    // memo[i][k] = nº de formas de criar prefixo i terminado no valor k
    vector<vi> memo(arraySize + 1, vi(upperBound + 1, 0));

    // Caso base: primeiro elemento do array (i=1)
    for (int k = 1; k <= upperBound; k++) {
        if (array[0] == k || array[0] == 0) {
            memo[1][k] = 1;
        }
    }

    // Transição para os restantes elementos
    for (int i = 2; i <= arraySize; i++) {
        for (int k = 1; k <= upperBound; k++) {
            // Se a posição não é zero, apenas transita para o valor fixo
            if (array[i - 1] != 0 && array[i - 1] != k) {
                memo[i][k] = 0;
                continue;
            }
            // Soma as 3 opções do vizinho anterior: [k-1, k, k+1]
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