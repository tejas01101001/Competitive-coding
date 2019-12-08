1)To find a diameter of a tree we run dfs/bfs twice to find the node which is farthest form a given arbitary node when we run dfs/bfs from that node to find the farthest node from that node.

2)This distance is the diameter of tree.

const int N = 2e5 + 5;
vector<int> adj[N];
lli dis[N];
void dfs(int s, int e)
{
    for (auto u : adj[s])
    {
        if (u == e)
            continue;
        dis[u] = dis[s] + 1;
        dfs(u, s);
    }
}
pair<lli, lli> far(lli n)
{
    pair<lli, lli> p = {-1, -1};
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
int main()
{
    kira;
    lli n, u, v;
    cin >> n;
    forz(i, n - 1)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, -1);
    pair<lli, lli> next = far(n);
    memset(dis, 0, sizeof(dis));
    dfs(next.S, -1);
    next = far(n);
    cout << next.F;
    return 0;
}