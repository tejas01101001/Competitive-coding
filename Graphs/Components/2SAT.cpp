const int N = 2e5 + 5;
vector<int> adj[N];
vector<int> adr[N];
vector<bool> vis(N), assignment(N);
vector<int> order;
int component[N];

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

void dfs2(int s, int cnt)
{
    vis[s] = true;
    component[s] = cnt;

    for (auto u : adr[s])
    {
        if (!vis[u])
            dfs2(u, cnt);
    }
}

void edges(int a, int b, int na, int nb)
{
    adj[na].pb(b);
    adj[nb].pb(a);

    adr[b].pb(na);
    adr[a].pb(nb);
}

int main()
{
    kira;

    int n, m, eu, ev;
    char u, v;

    cin >> m >> n;

    forz(i, m)
    {
        cin >> u >> eu >> v >> ev;
        int nu = 2 * eu;
        int nv = 2 * ev;
        eu = nu - 1;
        ev = nv - 1;

        if (u == '+' && v == '+')
            edges(eu, ev, nu, nv);
        if (u == '-' && v == '+')
            edges(nu, ev, eu, nv);
        if (u == '+' && v == '-')
            edges(eu, nv, nu, ev);
        if (u == '-' && v == '-')
            edges(nu, nv, eu, ev);
    }

    n = 2 * n;
    vis.assign(n + 1, false);

    fore(i, 1, n)
    {
        if (!vis[i])
            dfs1(i);
    }

    int cnt = 0;
    vis.assign(n + 1, false);

    fore(i, 1, n)
    {
        int v = order[n - i];
        if (!vis[v])
        {
            dfs2(v, cnt++);
        }
    }

    assignment.assign(n + 1, false);
    for (int i = 1; i <= n; i += 2)
    {
        if (component[i] == component[i + 1])
        {
            p1("IMPOSSIBLE");
            break;
        }
        assignment[(i + 1) / 2] = component[i] > component[i + 1];
    }

    for (int i = 1; i <= n/2; i++)
    {
        cout << (assignment[i] ? "+" : "-") << " ";
    }

    return 0;
}