/* ==============================================================================
 * Algoritmo: Algoritmo de Euclides Estendido (Extended GCD)
 * Descrição: Encontra x e y tais que A*x + B*y = gcd(A, B).
 * Retorna o Maior Divisor Comum (GCD) de A e B.
 * ==============================================================================
 */
#include <bits/stdc++.h>
using namespace std;

long long extGCD(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// Inverso modular universal (funciona mesmo se M não for primo, desde que
// gcd(A, M) == 1)
long long universalModInverse(long long a, long long m) {
    long long x, y;
    long long g = extGCD(a, m, x, y);
    if (g != 1) {
        return -1;  // Inverso não existe se A e M não forem coprimos
    }
    return (x % m + m) % m;
}