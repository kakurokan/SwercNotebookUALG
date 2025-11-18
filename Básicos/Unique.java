public static boolean unique(int[] arr) {
    // memo: Usa um HashSet para rastrear a presença de cada elemento.
    HashSet<Integer> memo = new HashSet<>();

    // Itera sobre cada elemento do array.
    for (int i : arr) {
        // Se o elemento 'i' já estiver no HashSet, encontramos uma duplicata.
        if (memo.contains(i))
            return false; // Duplicata encontrada, array não é único.

        // Adiciona o elemento ao conjunto.
        memo.add(i);
    }

    // Se o loop terminar sem encontrar duplicatas, o array é único.
    return true;
}