/* =============================================================================
 * Problema Tipico: Maior Subarray com Restricao (Ex: Soma <= Target)
 * Algoritmo: Dois Ponteiros / Janela Variavel (Sliding Window)
 * Descricao: O ponteiro 'right' avanca sempre. O 'left' avanca apenas para 
 * corrigir a janela quando esta se torna invalida.
 * Complexidade: O(N) Tempo (os ponteiros so andam para a frente)
 * ============================================================================= */
#include <bits/stdc++.h>
using namespace std;

int generic_sliding_window(const vector<int>& arr, long long target) {
    int n = arr.size();
    int max_len = 0;
    long long current_sum = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        // 1. Adiciona o elemento atual a janela
        current_sum += arr[right];

        // 2. Se a janela se tornou invalida, encolhe pela esquerda ate voltar a ser valida
        while (current_sum > target && left <= right) {
            current_sum -= arr[left];
            left++;
        }

        // 3. Neste ponto a janela [left, right] e garantidamente valida.
        // Atualiza a resposta (ex: tamanho maximo).
        max_len = max(max_len, right - left + 1);
    }
    
    return max_len;
}
