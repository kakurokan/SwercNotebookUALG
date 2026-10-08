#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1'000'000'007LL;
using Matrix = vector<vector<ll>>;

/*
 * Multiplicação de matrizes em O(n^3).
 */
Matrix multiply(const Matrix& A, const Matrix& B) {
    int rA = (int)A.size();
    int cA = (int)A[0].size();
    int cB = (int)B[0].size();

    Matrix C(rA, vector<ll>(cB, 0));
    for (int i = 0; i < rA; i++) {
        for (int k = 0; k < cA; k++) {
            for (int j = 0; j < cB; j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

/*
 * Exponenciação de matrizes - O(M^3 log P)
 */
Matrix matrixPower(Matrix A, ll p) {
    int n = (int)A.size();
    Matrix res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1;

    while (p > 0) {
        if (p & 1) res = multiply(res, A);
        A = multiply(A, A);
        p >>= 1;
    }
    return res;
}
