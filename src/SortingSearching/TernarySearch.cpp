/* 
 * Algoritmo: Ternary Search
 * Complexidade: O(log N)
 * Descrição: Encontra o mínimo de uma função unimodal no intervalo [left,
 * right].
 */
#include <bits/stdc++.h>
using namespace std;

// A função a ser minimizada (tem de ser estritamente decrescente e depois
// crescente)
double f(double x) {
    // Exemplo: calcular o custo para um determinado x
    return x * x;
}

double ternary_search(double left, double right) {
    // Para inteiros, a condição de paragem é (right - left > 2)
    // Para doubles, fazemos um número fixo de iterações (ex: 100 ou 200)
    for (int i = 0; i < 200; i++) {
        double m1 = left + (right - left) / 3.0;
        double m2 = right - (right - left) / 3.0;

        if (f(m1) < f(m2)) {
            right = m2;  // O mínimo não pode estar à direita de m2
        } else {
            left = m1;  // O mínimo não pode estar à esquerda de m1
        }
    }
    return f(left);  // left e right convergiram para o mínimo
}