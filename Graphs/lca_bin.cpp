const int N = 2e5 + 5;
vector<int> adj[N];
int tin[N], tout[N];
int n, l;
int up[N][21];
int timer;

void dfs(int s, int e)
{
    tin[s] = ++timer;
    up[s][0] = e;
    for (int i = 1; i <= l; i++)
    {
        up[s][i] = up[up[s][i - 1]][i - 1];
    }

    for (auto u : adj[s])
    {
        if (u == e)
            continue;
        dfs(u, s);
    }

    tout[s] = ++timer;
}

bool isancestor(int u, int v)
{
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v)
{
    if (isancestor(u, v))
        return u;
    if (isancestor(v, u))
        return v;

    for (int i = l; i >= 0; i--)
    {
        if (!isancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int query(int s, int k)
{
    for (int i = l; i >= 0; i--)
    {
        if (k & (1 << i))
            s = up[s][i];
    }
    if (s == 0)
        s = -1;
    return s;
}

int main()
{
    kira;
    int x, q;
    cin >> n >> q;
    forz(i, n - 1)
    {
        cin >> x;
        adj[i + 2].pb(x);
        adj[x].pb(i + 2);
    }
    l = ceil(log2(n));

    memset(up, 0, sizeof(up));
    timer = 0;
    dfs(1, 1);

    int u, v;
    forz(i, q)
    {
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
    run_time();
    return 0;
}