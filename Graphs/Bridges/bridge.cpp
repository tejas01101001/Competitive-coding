const int N = 1e5 + 5;
vector<int> adj[N];
int tin[N], low[N];
int timer;
bool vis[N];

vector<pii> bridges;

void dfs(int curr, int par)
{
    vis[curr] = true;
    tin[curr] = timer;
    low[curr] = timer;
    timer++;

    for (auto child : adj[curr])
    {
        if (child == par)
            continue;
        if (vis[child])
        {
            low[curr] = min(low[curr], tin[child]);
        }
        else
        {
            dfs(child, curr);
            low[curr] = min(low[curr], low[child]);
            if (low[child] > tin[curr])
            {
                bridges.pb({curr, child});
            }
        }
    }
}

int main()
{
    kira;

    int n, m;
    cin >> n >> m;

    int eu, ev;
    forz(i, m)
    {
        cin >> eu >> ev;
        adj[eu].pb(ev);
        adj[ev].pb(eu);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, 0);
    }

    cout << bridges.size() << endl;
    for (auto x : bridges)
    {
        p2(x.F, x.S);
    }

    run_time();
    return 0;
}