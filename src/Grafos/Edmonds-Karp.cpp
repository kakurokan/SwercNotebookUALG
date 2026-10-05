#include <bits/stdc++.h>
using namespace std;

class DistinctRoutesSolver
{
public:
    int n;
    vector<vector<int>> capacity;
    vector<vector<int>> graphResidual; // Para fluxo BFS
    vector<vector<int>> graphOriginal; // Para reconstruir o caminho
    int maxFlowValue;

    DistinctRoutesSolver(int size)
    {
        n = size;
        capacity.assign(n, vector<int>(n, 0)); 
        graphResidual.resize(n);
        graphOriginal.resize(n);
        maxFlowValue = 0;
    }

    void addEdge(int u, int v) {
        graphResidual[u].push_back(v);
        graphResidual[v].push_back(u);
        graphOriginal[u].push_back(v);
        capacity[u][v]++;
    }

    int computeMaxFlow(int s, int t) {
        maxFlowValue = 0; 
        while (true) {
            vector<int> parent(n, -1);
            queue<int> q;
            q.push(s);
            parent[s] = -2;
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                if (curr == t) break;

                for (int next : graphResidual[curr]) {
                    if (parent[next] == -1 && capacity[curr][next] > 0) {
                        parent[next] = curr;
                        q.push(next);
                    }
                }
            }
            
            if (parent[t] == -1) break; // Não há mais caminhos
            maxFlowValue++;
            int curr = t;

            while (curr != s) {
                int prev = parent[curr];
                capacity[prev][curr]--;
                capacity[curr][prev]++;
                curr = prev;
            }
        }
        return maxFlowValue;
    }

    vector<vector<int>> getPaths(int s, int t) {
        vector<vector<int>> paths;
        for (int i = 0; i < maxFlowValue; i++) {
            vector<int> path;
            int curr = s;
            path.push_back(s);
            while (curr != t) {
                bool moved = false;
                for (int next : graphOriginal[curr]) {
                    if (capacity[curr][next] == 0 && capacity[next][curr] >= 1) {
                        path.push_back(next);
                        capacity[next][curr]--;
                        capacity[curr][next]++;
                        curr = next;
                        moved = true;
                        break;
                    }
                }
                if (!moved) break; 
            }
            paths.push_back(path);
        }
        return paths; 
    }
};