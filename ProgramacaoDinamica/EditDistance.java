    /**
     * Calcula a Distância de Edição (Levenshtein Distance) entre duas strings.
     * @param st1 Primeira string.
     * @param st2 Segunda string.
     * @return A distância mínima de edição.
     */
    public static int dynamic(String st1, String st2) {
        int n = st1.length(), m = st2.length();

        // memo[y][x] armazena a distância de edição entre os prefixos st1[0...y-1] e st2[0...x-1].
        int[][] memo = new int[n + 1][m + 1];

        // Inicializa a primeira coluna: Distância de editar st1 em uma string vazia st2.
        // Requer 'y' remoções/inserções para o prefixo st1 de tamanho 'y'.
        for (int y = 0; y <= n; y++) {
            memo[y][0] = y;
        }

        // Inicializa a primeira linha: Distância de editar uma string vazia st1 em st2.
        // Requer 'x' inserções/remoções para o prefixo st2 de tamanho 'x'.
        for (int x = 0; x <= m; x++) {
            memo[0][x] = x;
        }

        // Itera sobre os prefixos de st1 (linhas, de tamanho 1 até n).
        for (int y = 1; y <= n; y++) {
            // Itera sobre os prefixos de st2 (colunas, de tamanho 1 até m).
            for (int x = 1; x <= m; x++) {

                // Determina o custo de "casamento" ou "modificação" (match/modify).
                // sum = 0 se os caracteres forem iguais (match), 1 se forem diferentes (modify).
                int sum = st1.charAt(y - 1) == st2.charAt(x - 1) ? 0 : 1;

                /*
                 * Lógica de Transição (Encontrando o Mínimo de 3 Opções):
                 * memo[y][x] é o mínimo custo para alcançar o estado atual, considerando:
                 * * 1. Inserção (chegar de st1[y] e st2[x-1]): memo[y][x - 1] + 1
                 * (Corresponde a adicionar o último caractere de st2 em st1).
                 * * 2. Modificação/Match (chegar de st1[y-1] e st2[x-1]): memo[y - 1][x - 1] + sum
                 * (Corresponde a modificar st1[y-1] para st2[x-1], ou match se sum=0).
                 * * 3. Remoção (chegar de st1[y-1] e st2[x]): memo[y - 1][x] + 1
                 * (Corresponde a remover o último caractere de st1).
                 */
                memo[y][x] = Math.min(memo[y][x - 1] + 1, Math.min(memo[y - 1][x - 1] + sum, memo[y - 1][x] + 1));
            }
        }
        // O resultado final é a distância de edição completa, localizada no canto inferior direito da tabela.
        return memo[n][m];
    }
}