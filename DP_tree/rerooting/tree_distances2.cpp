//https://cses.fi/problemset/task/1133
//https://cses.fi/problemset/result/377876/

void dfs(int s = 1, int e = -1, int h = 0)
{
    siz[s] = 1;
    dis[s] = h;
    for (auto u : adj[s])
    {
        if (u == e)
            continue;
        dfs(u, s, h + 1);
        siz[s] += siz[u];
        sum[s] += sum[u] + siz[u];
    }
}

void dfs2(int s, int e)
{
    ans[s] = sum[s];
    for (auto u : adj[s])
    {
        if (u == e)
            continue;

        sum[s] -= sum[u];
        sum[s] -= siz[u];
        siz[s] -= siz[u];
        siz[u] += siz[s];
        sum[u] += siz[s];
        sum[u] += sum[s];

        dfs2(u, s);

        sum[u] -= sum[s];
        sum[u] -= siz[s];
        siz[u] -= siz[s];
        siz[s] += siz[u];
        sum[s] += siz[u];
        sum[s] += sum[u];
    }
}
