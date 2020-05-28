1)what is the minimum price of such a route?
2)how many minimum-price routes are there? (modulo 109+7)
3)what is the minimum number of flights in a minimum-price route?
4)what is the maximum number of flights in a minimum-price route?

const int N = 1e5 + 5;
const lli INF = LLONG_MAX;
bool vis[N];
vector<pll> dis(N, {INF, 0});
vector<lli> mini(N, INF);
vector<lli> maxi(N, -INF);
vector<pll> adj[N];
int n, m;
 
int main()
{
    kira;
    cin >> n >> m;
    lli eu, ev, ew;
 
    forz(i, m)
    {
        cin >> eu >> ev >> ew;
        adj[eu].pb({ev, ew});
    }
 
    priority_queue<pair<lli, lli>> pq;
    dis[1] = {0, 1};
    pq.push({0, 1});
    mini[1]=0;
    maxi[1]=0;
    while (!pq.empty())
    {
        lli s = pq.top().S;
        pq.pop();
        if (vis[s])
            continue;
        vis[s] = true;
 
        for (auto u : adj[s])
        {
            lli v = u.F;
            lli w = u.S;
            if (dis[s].F + w == dis[v].F)
            {
                dis[v].S = modadd(dis[s].S, dis[v].S);
                mini[v] = min(mini[v], mini[s] + 1);
                maxi[v] = max(maxi[v], maxi[s] + 1);
            }
            if (dis[s].F + w < dis[v].F)
            {
                dis[v]={dis[s].F+w,dis[s].S};
                mini[v] = mini[s] + 1;
                maxi[v] = maxi[s] + 1;
                pq.push({-dis[v].F,v});
            }
        }
    }
    p4(dis[n].F,dis[n].S,mini[n],maxi[n]);
    run_time();
    return 0;
}