#include <bits/stdc++.h>
using namespace std;


int n;
const int nMax = 30;

vector<vector<int>> build_up(const vector<int>& jumps)
{
    vector<vector<int>> up(nMax, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++)
    {
        up[0][i] = jumps[i];
    }
    
    for (int i = 1; i < nMax; i++)
    {
        for (int j = 0; j < n; j++)
        {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
    
    return up;
}

int BinaryLifting(int current, const vector<vector<int>>& up, int f)
{
    for (int i = 0; i < nMax; i++)
    {
        if ((f & (1 << i)) != 0)
        {
            current = up[i][current];
        }
    }
    return current;
}