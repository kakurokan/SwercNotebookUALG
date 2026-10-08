/* ==============================================================================
 * Algoritmo: Trie (Prefix Tree) baseada em vetor estático
 * Complexidade: O(L) por inserção/pesquisa (L = tamanho da palavra)
 * Descrição: Evita a sobrecarga de alocação dinâmica. Facilmente adaptável
 * para uma Xor-Trie em problemas matemáticos manipulando bits (0 e 1).
 * ==============================================================================
 */
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    int next[26];
    bool is_end;
    TrieNode() {
        fill(begin(next), end(next), -1);
        is_end = false;
    }
};

vector<TrieNode> trie(1);  // O nó 0 é sempre a raiz

void insert_string(const string& s) {
    int node = 0;
    for (char c : s) {
        int idx = c - 'a';  // Assumindo apenas minúsculas
        if (trie[node].next[idx] == -1) {
            trie[node].next[idx] = trie.size();
            trie.emplace_back();  // Cria um novo nó
        }
        node = trie[node].next[idx];
    }
    trie[node].is_end = true;
}

bool search_string(const string& s) {
    int node = 0;
    for (char c : s) {
        int idx = c - 'a';
        if (trie[node].next[idx] == -1) return false;
        node = trie[node].next[idx];
    }
    return trie[node].is_end;
}