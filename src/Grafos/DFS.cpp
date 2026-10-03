#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<int> path;
void DFS(int current, vector<vector<int>> list) {
    visited[current] = true;
    path.push_back(current);
    for(int adj: list[current]) {
        if(!visited[adj]) {
            DFS(adj,list);
        }
    }
}