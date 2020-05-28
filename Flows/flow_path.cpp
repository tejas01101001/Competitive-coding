struct FlowEdge
{
    int v, u;
    lli cap, flow = 0;
    FlowEdge(int v, int u, lli cap) : v(v), u(u), cap(cap) {}
};
 
struct Dinic
{
    const lli flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;
 
    Dinic(int n, int s, int t) : n(n), s(s), t(t)
    {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
 
    void add_edge(int v, int u, lli cap)
    {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }
 
    bool bfs()
    {
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int id : adj[v])
            {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }
 
    lli dfs(int v, lli pushed)
    {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int &cid = ptr[v]; cid < (int)adj[v].size(); cid++)
        {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            lli tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
 
    lli flow()
    {
        lli f = 0;
        while (true)
        {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (lli pushed = dfs(s, flow_inf))
            {
                f += pushed;
            }
        }
        return f;
    }
};
 
vector<int> adj[505];
bool edge_taken[505][505];
bool vis[505];
vector<int> res;
int n, m;
 
void dfs(int s)
{
    if (s == n)
    {
        p1(int(res.si));
        for (auto x : res)
            p0(x);
        cout << endl;
        return;
    }
    vis[s] = true;
    for (auto u : adj[s])
    {
        if (!vis[u] && edge_taken[s][u])
        {
            res.pb(u);
            dfs(u);
            res.pop_back();
            edge_taken[s][u] = false;
        }
    }
}
int main()
{
    kira;
    cin >> n >> m;
    Dinic dinic(n + 1, 1, n);
 
    forz(i, m)
    {
        int u, v;
        cin >> u >> v;
        dinic.add_edge(u, v, 1);
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    cout << dinic.flow() << endl;
    for (auto x : dinic.edges)
        if (x.flow ==1)
            edge_taken[x.v][x.u] = true;
 
    res.pb(1);
    dfs(1);
    return 0;
}