/*
 * Truques Bitwise e Funções Embutidas (GCC)
 * Descrição: Operações de tempo constante O(1) essenciais para manipular
 * conjuntos representados por inteiros (Bitmasks).
 */
#include <bits/stdc++.h>
using namespace std;

void bitwise_basics() {
    int x = 53;  // Exemplo em binário: 110101 (32 bits)
    int k = 3;   // Posição do bit (0-indexed, da direita para a esquerda)

    // NOTA: Para variáveis 'long long', usar o sufixo 'll' (ex:
    // __builtin_popcountll)

    int ativos = __builtin_popcount(
        x);  // Conta os bits '1'. Útil para saber o tamanho de um subconjunto.
    int zeros_esq =
        __builtin_clz(x);  // Zeros à esquerda (Count Leading Zeros).
    int zeros_dir =
        __builtin_ctz(x);  // Zeros à direita (Count Trailing Zeros). Útil para
                           // encontrar o primeiro '1'.

    bool check_bit = (x & (1 << k)) != 0;  // Verifica se o bit k está ativo (1)
    int set_bit = x | (1 << k);            // Ativa o bit k (força a 1)
    int clear_bit = x & ~(1 << k);         // Desativa o bit k (força a 0)
    int toggle_bit = x ^ (1 << k);  // Inverte o bit k (0 vira 1, 1 vira 0)

    // Verifica se um número X (onde X > 0) é uma potência exata de 2
    bool is_power_of_two = (x & (x - 1)) == 0;

    // Isola o bit '1' menos significativo (Lowest Set Bit).
    // É o motor matemático que faz a BinaryIndexedTree funcionar.
    int lowest_set_bit = x & -x;

    // Apaga o bit '1' menos significativo
    int remove_lowest_bit = x & (x - 1);
}

/*
 * Iteração de Submáscaras (Submask Enumeration)
 * Descrição: Dado um bitmask que representa um conjunto, este ciclo itera
 * eficientemente por todos os seus subconjuntos válidos.
 * Aplicação: Evita iterar de 0 até (1<<N), reduzindo a complexidade de
 * DP com máscaras de O(4^N) para O(3^N).
 */
void iterate_submasks(int mask) {
    for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
        // Processar o subconjunto 'submask'
    }
}