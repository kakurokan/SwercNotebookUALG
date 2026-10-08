/* ==============================================================================
 * Problema Típico: Maior Subarray com Restrição (Ex: Soma <= Target)
 * Algoritmo: Dois Ponteiros / Janela Variável (Sliding Window)
 * Descrição: O ponteiro 'right' avança sempre. O 'left' avança apenas para 
 * corrigir a janela quando esta se torna inválida.
 * Complexidade: O(N) Tempo (os ponteiros só andam para a frente)
 * ============================================================================== */
#include <bits/stdc++.h>
using namespace std;

int generic_sliding_window(const vector<int>& arr, long long target) {
    int n = arr.size();
    int max_len = 0;
    long long current_sum = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        // 1. Adiciona o elemento atual à janela
        current_sum += arr[right];

        // 2. Se a janela se tornou inválida, encolhe pela esquerda até voltar a ser válida
        while (current_sum > target && left <= right) {
            current_sum -= arr[left];
            left++;
        }

        // 3. Neste ponto a janela [left, right] é garantidamente válida.
        // Atualiza a resposta (ex: tamanho máximo).
        max_len = max(max_len, right - left + 1);
    }
    
    return max_len;
}
