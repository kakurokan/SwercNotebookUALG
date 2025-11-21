
  static long[] dist;
    static boolean Bellman_Ford(List<long[]> list,int n) {
        boolean flag = false;
        for (int i = 0; i < n; i++) {
            for (long[] atual : list) {
                int o = (int) atual[0];
                int f = (int) atual[1];
                long w = atual[2];
                if (dist[o] != Long.MAX_VALUE && dist[f] > dist[o] + w) {
                    dist[f] = dist[o] + w;
                    if (i == n-1) {
                        flag = true;
                        break;
                    }

                }
            }
        }
        return flag;
    }
