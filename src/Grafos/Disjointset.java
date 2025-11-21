public static class DSU {
        private int[] parent, rank, tamanho;
        public DSU(int size) {
            rank = new int[size];
            parent = new int[size];
            for (int i = 0; i < size; i++) {
                parent[i] = i;
            }
        }

        public int find(int i) {
            int root = parent[i];
            if (parent[root] == root) return root;
            return parent[i] = find(root);
        }

        public void union(int i, int j) {
            int iRoot = find(i);
            int jRoot = find(j);
            if (jRoot == iRoot) return;
            if (rank[iRoot] < rank[jRoot]) {
                parent[iRoot] = jRoot;


            } else if (rank[iRoot] > rank[jRoot]) {
                parent[jRoot] = iRoot;


            } else {
                parent[iRoot] = jRoot;
                rank[jRoot]++;
            }

        }
    
