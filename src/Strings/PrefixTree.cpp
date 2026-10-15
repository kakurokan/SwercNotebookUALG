/* 
 * Algoritmo: Trie (Prefix Tree) baseada em vetor estatico
 * Complexidade: O(L) por insercao/pesquisa (L = tamanho da palavra)
 * Descricao: Evita a sobrecarga de alocacao dinamica. Facilmente adaptavel
 * para uma Xor-Trie em problemas matematicos manipulando bits (0 e 1).
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

vector<TrieNode> trie(1);  // O no 0 e sempre a raiz

void insert_string(const string& s) {
    int node = 0;
    for (char c : s) {
        int idx = c - 'a';  // Assumindo apenas minusculas
        if (trie[node].next[idx] == -1) {
            trie[node].next[idx] = trie.size();
            trie.emplace_back();  // Cria um novo no
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
