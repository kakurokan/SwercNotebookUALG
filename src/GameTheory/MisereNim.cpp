/* =============================================================================
 * Variante: Misere Nim
 * Descricao: Jogo do Nim normal, mas o ULTIMO jogador a fazer um movimento
 * PERDE.
 * =============================================================================
 */
bool misere_nim_winner(const vector<int>& piles) {
    int xor_sum = 0;
    bool all_ones = true;

    for (int x : piles) {
        xor_sum ^= x;
        if (x > 1) all_ones = false;
    }

    // Se todas as pilhas tem apenas 1 pedra, ganha quem deixa um numero impar
    // de pilhas
    if (all_ones) {
        return piles.size() % 2 == 0;
    }

    // Caso contrario, a estrategia e exatamente igual ao Nim normal
    return xor_sum != 0;
}
