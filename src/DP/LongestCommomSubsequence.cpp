/* 
 * Problema: Longest Common Subsequence
 * Algoritmo: DP 2D Classico + Backtracking
 * Descricao: Encontra a maior subsequencia comum entre dois vetores e imprime
 * o comprimento e os elementos dessa subsequencia, reconstituindo o caminho.
 */
void solve(vi base, vi target) {
    int n = base.size(), m = target.size();
    vector<vi> memo(n + 1, vi(m + 1, 0));

    // 1. Construir a Tabela DP
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (base[i - 1] == target[j - 1]) {
                memo[i][j] = memo[i - 1][j - 1] + 1;
            } else {
                memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);
            }
        }
    }

    // 2. Reconstruir a Subsecuencia (Backtracking do fim para o inicio)
    vi result;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (base[i - 1] == target[j - 1]) {
            result.push_back(base[i - 1]);
            i--;
            j--;
        }
        // Desloca para a direcao de onde veio o valor maximo
        else if (memo[i - 1][j] > memo[i][j - 1]) {
            i--;  // O valor otimo veio de cima
        } else {
            j--;  // O valor otimo veio da esquerda
        }
    }

    cout << result.size() << '\n';
    // A resposta e recolhida de tras para a frente
    for (int k = result.size() - 1; k >= 0; k--) {
        cout << result[k] << (k == 0 ? "\n" : " ");
    }
}
