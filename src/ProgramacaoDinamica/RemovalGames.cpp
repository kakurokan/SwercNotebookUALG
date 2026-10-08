/* ==============================================================================
 * Problema: Removal Game
 * Algoritmo: Range DP (DP em Intervalos)
 * Descrição: Dois jogadores apanham itens extremos do array alternadamente.
 * Maximizar a pontuação do primeiro jogador.
 * Percorre os intervalos (gaps) por ordem crescente de comprimento.
 * ==============================================================================
 */
ll solve(int listSize, vi list) {
    int n = listSize;
    // scores[i][j] armazena o melhor delta (Score_1 - Score_2) para [i...j]
    vector<vector<ll>> scores(n, vector<ll>(n, 0));

    // g é o "gap" ou tamanho do intervalo (j - i)
    for (int g = 0; g < n; ++g) {
        for (int i = 0, j = g; j < n; ++i, ++j) {
            if (g == 0) {
                // Intervalo de tamanho 1
                scores[i][j] = list[i];
            } else if (g == 1) {
                // Intervalo de tamanho 2
                scores[i][j] = max(list[i], list[j]);
            } else {
                // Opção 1: apanhar list[i]. O adversário forçará o pior caso
                // para nós
                ll val1 = list[i] + min(scores[i + 2][j], scores[i + 1][j - 1]);

                // Opção 2: apanhar list[j]. O adversário forçará o pior caso
                // para nós
                ll val2 = list[j] + min(scores[i + 1][j - 1], scores[i][j - 2]);

                scores[i][j] = max(val1, val2);
            }
        }
    }
    return scores[0][n - 1];
}