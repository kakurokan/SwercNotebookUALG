public class SlidingWindow {

    /**
     * Retorna um array onde o índice 'i' contém o MÍNIMO da janela
     * que termina em 'i' com tamanho 'k'.
     */
    public static int[] slidingWindowMin(int[] nums, int k) {
        int n = nums.length;
        if (n == 0) return new int[0];

        int[] result = new int[n - k + 1];
        // Deque armazena ÍNDICES, não valores.
        // Mantemos o deque em ordem crescente de valores (para Mínimo).
        Deque<Integer> deque = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            // 1. Remove elementos fora da janela atual (pela frente)
            if (!deque.isEmpty() && deque.peekFirst() < i - k + 1) {
                deque.pollFirst();
            }

            // 2. Mantém a monotonicidade: remove elementos da cauda que são
            // MAIORES (ou iguais) que o atual, pois eles nunca serão o mínimo
            // enquanto o elemento atual 'nums[i]' estiver na janela.
            // (Para Sliding Window MAX, mude para: nums[deque.peekLast()] <= nums[i])
            while (!deque.isEmpty() && nums[deque.peekLast()] >= nums[i]) {
                deque.pollLast();
            }

            // 3. Adiciona o índice atual
            deque.offerLast(i);

            // 4. Registra a resposta (apenas quando a primeira janela estiver completa)
            if (i >= k - 1) {
                result[i - k + 1] = nums[deque.peekFirst()];
            }
        }
        return result;
    }
}