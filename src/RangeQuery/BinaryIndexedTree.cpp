/* ==============================================================================
 * Algoritmo: Segment Tree com Lazy Propagation (Soma em Intervalo)
 * Complexidade: O(log N) para updates e queries. Memória O(4*N).
 * Descrição: Resolve atualizações e consultas em ranges (ex: [L, R]).
 * Para mudar para Máximo/Mínimo: alterar as funções de merge no update/query.
 * ==============================================================================
 */
struct LazySegTree {
    int n;
    vector<long long> tree, lazy;

    LazySegTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    // Empurra a atualização pendente para os nós filhos
    void push(int node, int left, int right) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node] * (right - left + 1);
            if (left != right) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int left, int right, int ql, int qr, long long val) {
        push(node, left, right);
        if (left > right || left > qr || right < ql) return;

        if (left >= ql && right <= qr) {
            lazy[node] += val;
            push(node, left, right);
            return;
        }

        int mid = left + (right - left) / 2;
        update(node * 2, left, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, right, ql, qr, val);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    long long query(int node, int left, int right, int ql, int qr) {
        push(node, left, right);
        if (left > right || left > qr || right < ql) return 0;

        if (left >= ql && right <= qr) return tree[node];

        int mid = left + (right - left) / 2;
        long long res_left = query(node * 2, left, mid, ql, qr);
        long long res_right = query(node * 2 + 1, mid + 1, right, ql, qr);

        return res_left + res_right;
    }

    // Funções de interface limpas para chamar na main() (0-indexed)
    void update(int l, int r, long long val) { update(1, 0, n - 1, l, r, val); }
    long long query(int l, int r) { return query(1, 0, n - 1, l, r); }
};