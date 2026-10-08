/* ==============================================================================
 * Algoritmo: Segment Tree (Range Minimum Query - RMQ)
 * Complexidade: Construção O(N). Update e Query O(log N). Memória O(4*N).
 * Descrição: Encontra o valor mínimo num intervalo [L, R] e atualiza
 * valores em índices específicos.
 * NOTA: O elemento neutro para queries de mínimo é o INF (infinito).
 * ==============================================================================
 */
#include <bits/stdc++.h>
using namespace std;

struct MinSegTree {
    int n;
    vector<long long> tree;
    const long long INF = 1e18;  // Elemento neutro para o mínimo

    MinSegTree(int n) {
        this->n = n;
        tree.assign(4 * n, INF);
    }

    // Constrói a árvore a partir de um array inicial em O(N)
    void build(const vector<long long>& a, int node, int left, int right) {
        if (left == right) {
            tree[node] = a[left];
            return;
        }
        int mid = left + (right - left) / 2;
        build(a, node * 2, left, mid);
        build(a, node * 2 + 1, mid + 1, right);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    // Atualiza um índice específico: arr[idx] = val
    void update(int node, int left, int right, int idx, long long val) {
        if (left == right) {
            tree[node] = val;
            return;
        }
        int mid = left + (right - left) / 2;
        if (idx <= mid) {
            update(node * 2, left, mid, idx, val);
        } else {
            update(node * 2 + 1, mid + 1, right, idx, val);
        }
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    // Retorna o mínimo no intervalo [ql, qr]
    long long query(int node, int left, int right, int ql, int qr) {
        // Intervalo totalmente fora da query
        if (left > qr || right < ql) return INF;

        // Intervalo totalmente contido na query
        if (left >= ql && right <= qr) return tree[node];

        // Intervalo parcialmente contido
        int mid = left + (right - left) / 2;
        long long res_left = query(node * 2, left, mid, ql, qr);
        long long res_right = query(node * 2 + 1, mid + 1, right, ql, qr);

        return min(res_left, res_right);
    }

    // Funções de interface limpas (0-indexed)
    void build(const vector<long long>& a) { build(a, 1, 0, n - 1); }
    void update(int idx, long long val) { update(1, 0, n - 1, idx, val); }
    long long query(int l, int r) { return query(1, 0, n - 1, l, r); }
};