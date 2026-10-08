/* ==============================================================================
 * Template: Estrutura Base para Competições
 * Descrição: Otimização de I/O, macros essenciais e constantes comuns.
 * ==============================================================================
 */
#include <bits/stdc++.h>
using namespace std;

// Atalhos de tipos para poupar teclado (essencial em DP)
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;

// Macros úteis para manter o código limpo
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

// Constantes comuns
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

void solve() {
    // Lógica do problema aqui
    int n;
    if (!(cin >> n)) return;
}

int main() {
    // Otimização crucial de Input/Output (Evita Time Limit Exceeded)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t; // Descomentar se houver múltiplos test cases

    while (t--) {
        solve();
    }
    return 0;
}