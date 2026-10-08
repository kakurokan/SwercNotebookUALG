/* ==============================================================================
 * Algoritmo: Binary Search on Answer
 * Descrição: Encontra o primeiro valor no intervalo [low, high] que satisfaz
 * a função check(). Estrutura imune a off-by-one errors.
 * ==============================================================================
 */
bool check(long long mid) {
    // Implementar a lógica de validação do problema para o valor 'mid'
    return true;
}

long long binary_search_answer(long long low, long long high) {
    long long ans = -1;
    while (low <= high) {
        long long mid = low + (high - low) / 2;  // Previne overflow
        if (check(mid)) {
            ans = mid;       // Guarda o candidato válido
            high = mid - 1;  // Tenta encontrar um valor ainda menor (ajustar
                             // conforme o problema)
        } else {
            low = mid + 1;  // O valor atual é inválido, procura mais acima
        }
    }
    return ans;
}