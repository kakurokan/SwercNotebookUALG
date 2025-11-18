 /**
     * Calcula o número de caminhos válidos de (0,0) a (n-1, n-1) na grade,
     * movendo apenas para baixo ou para a direita, módulo MOD.
     * @param grid A matriz da grade com armadilhas ('*').
     * @param n O tamanho da grade.
     * @return O número total de caminhos.
     */
    public static int dynamic(char[][] grid, int n) {
        // Caso Base de Falha: Se a célula inicial for uma armadilha, não há caminhos.
        if (grid[0][0] == '*')
            return 0;

        // Tabela de Programação Dinâmica (DP table).
        // memo[y][x] armazenará o número de caminhos válidos de (0,0) até a célula (y, x).
        int[][] memo = new int[n][n];

        for (int y = 0; y < n; y++) { // Itera pelas linhas (y)
            for (int x = 0; x < n; x++) { // Itera pelas colunas (x)

                // 1. Caso Armadilha: Se a célula atual for uma armadilha ('*').
                if (grid[y][x] == '*') {
                    memo[y][x] = 0; // Não há caminhos para ou através de uma armadilha.

                    // 2. Caso Inicial: Se for a célula de partida (0, 0).
                } else if (y == 0 && x == 0)
                    memo[y][x] = 1; // Há exatamente 1 caminho para a célula inicial (o caminho trivial).

                    // 3. Caso Geral (Transição): Se for uma célula livre e não for a inicial.
                else {
                    /*
                     * Lógica de Transição:
                     * O número de caminhos para (y, x) é a soma dos caminhos que chegam de:
                     * A) Célula acima: memo[y - 1][x] (Se y > 0)
                     * B) Célula à esquerda: memo[y][x - 1] (Se x > 0)
                     */

                    // Soma caminhos da célula de cima (se estiver dentro dos limites y > 0)
                    memo[y][x] = (y > 0 ? memo[y - 1][x] : 0);

                    // Adiciona caminhos da célula à esquerda (se estiver dentro dos limites x > 0)
                    memo[y][x] += (x > 0 ? memo[y][x - 1] : 0);

                    // Aplica a operação de módulo para manter o resultado dentro do limite do inteiro e do MOD.
                    memo[y][x] %= MOD;
                }
            }
        }
        // O resultado é o número de caminhos para a célula do canto inferior direito (n-1, n-1).
        return memo[n - 1][n - 1];
    }
}