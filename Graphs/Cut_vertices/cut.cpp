const int N = 1e5 + 5;
vector<int> adj[N];
int tin[N], low[N];
int timer;
bool vis[N];

vector<int> cut_vertex;

void dfs(int curr, int par)
{
    vis[curr] = true;
    tin[curr] = timer;
    low[curr] = timer;
    int children = 0;
    timer++;

    int f = 0; // Avoid duplicates
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

            if (low[child] >= tin[curr] && par != 0 && f == 0)
            {
                cut_vertex.pb(curr);
                f = 1;
            }
            children++;
        }
    }

    if (par == 0 && children > 1)
        cut_vertex.pb(curr);
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

    cout << cut_vertex.size() << endl;
    for (auto x : cut_vertex)
    {
        p0(x);
    }

    run_time();
    return 0;
}