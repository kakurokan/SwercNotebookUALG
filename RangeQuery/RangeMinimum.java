  // Fills lookup array lookup[][] in bottom up manner.
    public static int[][] buildSparseTable(int[] arr) {
        int n = arr.length;

        // create the 2d table
        int[][] lookup = new int[n + 1][(int)(Math.log(n) / Math.log(2)) + 1];

        // Initialize for the intervals with length 1
        for (int i = 0; i < n; i++)
            lookup[i][0] = arr[i];

        // Compute values from smaller to bigger intervals
        for (int j = 1; (1 << j) <= n; j++) {

            // Compute minimum value for all intervals with
            // size 2^j
            for (int i = 0; (i + (1 << j) - 1) < n; i++) {

                if (lookup[i][j - 1] <
                        lookup[i + (1 << (j - 1))][j - 1])
                    lookup[i][j] = lookup[i][j - 1];
                else
                    lookup[i][j] =
                            lookup[i + (1 << (j - 1))][j - 1];
            }
        }

        return lookup;
    }

    // Returns minimum of arr[L..R]
    public static int query(int L, int R, int[][] lookup) {

        // Find highest power of 2 that is smaller
        // than or equal to count of elements in range
        int j = (int)(Math.log(R - L + 1) / Math.log(2));

        // Compute minimum of last 2^j elements with first
        // 2^j elements in range.
        if (lookup[L][j] <= lookup[R - (1 << j) + 1][j])
            return lookup[L][j];
        else
            return lookup[R - (1 << j) + 1][j];
    }

    public static int[] solveQueries(int[] arr, int[][] queries) {
        int n = arr.length;
        int m = queries.length;
        int[] result = new int[m];

        // Build the sparse table
        int[][] lookup = buildSparseTable(arr);

        // Process each query
        for (int i = 0; i < m; i++) {
            int L = queries[i][0];
            int R = queries[i][1];
            result[i] = query(L, R, lookup);
        }

        return result;
    }
