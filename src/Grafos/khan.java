    static ArrayList<Integer> topoSortkhan(List<List<Integer>> list) {
        int n = list.size();
        int[] indegree = new int[n];
        Queue<Integer> q = new LinkedList<>();
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int next : list.get(i)) {
                indegree[next]++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.add(i);
            }
        }
        while (!q.isEmpty()) {
            int top = q.poll();
            result.add(top);
            for (int next : list.get(top)) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.add(next);
                }
            }
        }
        return result;
    }
