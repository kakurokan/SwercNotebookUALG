/* ==============================================================================
 * Problema: Coin Combinations II
 * Algoritmo: Unbounded Knapsack (Contagem Combinatória)
 * Descrição: Número de formas de atingir um alvo. A ORDEM DAS MOEDAS NÃO
 * IMPORTA (ex: 2+1 é igual a 1+2). Para isso, iteramos as moedas no ciclo
 * externo!
 * ==============================================================================
 */
int solve(int target, vi coins) {
    vi memo(target + 1, 0);
    memo[0] = 1;  // 1 forma de fazer o valor 0 (conjunto vazio)

    // O facto de a iteração das moedas ser externa é o que previne permutações
    for (int c : coins) {
        for (int i = 0; i <= target; i++) {
            if (c <= i) {
                memo[i] = (memo[i] + memo[i - c]) % MOD;
            }
        }
    }
    return memo[target];
}