#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> graph;
//graph[i][i] =0
void Warshall(int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][k] != LLONG_MAX && graph[k][j] != LLONG_MAX)
                {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}
