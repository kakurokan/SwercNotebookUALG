/* ==============================================================================
 * Problema: Minimizing Coins
 * Algoritmo: Unbounded Knapsack (Minimização)
 * Descrição: Encontrar o número mínimo de moedas para atingir um valor alvo.
 * Moedas podem ser usadas infinitas vezes.
 * ==============================================================================
 */
int solve(int target, vi coins) {
    // Inicializar com INF, pois queremos o mínimo
    vi memo(target + 1, INF);
    memo[0] = 0;  // 0 moedas para fazer o valor 0

    for (int i = 1; i <= target; i++) {
        for (int c : coins) {
            if (c <= i) {
                // Transição: Mínimo entre não usar e usar a moeda 'c'
                memo[i] = min(memo[i], memo[i - c] + 1);
            }
        }
    }

    // Se o valor continua INF, é impossível atingir o alvo
    return (memo[target] < INF ? memo[target] : -1);
}