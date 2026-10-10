struct aresta
{
    int s, f;
    long w;
};

long long kruskal(int n, vector<aresta>& edges)
{
    long long cost = 0, count = 0;

    sort(edges.begin(), edges.end(),
         [](const aresta& a, const aresta& b)
         {
             return a.w < b.w;
         });

    DSU dsu(n);

    for (const aresta& edge : edges)
    {
        int s = edge.s;
        int f = edge.f;
        long long w = edge.w;

        if (dsu.find(s) != dsu.find(f))
        {
            dsu.unionSet(s, f);
            cost += w;

            if (++count == n - 1)
                return cost;
        }
    }

    return -1;
}