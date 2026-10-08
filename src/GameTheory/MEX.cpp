/* ==============================================================================
 * Algoritmo: Teorema de Sprague-Grundy (Função MEX)
 * Descrição: Calcula o valor de Grundy para um jogo imparcial qualquer.
 * MEX (Minimum Excluded) é o menor inteiro não negativo ausente num conjunto.
 * ==============================================================================
 */
// Função para encontrar o MEX de um conjunto de valores (estados seguintes)
int mex(const vector<int>& next_states_grundy_values) {
    unordered_set<int> s(next_states_grundy_values.begin(),
                         next_states_grundy_values.end());
    for (int i = 0;; i++) {
        if (!s.count(i)) return i;
    }
}

// Exemplo de cálculo de Grundy com Memoização (DP)
// 'moves' é o conjunto de jogadas válidas (ex: retirar 1, 3 ou 4 pedras)
int grundy(int n, const vector<int>& moves, vector<int>& memo) {
    if (n == 0) return 0;  // Posição perdedora
    if (memo[n] != -1) return memo[n];

    vector<int> next_states;
    for (int m : moves) {
        if (n >= m) {
            next_states.push_back(grundy(n - m, moves, memo));
        }
    }

    return memo[n] = mex(next_states);
}
// Para resolver o jogo, calculas o Grundy de cada pilha individualmente e
// fazes o XOR-Sum de todos os resultados. Se for != 0, o 1º jogador ganha.