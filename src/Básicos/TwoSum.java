public static boolean twoSum(int[] arr, int sum) {
    // memo: Usa um HashSet para armazenar os elementos do array já vistos,
    // permitindo buscas eficientes O(1).
    HashSet<Integer> memo = new HashSet<>();

    // Itera sobre cada elemento do array.
    for (int i : arr) {
        // 'a' é o "complemento" necessário para atingir a soma alvo ('sum').
        int a = sum - i;

        /*
         * Condição de Retorno:
         * 1. Verifica se o complemento 'a' é diferente do elemento atual 'i' (para garantir
         * que, se sum = 10, e arr contiver apenas um '5', não contemos o 5 duas vezes).
         * 2. Verifica se o complemento 'a' já foi visto e está armazenado no HashSet.
         */
        if (a != i && memo.contains(a))
            return true; // Par encontrado.

        // Adiciona o elemento atual ao conjunto para futuras verificações.
        memo.add(i);
    }

    // Se o loop terminar sem encontrar um par, retorna false.
    return false;
}