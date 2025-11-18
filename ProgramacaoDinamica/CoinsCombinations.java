public static int dynamic(int n, int[] arr) {
    // Tabela DP 1D. memo[i] armazena o número de maneiras de formar a soma 'i'.
    int[] memo = new int[n + 1];

    // Caso Base: Há 1 maneira de formar a soma 0 (usando o conjunto vazio).
    memo[0] = 1;

    // Itera sobre as somas 'i' a serem alcançadas, de 1 até N (a soma alvo).
    for (int i = 1; i <= n; i++) {

        // Itera sobre cada valor de moeda 'c' disponível.
        for (int c : arr) {

            // 'a' é a soma restante necessária (i - c).
            int a = i - c;

            // Condição: Se a soma restante 'a' é válida (não negativa).
            if (a >= 0) {
                /*
                 * Transição de DP:
                 * O número de maneiras de formar a soma 'i' é a soma das maneiras de formar
                 * a soma restante 'a' (memo[a]).
                 * Isso reflete a fórmula: solve(x) = ∑ solve(x - c) para cada moeda c[cite: 1837].
                 */
                memo[i] += memo[a];

                // Aplica o módulo para evitar overflow de inteiro.
                memo[i] %= 1000000007;
            }
        }
    }

    // Retorna o número de maneiras de formar a soma alvo N.
    return memo[n];
}
