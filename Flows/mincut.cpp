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

bool hasEdge[505][505];
vector<int> positive, negative;
 
int main()
{
    kira;
    int n, m;
    cin >> n >> m;
    Dinic dinic(n + 1, 1, n);
 
    forz(i,m)
    {
        int u, v;
        cin >> u >> v;
        dinic.add_edge(u, v, 1);
        dinic.add_edge(v, u, 1);
        hasEdge[u][v] = true;
        hasEdge[v][u] = true;
    }
 
    cout << dinic.flow() << endl;
 
    for (int i = 1; i <= n; ++i)
    {
        if (dinic.level[i] >= 0)
            positive.push_back(i);
        else
            negative.push_back(i);
    }
 
    for (auto x : positive)
        for (auto y : negative)
            if (hasEdge[x][y])
                p2(x, y);
                
    return 0;
}