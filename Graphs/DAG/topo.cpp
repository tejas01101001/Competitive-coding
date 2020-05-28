
const int N = 2e5 + 5;
vector<int> adj[N];
vector<int> ans;
bool vis[N];
int n,m;

void dfs(int s)
{
    vis[s] = true;
    for (auto u : adj[s])
    {
        if (vis[u])
            continue;
        dfs(u);
    }
    ans.pb(s);
}

void toposort()
{
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    reverse(all(ans));
}