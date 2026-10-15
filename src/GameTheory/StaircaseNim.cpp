/* =============================================================================
 * Variante: Staircase Nim (Nim em Escadas)
 * Descricao: Os jogadores movem moedas do degrau 'i' para 'i-1'. As moedas
 * no degrau 0 sao removidas do jogo.
 * Regra: E equivalente a um Nim classico onde APENAS os degraus IMPARES
 * contam para o XOR-Sum.
 * =============================================================================
 */
bool staircase_nim_winner(const vector<int>& stairs) {
    int xor_sum = 0;
    // Assume-se que stairs[1] e o primeiro degrau, stairs[2] o segundo, etc.
    for (int i = 1; i < stairs.size(); i += 2) {
        xor_sum ^= stairs[i];
    }
    return xor_sum != 0;
}
