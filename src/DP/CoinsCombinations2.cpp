/* 
 * Problema: Coin Combinations II
 * Algoritmo: Unbounded Knapsack (Contagem Combinatoria)
 * Descricao: Numero de formas de atingir um alvo. A ORDEM DAS MOEDAS NAO
 * IMPORTA (ex: 2+1 e igual a 1+2). Para isto, iteramos as moedas no ciclo
 * externo!
 */
int solve(int target, vi coins) {
    vi memo(target + 1, 0);
    memo[0] = 1;  // 1 forma de fazer o valor 0 (conjunto vazio)

    // O facto de a iteracao das moedas ser externa e o que previne permutacoes
    for (int c : coins) {
        for (int i = 0; i <= target; i++) {
            if (c <= i) {
                memo[i] = (memo[i] + memo[i - c]) % MOD;
            }
        }
    }
    return memo[target];
}
