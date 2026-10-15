/* 
 * Algoritmo: Mo's Algorithm (Offline Range Queries)
 * Complexidade: O((N + Q) * sqrt(N))
 * Descrição: Ordena as queries por blocos para minimizar o movimento dos
 * ponteiros 'left' e 'right'.
 */
#include <bits/stdc++.h>
using namespace std;

int BLOCK_SIZE;

struct Query {
    int l, r, id;

    // Ordenação
    bool operator<(const Query& other) const {
        int block_own = l / BLOCK_SIZE;
        int block_other = other.l / BLOCK_SIZE;
        if (block_own != block_other) return block_own < block_other;
        // Otimização: alterna a direção de ordenação do R consoante o bloco ser
        // par/ímpar
        return (block_own & 1) ? (r < other.r) : (r > other.r);
    }
};

// Variáveis globais para o estado atual (exemplo: contar distintos)
int current_answer = 0;
// int freq[MAX_VAL];

void add(int idx, const vector<int>& a) {
    // Lógica para adicionar a[idx] ao estado atual
}

void remove(int idx, const vector<int>& a) {
    // Lógica para remover a[idx] do estado atual
}

vector<int> mos_algorithm(vector<int>& a, vector<Query>& queries) {
    int n = a.size();
    BLOCK_SIZE = max(1, (int)sqrt(n));
    sort(queries.begin(), queries.end());

    vector<int> answers(queries.size());
    int cur_l = 0, cur_r = -1;

    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l, a);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r, a);
        }
        while (cur_l < q.l) {
            remove(cur_l, a);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r, a);
            cur_r--;
        }

        answers[q.id] = current_answer;
    }
    return answers;
}