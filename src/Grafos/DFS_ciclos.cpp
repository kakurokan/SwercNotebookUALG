#include <bits/stdc++.h>
using namespace std;

vector<bool> na_chamada;
int inicio=-1;
int fim =-1;
vector<bool> visited;
vector<int> origem;

void dfs(int current, vector<vector<int>>&list) {
    visited[current] = true;
    na_chamada[current] = true;
    for(int adj: list[current]) {
        if(!visited[adj]) {
            origem[adj] = current;
            dfs(adj, list);
            if(inicio!=-1) break;
        } else if(na_chamada[adj]) {
            inicio= adj;
            fim = current;
            return;
        }
    }
    na_chamada[current] = false;
}