#include <bits/stdc++.h>
using namespace std;
struct aresta
{
    int v;
    long long w;
};
struct CompareAresta
{
    bool operator()(aresta &a, aresta &b)
    {
        return a.w > b.w;
    }
};
vector<long long> dist;
void Dijkstra(vector<vector<aresta>> list, int start)
{
    dist.assign(list.size(), LLONG_MAX);
    priority_queue<aresta, vector<aresta>, CompareAresta> pq;
    dist[start] = 0;
    pq.push({start, 0});
    while (!pq.empty())
    {
        aresta atual = pq.top();
        pq.pop();
        int v = atual.v;
        long long w = atual.w;
        if (w > dist[v])
            continue;
        for (aresta adj : list[v])
        {
            int vadj = adj.v;
            long long wadj = adj.w;
            if (dist[vadj] > dist[v] + wadj)
            {
                dist[vadj] = dist[v] + wadj;
                pq.push({vadj, dist[vadj]});
            }
        }
    }
}
