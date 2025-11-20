    public class DistinctRoutesTemplate {
        static class DistinctRoutesSolver {
            int n;
            int[][] capacity;
            List<List<Integer>> graphResidual; // Para o BFS (fluxo)
            List<List<Integer>> graphOriginal; // Para reconstruir o caminho
            int maxFlowValue;

            public DistinctRoutesSolver(int n) {
                this.n = n;
                this.capacity = new int[n][n];
                this.graphResidual = new ArrayList<>();
                this.graphOriginal = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    graphResidual.add(new ArrayList<>());
                    graphOriginal.add(new ArrayList<>());
                }
            }

            public void addEdge(int u, int v) {
                // Grafo Residual (Bidirecional para o algoritmo poder "desfazer" fluxo)
                graphResidual.get(u).add(v);
                graphResidual.get(v).add(u);
                // Grafo Original (Unidirecional para saber por onde realmente podemos passar)
                graphOriginal.get(u).add(v);
                capacity[u][v]++;
            }

            // Passo 1: Calcular o Fluxo Máximo (Edmonds-Karp)
            public int computeMaxFlow(int s, int t) {
                maxFlowValue = 0;
                int[] parent = new int[n];
                while (true) {
                    Arrays.fill(parent, -1);
                    Queue<Integer> q = new LinkedList<>();
                    q.offer(s);
                    parent[s] = -2;

                    while (!q.isEmpty()) {
                        int curr = q.poll();
                        if (curr == t) break;

                        for (int next : graphResidual.get(curr)) {
                            if (parent[next] == -1 && capacity[curr][next] > 0) {
                                parent[next] = curr;
                                q.offer(next);
                            }
                        }
                    }
                    if (parent[t] == -1) break; // Não há mais caminhos
                    maxFlowValue++;
                    int curr = t;
                    while (curr != s) {
                        int prev = parent[curr];
                        capacity[prev][curr]--; // Gasta a ida
                        capacity[curr][prev]++; // Cria a volta (residual)
                        curr = prev;
                    }
                }
                return maxFlowValue;
            }

            // Passo 2: Recuperar os caminhos individuais
            public List<List<Integer>> getPaths(int s, int t) {
                List<List<Integer>> paths = new ArrayList<>();
                for (int i = 0; i < maxFlowValue; i++) {
                    List<Integer> path = new ArrayList<>();
                    int curr = s;
                    path.add(curr);
                    while (curr != t) {
                        for (int next : graphOriginal.get(curr)) {
                            // Se cap ida é 0 e cap volta >= 1, o fluxo passou aqui
                            if (capacity[curr][next] == 0 && capacity[next][curr] >= 1) {
                                path.add(next);
                                // Removemos este fluxo específico para não o repetir
                                capacity[next][curr]--; // Remove residual
                                capacity[curr][next]++; // Restaura original
                                curr = next;
                                break;
                            }
                        }
                    }
                    paths.add(path);
                }
                return paths;
            }
        }
    }
