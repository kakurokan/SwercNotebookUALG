#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(vector<vector<int>> &list)
{
    int size = list.size();
    vector<bool> visited(size, false);
    vector<int> path;
    queue<int> q;

    for (int i = 0; i < size; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            q.push(i);
            while (!q.empty())
            {
                int current = q.front();
                path.push_back(current);
                q.pop();
                for (int adj : list[current])
                {
                    if (!visited[adj])
                    {
                        visited[adj] = true;
                        q.push(adj);
                    }
                }
            }
        }
    }
    return path;
}