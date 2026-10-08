#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/*
 * Máximo divisor comum e mínimo múltiplo comum.
 */
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}
