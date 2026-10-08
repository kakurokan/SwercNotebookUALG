/* ==============================================================================
 * Algoritmo: Teoria de Jogos (Nim e Sprague-Grundy)
 * Descrição: Avaliação de estados vencedores em jogos imparciais.
 * ==============================================================================
 */
#include <bits/stdc++.h>
using namespace std;

// Jogo do Nim Clássico: N pilhas de pedras. Os jogadores alternam retirando
// 1 ou mais pedras de uma única pilha. O último a jogar ganha.
// Regra de Ouro: O 1º jogador ganha se e só se o XOR-Sum for diferente de 0.
bool nim_game_winner(const vector<int>& piles) {
    int xor_sum = 0;
    for (int x : piles) {
        xor_sum ^= x;
    }
    return xor_sum !=
           0;  // true se o jogador que vai iniciar tem estratégia vencedora
}