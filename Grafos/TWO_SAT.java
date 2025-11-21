    // Arrays globais para armazenar estado da DFS e resultados
    static boolean[] visited;
    static int[] scc_id; // Armazena o ID do componente conexo de cada nó
    static int scc_count; // Contador de componentes
    static char[] result; // Resultado final ('+' ou '-')
    // A tua lógica principal ('two_sat') usa uma versão ITERATIVA (com pilha) que é muito melhor
    // para evitar StackOverflow em Java. Vou comentar brevemente aqui.
    public static void dfs(int start, List<List<Integer>> list, Stack<Integer> stack) {
        visited[start] = true;
        for (int v : list.get(start)) {
            if (!visited[v]) {
                dfs(v, list, stack);
            }
        }
        stack.push(start); // Post-order: empilha ao terminar
    }
    public static void dfs1(int start, List<List<Integer>> list) {
        visited[start] = true;
        scc_id[start] = scc_count;
        for (int v : list.get(start)) {
            if (!visited[v]) {
                dfs1(v, list);
            }
        }
    }
    // Transforma input do problema em índices de array (0 a 2m-1)
    // Variável +x vira índice (x-1)
    // Variável -x vira índice (x-1) + m
    private static int node(char sign, int val, int m) { 
        if (sign == '+') {
            return val - 1; 
        } else {
            return (val - 1) + m; 
        }
    }
    // Encontra o índice da negação de um nó
    // Se recebo x, devolvo -x. Se recebo -x, devolvo x.
    private static int neg(int node_idx, int m) {
        if (node_idx < m) {
            return node_idx + m; // Negação de +x é -x (lado direito do array)
        } else {
            return node_idx - m; // Negação de -x é +x (lado esquerdo do array)
        }
    }
    // Constrói o Grafo de Implicação
    // Lê o input, converte para nós e cria arestas A->B e arestas reversas B->A
    // Nota: Assume que existe um objeto 'fs' (FastScanner) acessível globalmente (cuidado ao compilar)
    public void cria_listas(List<List<Integer>> list, List<List<Integer>> list_inv) {
        // Leitura do par de desejos
        char pr = fs.nextChar(); int a = fs.nextInt();
        char se = fs.nextChar(); int b = fs.nextInt();
        // Converte para nós do grafo
        int u = node(pr, a, m);
        int u2 = node(se, b, m);
        // Pega as negações lógicas
        int negu = neg(u, m);
        int negu2 = neg(u2, m);
        // Lógica 2-SAT: Cláusula (A ou B) equivale a:
        // 1. Se NÃO A -> então B (negu -> u2)
        // 2. Se NÃO B -> então A (negu2 -> u)
        list.get(negu).add(u2);
        list.get(negu2).add(u);
        // Constrói o Grafo Inverso (Transposto) necessário para o Kosaraju
        list_inv.get(u2).add(negu);
        list_inv.get(u).add(negu2);
    }

    // --- O CORAÇÃO DO ALGORITMO (KOSARAJU ITERATIVO) ---
    public boolean two_sat(List<List<Integer>> list, List<List<Integer>> list_inv, int m, int n) {
        visited = new boolean[m * 2];
        scc_count = 0;
        scc_id = new int[m * 2];
        Stack<Integer> stack = new Stack<>(); // Esta será a pilha com a ordem topológica final

        // --- PASSO 1: DFS Iterativo (Simulação de Post-Order) ---
        // Objetivo: Preencher 'stack' com nós ordenados pelo tempo de término.
        Stack<Integer> exploration_stack = new Stack<>(); 
        
        for (int i = 0; i < 2 * m; i++) {
            if (!visited[i]) {
                exploration_stack.push(i); // Começa a explorar 'i'

                while (!exploration_stack.isEmpty()) {
                    int u = exploration_stack.pop();

                    // --- O TRUQUE DE MESTRE (BITWISE NOT) ---
                    // Se o nó é negativo (u < 0), significa que ele é o marcador que
                    // nós mesmos colocamos na pilha anteriormente usando '~u'.
                    // Isso sinaliza que "já visitamos todos os filhos deste nó, agora estamos voltando".
                    if (u < 0) {
                        stack.push(~u); // ~u inverte os bits de volta ao original positivo
                        continue;       // Processou o retorno, vai para o próximo
                    }
                    
                    // Se já visitou (e não é marcador de retorno), ignora
                    if (visited[u]) continue;
                    visited[u] = true;
                    
                    // 1. Empilha o "marcador de retorno" (~u)
                    // Como é uma pilha (LIFO), este marcador só sairá DEPOIS de todos os filhos.
                    exploration_stack.push(~u);
                    
                    // 2. Empilha os filhos para serem processados agora
                    for (int v : list.get(u)) {
                        if (!visited[v]) {
                            exploration_stack.push(v);
                        }
                    }
                }
            }
        }
        
        // --- PASSO 2: Encontrar SCCs no Grafo Transposto ---
        // Agora usamos a 'stack' preenchida acima.
        // Como processamos do último terminado para o primeiro, estamos seguindo a ordem topológica inversa.
        
        for (int i = 0; i < 2 * m; i++) {
            visited[i] = false; // Reseta visited para reusar
        }

        Stack<Integer> scc_stack = new Stack<>(); // Pilha auxiliar para DFS simples
        while (!stack.isEmpty()) {
            int i = stack.pop(); // Pega o nó com maior tempo de término
            if (!visited[i]) {
                // Se ainda não visitado, encontrou um novo Componente Fortemente Conexo (SCC)
                scc_stack.push(i);
                while (!scc_stack.isEmpty()) {
                    int u = scc_stack.pop();
                    if (visited[u]) continue;
                    visited[u] = true;
                    scc_id[u] = scc_count; // Marca todos neste grupo com o mesmo ID
                    // Importante: Aqui navegamos no grafo INVERTIDO (list_inv)
                    for (int v : list_inv.get(u)) {
                        if (!visited[v]) {
                            scc_stack.push(v);
                        }
                    }
                }
                scc_count++; // Fecha o componente atual e prepara ID para o próximo
            }
        }
        // --- PASSO 3: Verificação e Atribuição de Verdade ---
        result = new char[m];
        for (int i = 0; i < m; i++) {
            int node_atual = i;       // Representa +x
            int node_neg = i + m;     // Representa -x   
            // 1. Verificação de Impossibilidade
            // Se x e -x estão no mesmo SCC, temos uma contradição lógica (x <-> -x)
            if (scc_id[node_atual] == scc_id[node_neg]) {
                return false;
            }
            // 2. Atribuição de Valores
            // No algoritmo de Kosaraju:
            // IDs maiores de SCC aparecem "antes" topologicamente (são Fontes/Sources).
            // IDs menores aparecem "depois" (são Sorvedouros/Sinks).
            // Regra 2-SAT: Se A -> B, queremos escolher B (para não quebrar implicação).
            // Ou seja, escolhemos o componente que está "mais à frente" topologicamente (SINK).
            // Lógica usada aqui:
            // Se id[+x] > id[-x], então +x vem ANTES de -x (Implicação: +x -> -x).
            // Se +x implica -x, então +x DEVE ser Falso.
            if (scc_id[node_atual] > scc_id[node_neg]) {
                result[i] = '+';
            } else {
                result[i] = '-';
            }
        }
        return true;
    }
}
