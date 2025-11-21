/**
 * Binary Indexed Tree (Fenwick Tree)
 * * Suporta: Point Update (soma) e Range Sum Query.
 * * Indexação: 1-based (Internamente). O código lida com arrays 0-based se necessário.
 */
public static class BIT {
    long[] tree;
    int n;

    public BIT(int size) {
        this.n = size;
        // Tamanho n + 1 porque a BIT usa índices de 1 a n.
        // O índice 0 não é utilizado para simplificar a lógica de bits.
        tree = new long[n + 1];
    }

    /**
     * Adiciona 'delta' ao valor no índice 'i'.
     * Referência: "Updating a value" [cite: 2344-2350]
     * Lógica: Subimos na árvore somando o bit menos significativo (LSB).
     */
    public void add(int i, long delta) {
        // Garante que estamos trabalhando com 1-based indexing se a entrada for 0-based
        i++;

        while (i <= n) {
            tree[i] += delta;
            // i & -i isola o bit menos significativo (LSB).
            // Ex: se i = 6 (110), -i é (010) em complemento de dois. i & -i = 2 (010).
            // Somar isso move para o próximo intervalo que "cobre" este índice.
            i += i & -i;
        }
    }

    /**
     * Retorna a soma do prefixo [0...i].
     * Referência: "Processing a range sum query"
     * Lógica: Descemos na árvore subtraindo o LSB.
     */
    public long prefixSum(int i) {
        i++; // Ajuste para 1-based
        long sum = 0;
        while (i > 0) {
            sum += tree[i];
            // Remove o LSB para pular para o final do intervalo anterior.
            // Ex: De 7 (111) vai para 6 (110), depois 4 (100), depois 0.
            i -= i & -i;
        }
        return sum;
    }

    /**
     * Retorna a soma do intervalo [l, r].
     * Baseado na fórmula clássica de soma de prefixos: sum(r) - sum(l-1).
     */
    public long query(int l, int r) {
        if (l > r) return 0;
        return prefixSum(r) - prefixSum(l - 1);
    }
}