/* ==============================================================================
 * Variante: Misère Nim
 * Descrição: Jogo do Nim normal, mas o ÚLTIMO jogador a fazer um movimento
 * PERDE.
 * ==============================================================================
 */
bool misere_nim_winner(const vector<int>& piles) {
    int xor_sum = 0;
    bool all_ones = true;

    for (int x : piles) {
        xor_sum ^= x;
        if (x > 1) all_ones = false;
    }

    // Se todas as pilhas têm apenas 1 pedra, ganha quem deixa um número ímpar
    // de pilhas
    if (all_ones) {
        return piles.size() % 2 == 0;
    }

    // Caso contrário, a estratégia é exatamente igual ao Nim normal
    return xor_sum != 0;
}