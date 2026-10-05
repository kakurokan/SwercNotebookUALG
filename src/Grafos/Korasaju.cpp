#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dag;
vector<int> in_degree;
vector<int> out_degree;

vector<vector<int>> graph, graphR;
vector<bool> visited;
vector<int> scc_id;
int scc_count;
vector<int> order;
vector<vector<int>> sccs;

void dfs(int start, vector<vector<int>> &list)
{
    visited[start] = true;
    for (int v : list[start])
    {
        if (!visited[v])
            dfs(v, list);
    }
    order.push_back(start);
}

void dfs1(int start, vector<vector<int>> &list)
{
    visited[start] = true;
    scc_id[start] = scc_count;
    sccs.back().push_back(start);
    for (int v : list[start])
    {
        if (!visited[v])
        {
            dfs1(v, list);
        }
    }
}

void kosaraju(int n)
{
    sccs.clear();
    scc_count = 0;
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i, graph);
    }
    visited.assign(n + 1, false);
    scc_id.assign(n + 1, 0);
    vector<int> conexos;
    for (int i = order.size() - 1; i >= 0; i--)
    {
        int u = order[i];
        if (!visited[u])
        {
            sccs.push_back({});
            dfs1(u, graphR);
            conexos.push_back(u);
            scc_count++;
        }
    }
}

void build_condensation_graph(int n)
{
    dag.assign(scc_count, vector<int>());
    in_degree.assign(scc_count, 0);
    out_degree.assign(scc_count, 0);


    set<pair<int, int>> edges;

    for (int u = 1; u <= n; u++)
    {
        for (int v : graph[u])
        {
            int id_u = scc_id[u];
            int id_v = scc_id[v];

            if (id_u != id_v && !edges.count({id_u, id_v}))
            {
                edges.insert({id_u, id_v});
                dag[id_u].push_back(id_v);
                out_degree[id_u]++;
                in_degree[id_v]++;
            }
        }
    }
}