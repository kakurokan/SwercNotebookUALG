public static long kruskal(int n, long[][] arestas) {
        long cost = 0, count = 0;
        boolean possivel = false;
        Arrays.sort(arestas, Comparator.comparingLong(arr -> arr[2]));
        DSU dsu = new DSU(n);
        for (long[] aresta : arestas) {
            int s = (int) aresta[0];
            int f = (int) aresta[1];
            long w = aresta[2];
            if (dsu.find(s) != dsu.find(f)) {
                dsu.union(s, f);
                cost += w;
                if (++count == n - 1) {
                    possivel = true;
                    break;
                }
            }
        }
        if (possivel) return cost;
        return -1;
    }
