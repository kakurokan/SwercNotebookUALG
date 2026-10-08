/* ==============================================================================
 * Problema Típico: Sliding Window Minimum / Maximum
 * Algoritmo: Monotonic Queue (Fila Monotónica) usando std::deque
 * Descrição: Encontra o mínimo (ou máximo) em todas as janelas de tamanho K.
 * Complexidade: O(N) Tempo | O(K) Memória
 * ============================================================================== */
#include <bits/stdc++.h>
using namespace std;

vector<int> sliding_window_minimum(const vector<int>& arr, int k) {
    vector<int> res;
    deque<int> dq; // Guarda os *índices* dos elementos, não os valores

    for (int i = 0; i < arr.size(); i++) {
        // 1. Remove os índices que já ficaram fora da janela atual [i - k + 1, i]
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        
        // 2. Mantém a fila monotónica: remove pela direita tudo o que é maior ou igual 
        // ao elemento atual, pois nunca será o mínimo desta janela nem das futuras.
        // (Para Sliding Window Maximum, basta mudar para arr[dq.back()] <= arr[i])
        while (!dq.empty() && arr[dq.back()] >= arr[i]) {
            dq.pop_back();
        }
        
        // 3. Insere o índice do elemento atual
        dq.push_back(i);
        
        // 4. A partir do momento em que a primeira janela atinge o tamanho K,
        // o mínimo estará sempre na frente da deque.
        if (i >= k - 1) {
            res.push_back(arr[dq.front()]);
        }
    }
    return res;
}
