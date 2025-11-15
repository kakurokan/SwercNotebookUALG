    static boolean[] na_chamada;
    static int inicio = -1;
    static int fim=-1;
    static boolean visited[];
    static int origem[];

    static void dfs(int current, List<List<Integer>> list) {
        visited[current] = true;
        na_chamada[current] = true;
        for (int adj : list.get(current)) {
            if (!visited[adj]) {
                origem[adj] = current;
                dfs(adj, list);
                if (inicio != -1) break;

            } else if (na_chamada[adj]) {
                inicio = adj;
                fim = adj;
                return;
            }
        }
        na_chamada[current] = false;
    }
