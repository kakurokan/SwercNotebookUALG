#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> parent, rank, tamanho;

public:
    int nMax, nComponents;

    DSU(int size)
    {
        parent.resize(size + 1);
        rank.assign(size + 1, 0);
        tamanho.assign(size + 1, 1);
        for (int i = 0; i <= size; i++)
        {
            parent[i] = i;
        }
        nMax = 0;
        nComponents = size;
    }
    int find(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void uniao(int i, int j)
    {
        int iRoot = find(i);
        int jRoot = find(j);
        if (jRoot == iRoot)
            return;

        if (rank[iRoot] < rank[jRoot])
        {
            parent[iRoot] = jRoot;
            tamanho[jRoot] += tamanho[iRoot]; 
            nMax = max(nMax, tamanho[jRoot]);
        }
        else if (rank[iRoot] > rank[jRoot])
        {
            parent[jRoot] = iRoot;
            tamanho[iRoot] += tamanho[jRoot]; 
            nMax = max(nMax, tamanho[iRoot]);
        }
        else
        {
            parent[iRoot] = jRoot;
            tamanho[jRoot] += tamanho[iRoot];
            nMax = max(nMax, tamanho[jRoot]);
            rank[jRoot]++;
        }
        nComponents--;
    }

public:
    int getnComponents()
    {
        return nComponents;
    }

public:
    int getnMax()
    {
        return nMax;
    }
};
