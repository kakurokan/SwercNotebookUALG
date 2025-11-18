public static int checkTimes(int[] arr, double times) {
    // memo: Usa um HashMap para mapear cada elemento ao seu número de ocorrências (frequência).
    HashMap<Integer, Integer> memo = new HashMap<>();

    // Itera sobre cada elemento do array.
    for (int i : arr) {
        // Obtém a contagem atual de 'i', incrementa em 1. Se 'i' for novo, começa com 1.
        int t = memo.getOrDefault(i, 0) + 1;

        // Condição: Verifica se a nova contagem 't' excedeu o limite 'times'.
        if (t > times)
            return i; // Retorna o elemento que excedeu o limite.

        // Atualiza a contagem de 'i' no HashMap.
        memo.put(i, t);
    }

    // Se o loop terminar sem que nenhum elemento exceda o limite, retorna -1.
    return -1;
}