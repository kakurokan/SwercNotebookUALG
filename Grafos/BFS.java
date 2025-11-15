    public static ArrayList<Integer> BFS(List<List<Integer>> list) {
        int size = list.size();
        boolean[] visited = new boolean[size];
        ArrayList<Integer> path = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                visited[i] = true;
                q.add(i);
                while (!q.isEmpty()) {
                    int current = q.poll();
                    path.add(current);
                    for (int adj : list.get(current)) {
                        if (!visited[adj]) {
                            visited[adj] = true;
                            q.offer(adj);

                        }
                    }
                }
            }
        }
        return path;
    }
