# SwercNotebookUALG

Notebook da equipe UALGException.

Este repositório reúne exemplos, algoritmos e estruturas de dados em C++ para estudo, consulta rápida e utilização em competições e desafios de programação.

## Sobre o projeto

O objetivo do projeto é centralizar implementações clássicas e úteis de:

- grafos;
- programação dinâmica;
- estruturas de dados;
- consultas em intervalos;
- janelas deslizantes;
- matemática e utilitários;
- técnicas comuns em programação competitiva.

## Estrutura do repositório

```text
.
├── .vscode/
│   └── c_cpp_properties.json
├── src/
│   ├── Básicos/
│   ├── Grafos/
│   ├── Math/
│   ├── ProgramacaoDinamica/
│   ├── RangeQuery/
│   ├── SlidingWindow/
│   └── ...
├── README.md
├── LICENSE
└── .gitignore
```

## Conteúdo por categoria

### Básicos
Arquivos com fundamentos e operações simples, como:

- contagem de ocorrências;
- manipulação de matrizes;
- busca e análise de arrays;
- exemplos introdutórios.

### Grafos
Implementações de algoritmos clássicos, incluindo:

- BFS;
- DFS;
- Dijkstra;
- Bellman-Ford;
- Kruskal;
- Binary Lifting;
- ordenação topológica (Kahn);
- SCC (Kosaraju);
- fluxo máximo (Edmonds-Karp);
- Union-Find;
- Eulerian path (Hierholzer);
- 2-SAT.

### Programação dinâmica
Soluções para problemas de otimização e recorrência, como:

- Edit Distance;
- Longest Common Subsequence;
- Minimizing Coins;
- Counting Towers;
- Book Shop;
- Removal Games;
- Minimal Grid Path.

### Range Query
Estruturas de dados para consultas em intervalos:

- Fenwick Tree (Binary Indexed Tree);
- Segment Tree com lazy propagation;
- Range minimum query.

### Sliding Window
Implementações de janelas deslizantes para soluções eficientes em subarrays.

### Math
Utilitários matemáticos e funções de apoio para manipulação numérica.

## Linguagem principal

O repositório é majoritariamente desenvolvido em C++.

## Requisitos

- compilador C++ (g++ ou clang++);
- suporte a C++11 ou superior;
- opcionalmente, um ambiente com `make`.

## Como compilar

Exemplo básico para compilar um arquivo C++:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -o programa arquivo.cpp
./programa
```

Exemplo para compilar um arquivo de grafos:

```bash
g++ -std=c++17 -O2 -Wall -Wextra src/Grafos/BFS.cpp -o bfs
./bfs
```

## Como usar

Cada arquivo pode ser compilado isoladamente conforme a necessidade do problema ou algoritmo. Em muitos casos, o código foi organizado para facilitar leitura e reutilização em outros projetos.

## Objetivo

Este notebook foi montado para servir como base de estudo e consulta rápida em algoritmos, estruturas de dados e técnicas frequentemente usadas em programação competitiva.

## Contribuição

Contribuições são bem-vindas. Se você quiser adicionar novos algoritmos, melhorar a documentação ou ajustar implementações, sinta-se à vontade para abrir um pull request ou sugerir melhorias.

## Equipe

- UALGException

## Licença

Consulte o arquivo `LICENSE` no repositório para mais detalhes.
