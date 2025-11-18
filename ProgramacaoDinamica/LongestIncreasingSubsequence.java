public static void dynamic(int n, int m, int[] arr1, int[] arr2) {
    // memo[i][j] armazena o comprimento do LCS entre os prefixos
    // arr1[0...i-1] e arr2[0...j-1].
    int[][] memo = new int[n + 1][m + 1];

    // Os casos base (linhas e colunas 0) são implicitamente 0 (inicialização padrão Java).

    // Itera sobre os prefixos do arr1.
    for (int i = 1; i <= n; i++) {
        // Itera sobre os prefixos do arr2.
        for (int j = 1; j <= m; j++) {

            // 1. Match (Os elementos atuais são iguais)
            if (arr1[i - 1] == arr2[j - 1]) {
                // O LCS aumenta em 1, vindo da solução da diagonal superior esquerda.
                memo[i][j] = 1 + memo[i - 1][j - 1];
            }

            // 2. Não-Match (Os elementos atuais são diferentes)
            else {
                /*
                 * O LCS é o máximo entre:
                 * a) Ignorar o elemento de arr1: memo[i - 1][j] (Movimento para cima)
                 * b) Ignorar o elemento de arr2: memo[i][j - 1] (Movimento para a esquerda)
                 */
                memo[i][j] = Math.max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
    }

    // Imprime o comprimento total do LCS (o valor no canto inferior direito).
    System.out.println(memo[n][m]);

    Stack<Integer> stack = new Stack<>(); // Usa Stack para obter a subsequência na ordem correta (FIFO).
    int i = n, j = m; // Começa pelo final da tabela.

    while (memo[i][j] != 0) { // Continua até chegar a um caso base (LCS de comprimento 0).

        // 1. Se os elementos atuais são iguais (O Match ocorreu aqui)
        if (arr1[i - 1] == arr2[j - 1]) {
            stack.push(arr1[i - 1]); // Adiciona o elemento à stack.
            i--; // Move na diagonal (consumindo um elemento de cada array).
            j--;
        }

        // 2. Se o valor veio da célula acima (Ignorou arr1[i-1])
        else if (memo[i - 1][j] >= memo[i][j - 1])
            i--; // Move para cima.
            // 3. Se o valor veio da célula à esquerda (Ignorou arr2[j-1])
        else
            j--; // Move para a esquerda.
    }

    // Imprime a subsequência, esvaziando a stack (o que inverte a ordem e imprime corretamente).
    while (!stack.isEmpty())
        System.out.print(stack.pop() + " ");
}