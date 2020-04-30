1)Time complexity O(VE)
2)Used to find shortest distances from a source to all 
  the other vertices.
3)|V|-1 iterations required
4)All edges checked in each of the iteration.
5)ith iteration uses i edges between (u,v) to minimise the distances.
6)IF at |V| iteration any distance reduces then we have 
  a negative cycle.

const int N = 2505;
const lli INF = LLONG_MAX;
lli dis[N];

struct edge
{
    lli u, v, w;
};
vector<edge> edges;

int main()
{

    kira;
    lli n, m;
    cin >> n >> m;
    lli eu, ev, ew;

    forz(i, m)
    {
        cin >> eu >> ev >> ew;
        edges.pb({eu, ev,ew});
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    dis[1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto x : edges)
        {
            lli u = x.u;
            lli v = x.v;
            lli w = x.w;
            if (dis[u] != INF && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            }
        }
    }

    for (auto x : edges)
    {
        lli u = x.u;
        lli v = x.v;
        lli w = x.w;
        if (dis[u] != INF && dis[u] + w < dis[v])
        {
            cout << -1;
            return 0;
        }
    }

    cout << dis[n];
    run_time();
    return 0;
}