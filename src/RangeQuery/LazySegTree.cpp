/**
 * Segment Tree Recursiva com Lazy Propagation.
 * Ideal para: Range Updates (atualizar um intervalo inteiro) e Range Queries.
 * Complexidade: O(log N) para update e query.
 * Espaco: 4 * N.
 */
public static class LazySegTree {
    // 'tree': Armazena o valor agregado (soma, min, max) do intervalo.
    // 'lazy': Armazena o valor de atualizacao pendente que AINDA NAO foi repassado para os filhos.
    long[] tree, lazy;
    int n;

    public LazySegTree(int n) {
        this.n = n;
        // O tamanho 4*N e uma cota superior segura para uma arvore binaria completa
        // que cobre N elementos.
        tree = new long[4 * n];
        lazy = new long[4 * n];
    }

    /**
     * A funcao PUSH (Propagate).
     * Esta e a magica da Lazy Propagation. Antes de descer para os filhos de um no,
     * verificamos se ha alguma atualizacao pendente ("preguicosa") neste no.
     * Se houver, nos a aplicamos aos filhos AGORA e limpamos a preguica do pai.
     */
    private void push(int node, int start, int end) {
        // Se nao houver nada pendente (0), nao faz nada.
        if (lazy[node] != 0) {

            // Se nao for um no folha (tem filhos), propaga a informacao.
            if (start != end) {
                int mid = (start + end) / 2;

                // --- Filho Esquerdo (2*node) ---
                // 1. Repassa a responsabilidade (o valor lazy) para o filho
                lazy[2 * node] += lazy[node];
                // 2. Atualiza o valor REAL (tree) do filho imediatamente, para que
                //    futuras consultas nele estejam corretas sem precisar descer mais.
                //    NOTA: Multiplicamos pelo tamanho do intervalo ((mid - start + 1)) porque e SOMA.
                //          Se fosse MINIMO ou MAXIMO, nao multiplicaria, apenas somaria.
                tree[2 * node] += lazy[node] * (mid - start + 1);

                // --- Filho Direito (2*node + 1) ---
                lazy[2 * node + 1] += lazy[node];
                tree[2 * node + 1] += lazy[node] * (end - mid);
            }

            // Como ja empurramos a atualizacao para baixo, limpamos a "preguica" do no atual.
            lazy[node] = 0;
        }
    }

    // Funcao publica para chamar a atualizacao (interface amigavel)
    // Adiciona 'val' a todos os elementos no intervalo [l, r]
    public void update(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }

    // Funcao interna recursiva de atualizacao
    // node: indice atual na arvore | start, end: intervalo que este no cobre
    // l, r: intervalo que queremos atualizar | val: valor a adicionar
    private void update(int node, int start, int end, int l, int r, int val) {
        // Caso 1: O intervalo do no atual esta totalmente FORA do intervalo de atualizacao.
        if (l > end || r < start) return;

        // Caso 2: O intervalo do no atual esta TOTALMENTE DENTRO do intervalo de atualizacao.
        // Aqui acontece a otimizacao: Atualizamos este no e marcamos o 'lazy' para nao descer mais.
        if (l <= start && end <= r) {
            lazy[node] += val; // Acumula a preguica
            tree[node] += (long) val * (end - start + 1); // Atualiza o valor deste no
            return; // RETORNA IMEDIATAMENTE! Nao desce para os filhos (O(log N)).
        }

        // Caso 3: Intersecao parcial. Precisamos descer.
        // Antes de descer, TEMOS que empurrar qualquer sujeira antiga (push).
        push(node, start, end);

        int mid = (start + end) / 2;
        // Recurso para esquerda e direita
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);

        // Na volta da recursao (backtracking), atualizamos o valor do no atual
        // baseando-se nos valores atualizados dos filhos (Pull/Merge).
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    // Funcao publica para consulta
    public long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    private long query(int node, int start, int end, int l, int r) {
        // Caso 1: Totalmente fora. Retorna elemento neutro (0 para soma).
        if (l > end || r < start) return 0;

        // Caso 2: Totalmente dentro. Retorna o valor armazenado.
        // Gracas ao 'push' e 'update' corretos, este valor ja considera todas as atualizacoes
        // relevantes ou tem um 'lazy' pendente que ja foi contabilizado no 'tree[node]'.
        if (l <= start && end <= r) return tree[node];

        // Caso 3: Parcial. Empurra pendencias antes de consultar os filhos.
        push(node, start, end);

        int mid = (start + end) / 2;
        // Soma os resultados das consultas nos filhos
        return query(2 * node, start, mid, l, r) +
                query(2 * node + 1, mid + 1, end, l, r);
    }
}
