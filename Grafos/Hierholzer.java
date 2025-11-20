    static ArrayList<Integer> path;
    public static boolean HeirHolzer(List<ArrayList<Integer>> list, int n, int m, int[] grau_e, int[] grau_s) {
        // 1. Verificação dos Graus (Assumindo 0-based indexing: 0 é início, n-1 é fim)
        if (grau_s[0] != grau_e[0] + 1) return false;
        if (grau_e[n - 1] != grau_s[n - 1] + 1) return false;
        for (int i = 1; i < n - 1; i++) {
            if (grau_s[i] != grau_e[i]) return false;
        }path = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        while (!stack.isEmpty()) {
            int u = stack.peek();
            // Se u tem vizinhos, avança
            if (!list.get(u).isEmpty()) {
                int indexLast = list.get(u).size() - 1;
                int v = list.get(u).get(indexLast);
                list.get(u).remove(indexLast);
                stack.push(v);
            } else {
                // Se não tem vizinhos, adiciona ao caminho e faz backtrack
                path.add(u);
                stack.pop();
            }
        }
        // 4. Verificação de Conectividade
        // Se o grafo for desconexo, o caminho será menor que o número de arestas + 1
        if (path.size() != m + 1) {
            return false;
        }
        Collections.reverse(path);
        return true;
    }




