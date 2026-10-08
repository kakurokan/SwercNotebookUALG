# SwercNotebookUALG

Notebook da equipe UALGException, reunindo implementações de algoritmos, estruturas de dados e técnicas frequentes em programação competitiva e resolução de problemas.

## Sobre o projeto

Este repositório serve como uma coleção de referências rápidas para:

- algoritmos de grafos;
- estruturas de dados clássicas;
- programação dinâmica;
- técnicas de sliding window e range query;
- utilitários matemáticos;
- soluções básicas em Java e C++.

O objetivo é centralizar exemplos prontos para consulta, estudo e reutilização durante competições e desafios de algoritmos.

## Estrutura do repositório

```text
.
├── .vscode/
│   └── c_cpp_properties.json
├── src/
│   ├── Básicos/
│   │   ├── CheckTimes.java
│   │   ├── Occorrences.java
│   │   ├── TransporMatriz.java
│   │   ├── TwoSum.java
│   │   └── Unique.java
│   │
│   ├── Grafos/
│   │   ├── BFS.cpp
│   │   ├── Bellman_Ford.cpp
│   │   ├── BinaryLifting.cpp
│   │   ├── DFS.cpp
│   │   ├── DFS_ciclos.cpp
│   │   ├── Dijkstra.cpp
│   │   ├── Disjointset.cpp
│   │   ├── Edmonds-Karp.cpp
│   │   ├── Floyd-Warshall.java
│   │   ├── Hierholzer.java
│   │   ├── Korasaju.cpp
│   │   ├── Kruskal.java
│   │   ├── Reader.java
│   │   ├── TWO_SAT.cpp
│   │   └── khan.java
│   │
│   ├── Math/
│   │   └── MathUtils.java
│   │
│   ├── ProgramacaoDinamica/
│   │   ├── ArrayDescription.cpp
│   │   ├── BookShop.cpp
│   │   ├── CoinsCombinations2.cpp
│   │   ├── CountingTowers.cpp
│   │   ├── EditDistance.cpp
│   │   ├── LongestCommomSubsequence.cpp
│   │   ├── MinimalGridPath.cpp
│   │   ├── MinimizingCoins.cpp
│   │   ├── RemovalGames.cpp
│   │   └── template.cpp
│   │
│   ├── RangeQuery/
│   │   ├── BinaryIndexedTree.java
│   │   ├── LazySegTree.java
│   │   └── RangeMinimum.java
│   │
│   ├── SlidingWindow/
│   │   ├── Generic.java
│   │   └── Minimum.java
│   └── ...
├── README.md
└── LICENSE
```

## Conteúdo por categoria

### Básicos
Arquivos para operações simples e fundamentos de algoritmos, como:

- análise de tempo;
- contagem de ocorrências;
- transposição de matrizes;
- dois somas;
- exclusão de elementos duplicados.

### Grafos
Implementações de algoritmos clássicos para grafos, incluindo:

- BFS e DFS;
- Dijkstra;
- Bellman-Ford;
- Kruskal;
- Binary Lifting;
- Ordenação topológica (Kahn);
- SCC (Kosaraju);
- Fluxo máximo (Edmonds-Karp);
- Union-Find;
- Eulerian path (Hierholzer);
- 2-SAT.

### Programação dinâmica
Soluções para problemas de DP, como:

- Edits distance;
- Longest Common Subsequence;
- Minimizing Coins;
- Counting Towers;
- Book Shop;
- Removal Games;
- Minimal Grid Path.

### Range Query
Estruturas para consultas em intervalos:

- Fenwick Tree (Binary Indexed Tree);
- Segment Tree com lazy propagation;
- Range minimum query.

### Sliding Window
Implementações de janelas deslizantes para resolução eficiente de problemas de subarray:

- mínimo em janela;
- forma genérica para problemas desse tipo.

### Math
Utilitários matemáticos para suporte em operações e manipulação numérica.

## Linguagens

O repositório contém exemplos em:

- C++
- Java

## Como usar

### C++
```bash
g++ src/Grafos/BFS.cpp -o bfs
./bfs
```

### Java
```bash
javac src/RangeQuery/BinaryIndexedTree.java
java BinaryIndexedTree
```

> Os comandos podem variar conforme a classe ou arquivo selecionado. Em alguns casos, a estrutura do programa pode exigir adaptação do ponto de entrada.

## Objetivo

Este notebook foi montado para servir como base de estudo e consulta rápida, especialmente em problemas de algoritmos e estruturas de dados, com foco em soluções bem organizadas e reutilizáveis.

## Contribuição

Contribuições são bem-vindas. Se você quiser adicionar novos algoritmos, melhorar documentação ou padronizar implementações, sinta-se à vontade para abrir um pull request.

## Equipe

- UALGException

## Licença

Confira a licença do repositório para mais detalhes.
