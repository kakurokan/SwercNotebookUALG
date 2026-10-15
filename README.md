# SwercNotebookUALG

Notebook of the UALGException team.

This repository contains examples, algorithms, and data structures in C++ for studying, quick consultation, and use in programming contests and algorithm challenges.

## About the project

The goal of this project is to centralize useful and classic implementations of:

- graphs;
- dynamic programming;
- data structures;
- range queries;
- sliding window techniques;
- mathematics and utilities;
- common competitive programming strategies.

## Repository structure

```text
.
├── .vscode/
│   └── c_cpp_properties.json
├── src/
│   ├── Basics/
│   ├── Graphs/
│   ├── Math/
│   ├── DynamicProgramming/
│   ├── RangeQuery/
│   ├── SlidingWindow/
│   └── ...
├── README.md
├── LICENSE
└── .gitignore
```

## Content by category

### Basics
Files with fundamentals and simple operations, such as:

- counting occurrences;
- matrix manipulation;
- array analysis;
- introductory examples.

### Graphs
Implementations of classic graph algorithms, including:

- BFS;
- DFS;
- Dijkstra;
- Bellman-Ford;
- Kruskal;
- Binary Lifting;
- topological sorting (Kahn);
- SCC (Kosaraju);
- maximum flow (Edmonds-Karp);
- Union-Find;
- Eulerian path (Hierholzer);
- 2-SAT.

### Dynamic Programming
Solutions for optimization and recurrence problems, such as:

- Edit Distance;
- Longest Common Subsequence;
- Minimizing Coins;
- Counting Towers;
- Book Shop;
- Removal Games;
- Minimal Grid Path.

### Range Query
Data structures for interval queries:

- Fenwick Tree (Binary Indexed Tree);
- Segment Tree with lazy propagation;
- Range minimum query.

### Sliding Window
Implementations of sliding-window techniques for efficient subarray solutions.

### Math
Mathematical utilities and helper functions for numerical manipulation.

## Main language

The repository is primarily developed in C++.

## Requirements

- a C++ compiler (g++ or clang++);
- C++11 or newer support;
- optionally, a `make` environment.

## How to compile

Basic example to compile a C++ file:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -o program file.cpp
./program
```

Example for compiling a graph file:

```bash
g++ -std=c++17 -O2 -Wall -Wextra src/Graphs/BFS.cpp -o bfs
./bfs
```

## How to use

Each file can be compiled individually depending on the specific problem or algorithm. In many cases, the code is organized to make reading and reuse easier in other projects.

## Goal

This notebook was created to serve as a quick study and reference base for algorithms, data structures, and techniques commonly used in competitive programming.

## Contribution

Contributions are welcome. If you want to add new algorithms, improve documentation, or adjust implementations, feel free to open a pull request or suggest improvements.

## Team

- UALGException

## License

Please check the `LICENSE` file in the repository for more details.
