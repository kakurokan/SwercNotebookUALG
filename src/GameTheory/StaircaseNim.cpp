/* ==============================================================================
 * Variante: Staircase Nim (Nim em Escadas)
 * Descrição: Os jogadores movem moedas do degrau 'i' para 'i-1'. As moedas
 * no degrau 0 são removidas do jogo.
 * Regra: É equivalente a um Nim clássico onde APENAS os degraus ÍMPARES
 * contam para o XOR-Sum.
 * ==============================================================================
 */
bool staircase_nim_winner(const vector<int>& stairs) {
    int xor_sum = 0;
    // Assume-se que stairs[1] é o primeiro degrau, stairs[2] o segundo, etc.
    for (int i = 1; i < stairs.size(); i += 2) {
        xor_sum ^= stairs[i];
    }
    return xor_sum != 0;
}