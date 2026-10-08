/**
 * Segment Tree Recursiva com Lazy Propagation.
 * Ideal para: Range Updates (atualizar um intervalo inteiro) e Range Queries.
 * Complexidade: O(log N) para update e query.
 * Espaço: 4 * N.
 */
public static class LazySegTree {
    // 'tree': Armazena o valor agregado (soma, min, max) do intervalo.
    // 'lazy': Armazena o valor de atualização pendente que AINDA NÃO foi repassado para os filhos.
    long[] tree, lazy;
    int n;

    public LazySegTree(int n) {
        this.n = n;
        // O tamanho 4*N é uma cota superior segura para uma árvore binária completa
        // que cobre N elementos.
        tree = new long[4 * n];
        lazy = new long[4 * n];
    }

    /**
     * A função PUSH (Propagate).
     * Esta é a mágica da Lazy Propagation. Antes de descer para os filhos de um nó,
     * verificamos se há alguma atualização pendente ("preguiçosa") neste nó.
     * Se houver, nós a aplicamos aos filhos AGORA e limpamos a preguiça do pai.
     */
    private void push(int node, int start, int end) {
        // Se não houver nada pendente (0), não faz nada.
        if (lazy[node] != 0) {

            // Se não for um nó folha (tem filhos), propaga a informação.
            if (start != end) {
                int mid = (start + end) / 2;

                // --- Filho Esquerdo (2*node) ---
                // 1. Repassa a responsabilidade (o valor lazy) para o filho
                lazy[2 * node] += lazy[node];
                // 2. Atualiza o valor REAL (tree) do filho imediatamente, para que
                //    futuras consultas nele estejam corretas sem precisar descer mais.
                //    NOTA: Multiplicamos pelo tamanho do intervalo ((mid - start + 1)) porque é SOMA.
                //          Se fosse MÍNIMO ou MÁXIMO, não multiplicaria, apenas somaria.
                tree[2 * node] += lazy[node] * (mid - start + 1);

                // --- Filho Direito (2*node + 1) ---
                lazy[2 * node + 1] += lazy[node];
                tree[2 * node + 1] += lazy[node] * (end - mid);
            }

            // Como já empurramos a atualização para baixo, limpamos a "preguiça" do nó atual.
            lazy[node] = 0;
        }
    }

    // Função pública para chamar a atualização (interface amigável)
    // Adiciona 'val' a todos os elementos no intervalo [l, r]
    public void update(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }

    // Função interna recursiva de atualização
    // node: índice atual na árvore | start, end: intervalo que este nó cobre
    // l, r: intervalo que queremos atualizar | val: valor a adicionar
    private void update(int node, int start, int end, int l, int r, int val) {
        // Caso 1: O intervalo do nó atual está totalmente FORA do intervalo de atualização.
        if (l > end || r < start) return;

        // Caso 2: O intervalo do nó atual está TOTALMENTE DENTRO do intervalo de atualização.
        // Aqui acontece a otimização: Atualizamos este nó e marcamos o 'lazy' para não descer mais.
        if (l <= start && end <= r) {
            lazy[node] += val; // Acumula a preguiça
            tree[node] += (long) val * (end - start + 1); // Atualiza o valor deste nó
            return; // RETORNA IMEDIATAMENTE! Não desce para os filhos (O(log N)).
        }

        // Caso 3: Interseção parcial. Precisamos descer.
        // Antes de descer, TEMOS que empurrar qualquer sujeira antiga (push).
        push(node, start, end);

        int mid = (start + end) / 2;
        // Recurso para esquerda e direita
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);

        // Na volta da recursão (backtracking), atualizamos o valor do nó atual
        // baseando-se nos valores atualizados dos filhos (Pull/Merge).
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    // Função pública para consulta
    public long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    private long query(int node, int start, int end, int l, int r) {
        // Caso 1: Totalmente fora. Retorna elemento neutro (0 para soma).
        if (l > end || r < start) return 0;

        // Caso 2: Totalmente dentro. Retorna o valor armazenado.
        // Graças ao 'push' e 'update' corretos, este valor já considera todas as atualizações
        // relevantes ou tem um 'lazy' pendente que já foi contabilizado no 'tree[node]'.
        if (l <= start && end <= r) return tree[node];

        // Caso 3: Parcial. Empurra pendências antes de consultar os filhos.
        push(node, start, end);

        int mid = (start + end) / 2;
        // Soma os resultados das consultas nos filhos
        return query(2 * node, start, mid, l, r) +
                query(2 * node + 1, mid + 1, end, l, r);
    }
}