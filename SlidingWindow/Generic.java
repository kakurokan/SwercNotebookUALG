public static int solveVariableWindow(int[] nums, int target) {
    int n = nums.length;
    int l = 0, r = 0;
    int currentSum = 0;
    int minLength = Integer.MAX_VALUE; // ou maxLength = 0

    // Expande a janela para a direita
    while (r < n) {
        // 1. Adiciona o elemento da direita à janela
        int valRight = nums[r];
        currentSum += valRight;

        // 2. Contrai a janela da esquerda enquanto a condição for satisfeita (ou quebrada)
        // Exemplo: Enquanto a soma for maior ou igual ao alvo
        while (currentSum >= target) {
            // Atualiza a melhor resposta
            minLength = Math.min(minLength, r - l + 1);

            // Remove o elemento da esquerda
            int valLeft = nums[l];
            currentSum -= valLeft;
            l++;
        }

        // Move ponteiro direito
        r++;
    }

    return minLength == Integer.MAX_VALUE ? 0 : minLength;
}