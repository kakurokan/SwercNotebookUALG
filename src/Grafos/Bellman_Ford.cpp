#include <bits/stdc++.h>
using namespace std;

vector<long long> dist;

bool Bellman_Ford(const vector<aresta>& list, int n) {
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (const aresta& atual : list) {
            int s = atual.s;
            int f = atual.f;
            long long w = atual.w;
            
            if (dist[s] != LLONG_MAX && dist[f] > dist[s] + w) {
                dist[f] = dist[s] + w;
                if (i == n - 1) {
                    flag = true;
                    break;
                }
            }
        }
    }
    return flag;
}