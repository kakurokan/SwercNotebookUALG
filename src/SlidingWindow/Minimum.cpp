/* 
 * Problema Tipico: Sliding Window Minimum / Maximum
 * Algoritmo: Monotonic Queue (Fila Monotonica) usando std::deque
 * Descricao: Encontra o minimo (ou maximo) em todas as janelas de tamanho K.
 * Complexidade: O(N) Tempo | O(K) Memoria
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> sliding_window_minimum(const vector<int>& arr, int k) {
    vector<int> res;
    deque<int> dq; // Guarda os *indices* dos elementos, nao os valores

    for (int i = 0; i < arr.size(); i++) {
        // 1. Remove os indices que ja ficaram fora da janela atual [i - k + 1, i]
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        
        // 2. Mantem a fila monotonica: remove pela direita tudo o que e maior ou igual 
        // ao elemento atual, pois nunca sera o minimo desta janela nem das futuras.
        // (Para Sliding Window Maximum, basta mudar para arr[dq.back()] <= arr[i])
        while (!dq.empty() && arr[dq.back()] >= arr[i]) {
            dq.pop_back();
        }
        
        // 3. Insere o indice do elemento atual
        dq.push_back(i);
        
        // 4. A partir do momento em que a primeira janela atinge o tamanho K,
        // o minimo estara sempre na frente da deque.
        if (i >= k - 1) {
            res.push_back(arr[dq.front()]);
        }
    }
    return res;
}
