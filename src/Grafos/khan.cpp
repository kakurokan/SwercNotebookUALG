#include <bits/stdc++.h>
using namespace std;

vector<int> order;
vector<vector<int>> graph;

void topoSortKhan()
{
    int n = graph.size()-1;
    vector<int> indegree(n+1,0);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        for (int next : graph[i])
        {
            indegree[next]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        order.push_back(top);
        for (int next : graph[top])
        {
            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }
    }
}