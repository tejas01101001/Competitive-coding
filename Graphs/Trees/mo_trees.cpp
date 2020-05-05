
struct query
{
    int l, r, lca, idx;
    bool flag;
};

const int N = 2e5 + 5;
const int l = ceil(log2(N));
int up[N][l], tin[N], tout[N];
int res[N];
int cnt[N], a[N];
bool chk[N];
vector<int> adj[N];
vector<int> euler;
vector<query> mo;
int n, q, eu, ev, timer = 0;
int len;

void dfs(int s, int e)
{
    euler.pb(s);
    tin[s] = timer++;

    up[s][0] = e;
    for (int i = 1; i < l; i++)
    {
        up[s][i] = up[up[s][i - 1]][i - 1];
    }

    for (auto u : adj[s])
    {
        if (u == e)
            continue;
        dfs(u, s);
    }
    euler.pb(s);
    tout[s] = timer++;
}

bool isancestor(int u, int v)
{
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int LCA(int u, int v)
{
    if (isancestor(u, v))
        return u;
    if (isancestor(v, u))
        return v;

    for (int i = l; i >= 0; i--)
    {
        if (!isancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

bool compare(query a, query b)
{
    if (a.l / len != b.l / len)
        return a.l / len < b.l / len;

    return ((a.l / len) & 1) ? (a.r < b.r) : (a.r > b.r);
}

query make_query(int a, int b, int idx)
{
    if (tin[a] > tin[b])
        swap(a, b);

    int lca = LCA(a, b);

    if (a == lca)
        return {tin[a], tin[b], lca, idx, 0};
    return {tout[a], tin[b], lca, idx, 1};
}

void check(int node)
{
    //DONT COUNT NODE IF IT APPEARS TWICE
    if (!chk[node])
    {

    }
    else
    {

    }
    chk[node] ^= 1;
}
void compute()
{
    //algo for zero based queries
    int l = 0, r = -1;
    for (query u : mo)
    {
        while (l > u.l)
            check(euler[--l]);
        while (r < u.r)
            check(euler[++r]);
        while (l < u.l)
            check(euler[l++]);
        while (r > u.r)
            check(euler[r--]);

        if (u.flag)
        {
            check(u.lca);
            //
            check(u.lca);
        }
        else 
        {

        }
    }
}
int main()
{
    kira;
    cin >> n >> q;
    forz(i, n - 1)
    {
        cin >> eu >> ev;
        adj[eu].pb(ev);
        adj[ev].pb(eu);
    }
    dfs(1, 1);

    int ql, qr;
    forz(i, q)
    {
        cin >> ql >> qr;
        mo.pb(make_query(ql, qr, i));
    }
    len = int(sqrt(n + 0.5)) + 1;
    sort(all(mo), compare);

    compute();
    for (int i = 1; i <= n; i++)
        p0(cnt[i]);
    return 0;
}