    /**
     * Resolve o Problema de Soma de Subconjuntos para encontrar todas as somas possíveis.
     * @param coins Array de valores dos itens (moedas).
     * @param n Número de itens.
     */
    public static void dynamic(int[] coins, int n) {
        // Calcula a soma máxima possível (o tamanho da segunda dimensão da tabela DP).
        int max = Arrays.stream(coins).sum();

        // memo[i][j] é TRUE se a soma 'j' for possível usando os primeiros 'i' itens.
        boolean[][] memo = new boolean[n + 1][max + 1];

        // Caso Base: A soma 0 é sempre possível com 0 itens.
        memo[0][0] = true;

        // Itera sobre os itens (de 1 até n).
        for (int i = 1; i <= n; i++) {
            // Itera sobre todas as somas possíveis (de 0 até a soma total).
            for (int j = 0; j <= max; j++) {

                // Opção 1: Não incluir o item atual (coins[i-1]).
                // Se a soma 'j' já era possível com os itens anteriores (i-1),
                // ela continua sendo possível (memo[i][j] = true).
                if (memo[i - 1][j]) {
                    memo[i][j] = true;
                    continue; // Somas já resolvidas continuam na próxima iteração
                }

                // Opção 2: Incluir o item atual.
                // a é a soma restante necessária.
                int a = j - coins[i - 1];

                // Se a soma restante 'a' for válida (>= 0) E era possível de ser formada
                // com os itens anteriores (memo[i - 1][a]), então a soma 'j' é possível.
                if (a >= 0 && memo[i - 1][a])
                    memo[i][j] = true;
            }
        }

        ArrayList<Integer> sums = new ArrayList<>();
        // Percorre a última linha da tabela DP (memo[n]) para coletar todas as somas possíveis.
        for (int i = 1; i <= max; i++)
            if (memo[n][i]) // Se memo[n][i] é true, a soma 'i' é alcançável.
                sums.add(i);

        int k = sums.size(); // K: Número total de somas possíveis.
        System.out.println(k);

        // Imprime todas as somas encontradas.
        for (int i = 0; i < k; i++)
            System.out.print(sums.get(i) + " ");
    }
}