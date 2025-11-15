static void Dijkstra(List<List<long[]>> list) {
        dist = new long[list.size()];
        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(x -> x[0]));
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0;
        pq.offer(new long[]{0, 0});
        while (!pq.isEmpty()) {
            long[] atual = pq.poll();
            int v = (int) atual[1];
            long w = atual[0];
            if (w > dist[v]) {
                continue;
            }
            for (long[] adj : list.get(v)) {
                int v_adj = (int) adj[1];
                long w_adj = adj[0];
                if (dist[v_adj] > dist[v] + w_adj) {
                    dist[v_adj] = dist[v] + w_adj;
                    pq.offer(new long[]{dist[v_adj], v_adj});
                }
            }
        }
    }
