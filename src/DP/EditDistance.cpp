/* ==============================================================================
 * Problema: Edit Distance (Distância de Levenshtein)
 * Algoritmo: DP 2D Baseado em Strings
 * Descrição: Número mínimo de inserções, remoções e substituições para
 * transformar a string base na target.
 * ==============================================================================
 */
int solve() {
    string base, target;
    getline(cin, base);
    getline(cin, target);

    if (base == target) return 0;
    if (target.empty()) return base.length();
    if (base.empty()) return target.length();

    int n = base.length(), m = target.length();
    vector<vi> memo(n + 1, vi(m + 1, 0));

    // Casos base: transformar de/para strings vazias
    for (int i = 1; i <= n; i++) memo[i][0] = i;
    for (int i = 1; i <= m; i++) memo[0][i] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (base[i - 1] == target[j - 1]) {
                memo[i][j] = memo[i - 1][j - 1];  // Sem custo
            } else {
                memo[i][j] = min({
                                 memo[i - 1][j - 1],  // Substituição
                                 memo[i - 1][j],      // Remoção
                                 memo[i][j - 1]       // Inserção
                             }) +
                             1;
            }
        }
    }
    return memo[n][m];
}