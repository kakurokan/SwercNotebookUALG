/* 
 * Problema: Minimal Grid Path
 * Algoritmo: Breadth-First Search (BFS) guiada por nivel
 * Descricao: Encontra o caminho lexicograficamente menor (formando uma string)
 * numa grelha N x N. Usa BFS sincrona para manter apenas as melhores opcoes por
 * nivel.
 */
string solve(vector<string> grid) {
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<pair<int, int>> active;

    string result = "";
    result += grid[0][0];
    active.push_back({0, 0});
    visited[0][0] = true;

    // O comprimento do caminho e exatamente 2*N - 2 passos
    for (int step = 0; step < 2 * n - 2; ++step) {
        char min_char = 'Z' + 1;  // Valor infinito (acima de 'Z')
        vector<pair<int, int>> next_candidates;

        // Avalia vizinhos de todas as celulas otimas do nivel atual
        for (auto [r, c] : active) {
            if (r + 1 < n) {
                if (grid[r + 1][c] < min_char) min_char = grid[r + 1][c];
                next_candidates.push_back({r + 1, c});
            }
            if (c + 1 < n) {
                if (grid[r][c + 1] < min_char) min_char = grid[r][c + 1];
                next_candidates.push_back({r, c + 1});
            }
        }

        result += min_char;
        active.clear();

        // Mantem para o proximo passo apenas os vizinhos que tem o min_char
        for (auto [r, c] : next_candidates) {
            if (grid[r][c] == min_char && !visited[r][c]) {
                visited[r][c] = true;
                active.push_back({r, c});
            }
        }
    }
    return result;
}
