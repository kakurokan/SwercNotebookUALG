/* ==============================================================================
 * Problema: Book Shop
 * Algoritmo: Mochila 0/1 (0/1 Knapsack)
 * Descrição: Dado um array de preços e outro de páginas, encontrar o máximo
 * de páginas possível comprar sem exceder um preço máximo.
 * ==============================================================================
 */
int solve(vi pages, vi prices, int maxTotalPrice) {
    int n = pages.size();
    // memo[i][sz] = máx páginas usando os primeiros i livros com orçamento sz
    vector<vi> memo(n + 1, vi(maxTotalPrice + 1, 0));

    for (int i = 1; i <= n; i++) {
        int pi = prices[i - 1], pa = pages[i - 1];

        for (int sz = 1; sz <= maxTotalPrice; sz++) {
            // Opção 1: Não comprar o livro atual
            memo[i][sz] = memo[i - 1][sz];

            // Opção 2: Comprar o livro atual (se o orçamento permitir)
            if (sz >= pi && memo[i - 1][sz - pi] + pa > memo[i][sz]) {
                memo[i][sz] = memo[i - 1][sz - pi] + pa;
            }
        }
    }
    return memo[n][maxTotalPrice];
}