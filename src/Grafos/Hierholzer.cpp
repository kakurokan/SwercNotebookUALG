#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> graph;
int n, m;
vector<int> degree;
vector<int> circuit;

// Para grafos direcionados deve usar in_degree e out_degree.
// Os valores no indice i devem ser iguais.
//
void Heirholzer()
{
    cin >> n >> m;
    graph.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back({b, i});
        graph[b].push_back({a, i});
        degree[a]++;
        degree[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] % 2 != 0)
        {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    vector<int> currPath;
    currPath.push_back(1);
    vector<bool> visited(m, false);

    while (currPath.size() > 0)
    {
        int currNode = currPath[currPath.size() - 1];
        bool edge_found = false;
        while (!graph[currNode].empty())
        {
            auto [nextNode, edge_idx] = graph[currNode].back();
            graph[currNode].pop_back();

            if (!visited[edge_idx])
            {
                visited[edge_idx] = true;
                currPath.push_back(nextNode);
                edge_found = true;
                break;
            }
        }
        if (!edge_found)
        {
            circuit.push_back(currNode);
            currPath.pop_back();
        }
    }
    if (circuit.size() != m + 1)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    reverse(circuit.begin(), circuit.end());
}