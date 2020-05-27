const int N = 2.5e3 + 5;
vector<int> adj[N];
int dis[N];
int pre[N];
const int INF = 1e9;
int ans = INF;
void bfs(int s)
{
    dis[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto u : adj[x])
        {
            if (dis[u] == INF)
            {
                dis[u] = dis[x] + 1;
                pre[u] = x;
                q.push(u);
            }
            else if (pre[u] != x && pre[x] != u)
            {
                ans = min(ans, dis[x] + dis[u] + 1);
            }
        }
    }
}

int main()
{
    kira;
    int n, a, b, m;
    cin >> n >> m;
    forz(i, m)
    {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int i = 1; i <= n; i++)
        {
            dis[i] = INF;
            pre[i] = -1;
        }
        bfs(i);
    }
    if (ans == INF)
        p1(-1);
    else
        p1(ans);
    return 0;
}