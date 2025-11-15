    static void Warshall(long[][] matriz,int n) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matriz[i][k] != Long.MAX_VALUE && matriz[k][j] != Long.MAX_VALUE) {
                        matriz[i][j] = Math.min(matriz[i][j], matriz[i][k] + matriz[k][j]);
                    }
                }
            }
        }
    }
