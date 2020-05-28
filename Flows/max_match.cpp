1)n boys and m girls to be matched
2)Hopkorft Algo is special case of Dinic 
3)O(EV^(1/2))
4)Insert two dummy nodes and convert the problem to  a max 
  flow problem 
  
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
 
    vector<pll> flow()
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
        vector<pll> res;
        for (auto x : edges)
        {
            if (x.flow == 1&&x.v<x.u)
                res.pb({x.v,x.u});
        }
        res.pb({f, -1});
        return res;
    }
};
 
int main()
{
    kira;
    int n, m, k;
    cin >> n >> m >> k;
    Dinic dinic(n + m + 3, 1, n + m + 2);
 
    forz(i, k)
    {
        int u, v;
        cin >> u >> v;
        u++;
        v++;
        dinic.add_edge(u, v + n, 1);
    }
 
    for (int i = 2; i <= n + 1; i++)
    {
        dinic.add_edge(1, i, 1);
    }
 
    for (int i = n + 2; i <= n + m + 1; i++)
    {
        dinic.add_edge(i, n + m + 2, 1);
    }
 
    vector<pll> ans = dinic.flow();
    cout<<ans.back().F<<endl;
    ans.pop_back();
 
    for(auto x:ans)
    {
        if(x.F==1)continue;
        if(x.S==n+m+2)continue;
        p2(x.F-1,x.S-n-1);
    }
    return 0;
}