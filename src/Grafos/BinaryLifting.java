    static int n;
    static int nMax = 30;

    static int[][] build_up(int[] jumps) {
        int[][] up = new int[nMax][n];
        for (int i = 0; i < n; i++) {
            up[0][i] = jumps[i];
        }
        for (int i = 1; i < nMax; i++) {
            for (int j = 0; j < n; j++) {
                up[i][j] = up[i - 1][ up[i - 1][j] ];
            }
        }
        return up;
    }

    static int BinaryLifting(int current, int[][] up, int f) {

        for (int i = 0; i < nMax; i++) {
            if ((f & (1 << i)) != 0) {
                current = up[i][current];
            }
        }
        return current;

    }
