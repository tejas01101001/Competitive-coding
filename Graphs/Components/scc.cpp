const int N = 2e5 + 5;
vector<int> adj[N];
vector<int> adr[N];
vector<bool> vis(N);
vector<int> order, component;

void dfs1(int s)
{
    vis[s] = true;
    for (auto u : adj[s])
    {
        if (!vis[u])
            dfs1(u);
    }
    order.pb(s);
}

void dfs2(int s)
{
    vis[s] = true;
    component.pb(s);
    for (auto u : adr[s])
    {
        if (!vis[u])
            dfs2(u);
    }
}

int main()
{
    kira;
    int n, m, a, b;
    cin >> n >> m;
    forz(i, m)
    {
        cin >> a >> b;
        adj[a].pb(b);
        adr[b].pb(a);
    }

    vis.assign(n + 1, false);
    fore(i, 1, n)
    {
        if (!vis[i])
            dfs1(i);
    }

    int cnt = 0;
    vector<int> ans;

    vis.assign(n + 1, false);
    fore(i, 1, n)
    {
        int v = order[n - i];
        if (!vis[v])
        {
            cnt++;
            ans.pb(v);
            dfs2(v);
            component.clear();
        }
    }
    return 0;
}