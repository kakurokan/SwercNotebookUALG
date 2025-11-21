    /**
     * @param n Número de itens (livros).
     * @param x Orçamento máximo.
     * @param prices Custos/Pesos dos itens.
     * @param pages Páginas/Valores dos itens.
     * @return O número máximo de páginas que podem ser compradas.
     */
    public static int dynamic(int n, int x, int[] prices, int[] pages) {
        // Cria a tabela de memoização (DP table).
        // memo[i][j] armazena o número máximo de páginas usando os primeiros 'i' livros com orçamento 'j'.
        int[][] memo = new int[n + 1][x + 1];

        // Itera sobre os itens (livros), de 1 até n.
        for (int i = 1; i <= n; i++) {
            // Obtém o preço e o valor do item atual (usamos i-1 porque os arrays são 0-indexados).
            int price = prices[i - 1];
            int page = pages[i - 1];

            // Itera sobre todas as capacidades/orçamentos possíveis, de 1 até x.
            for (int j = 1; j <= x; j++) {

                // Condição: Se o orçamento atual (j) for suficiente para comprar o livro (price).
                if (j >= price) {
                    /*
                     * Lógica da DP (Transição):
                     * memo[i][j] será o máximo entre duas opções:
                     * 1. Não incluir o item 'i': memo[i - 1][j]
                     * 2. Incluir o item 'i': memo[i - 1][j - price] + page
                     * (Melhor resultado anterior para o orçamento restante + valor do item atual)
                     */
                    memo[i][j] = Math.max(memo[i - 1][j], memo[i - 1][j - price] + page);
                } else {
                    // Condição: O orçamento atual não é suficiente para o livro.
                    // A única opção é não incluir o item, copiando o valor da linha anterior.
                    memo[i][j] = memo[i - 1][j];
                }
            }
        }

        // O resultado final é o valor máximo que pode ser alcançado com todos os 'n' itens e orçamento 'x'.
        return memo[n][x];
    }
}