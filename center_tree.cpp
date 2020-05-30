const int N = 2e5 + 5;
vector<int> adj[N], path;
int dis[N];
int pre[N];
int n;

void dfs(int s, int e)
{
    for (auto u : adj[s])
    {
        if (u == e)
            continue;
        pre[u] = s;
        dis[u] = dis[s] + 1;
        dfs(u, s);
    }
}

pii far()
{
    pii p = {-1, -1};
    for (int i = 1; i <= n; i++)
    {
        if (p.F < dis[i])
        {
            p.F = dis[i];
            p.S = i;
        }
    }
    return p;
}

vector<int> center()
{
    memset(dis, 0, sizeof(dis));
    dfs(1, -1);
    pii next = far();
    memset(dis, 0, sizeof(dis));
    for(int i=1;i<=n;i++)pre[i]=-1;
    int far_node = next.S;
    dfs(far_node, -1);
    next = far();
    for (int j = next.S; pre[j] != -1; j = pre[j])
    {
        path.pb(j);
    }
    path.pb(far_node);
    int dia = next.F;
    dia++;
    if (dia % 2)
        return {path[dia / 2]};
    return {path[dia / 2], path[dia / 2 - 1]};
}