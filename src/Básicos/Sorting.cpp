#include <bits/stdc++.h>
using namespace std;

struct Tarefa {
    int prioridade, duracao, id;
};

// Ordena por maior prioridade; em caso de empate, menor duração
bool compara_tarefas(const Tarefa& a, const Tarefa& b) {
    if (a.prioridade != b.prioridade) {
        return a.prioridade > b.prioridade;
    }
    return a.duracao < b.duracao;
}

void ordenar_structs(vector<Tarefa>& tarefas) {
    // Aplicação do comparador para processamento ganancioso (Greedy)
    sort(tarefas.begin(), tarefas.end(), compara_tarefas);
}