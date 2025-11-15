    static boolean[] visited;
    static ArrayList<Integer> travessia;
    public static void DFS(int current,List<List<Integer>> list){
        visited[current]=true;
        travessia.add(current);
        for(int adj:list.get(current)){
            if (!visited[adj]){
                DFS(adj,list);
            }
        }
    }
