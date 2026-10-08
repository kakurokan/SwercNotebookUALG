/* ==============================================================================
 * Algoritmo: 2D Prefix Sums
 * Descrição: Pré-computa a soma de qualquer submatriz em O(N*M).
 * A consulta de uma área (r1, c1) até (r2, c2) é feita em O(1).
 * ============================================================================== */
void build_2d_prefix(const vector<vector<int>>& grid, vector<vector<long long>>& pref) {
    int R = grid.size(), C = grid[0].size();
    // pref[i][j] guarda a soma de (0,0) até (i-1, j-1)
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            pref[i][j] = grid[i-1][j-1] 
                       + pref[i-1][j] 
                       + pref[i][j-1] 
                       - pref[i-1][j-1];
        }
    }
}

// Retorna a soma do retângulo com canto superior esquerdo (r1, c1) e inferior direito (r2, c2)
// Coordenadas 0-indexed
long long query_2d(const vector<vector<long long>>& pref, int r1, int c1, int r2, int c2) {
    return pref[r2+1][c2+1] - pref[r1][c2+1] - pref[r2+1][c1] + pref[r1][c1];
}