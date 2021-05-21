inline int64_t gilbertOrder(int x, int y, int pow, int rotate)
{
    if (pow == 0)
    {
        return 0;
    }
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? (
                               (y < hpow) ? 0 : 3)
                         : (
                               (y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct query
{
    int l, r, idx;
    int64_t ord;
    inline void calcOrder()
    {
        ord = gilbertOrder(l, r, 21, 0);
    }
};

const int N = 2e5 + 5;
vector<int> adj[N];
vector<int> v;
int siz[N];
int pos[N];
int timer = 0;
int a[N], cnt[N], ans[N], arr[N];
map<int, int> m;
int len, res = 0;
int n, q, ql, qr, y;
vector<query> mo;

void dfs(int s = 0, int e = -1)
{
    siz[s] = 1;
    v.pb(s);
    for (auto u : adj[s])
    {
        if (u == e)
            continue;
        dfs(u, s);
        siz[s] += siz[u];
    }
}

bool compare(query a, query b)
{
    return a.ord < b.ord;
}

void add(int idx)
{
    if (cnt[a[idx]] == 0)
        res++;
    cnt[a[idx]]++;
}
void remove(int idx)
{
    cnt[a[idx]]--;
    if (cnt[a[idx]] == 0)
        res--;
}
void compute()
{
    //algo for zero based queries
    int l = 0, r = -1;
    for (query u : mo)
    {
        while (l > u.l)
        {
            l--;
            add(l);
        }
        while (r < u.r)
        {
            r++;
            add(r);
        }
        while (l < u.l)
        {
            remove(l);
            l++;
        }
        while (r > u.r)
        {
            remove(r);
            r--;
        }
        ans[u.idx] = res;
    }
}
int main()
{
    kira;
    cin >> n;
    forz(i, n)
    {
        cin >> y;
        if (m.count(y))
            arr[i] = m[y];
        else
        {
            arr[i] = int(m.si);
            m[y] = arr[i];
        }
    }
    int eu, ev;
    forz(i, n - 1)
    {
        cin >> eu >> ev;
        eu--;
        ev--;
        adj[eu].pb(ev);
        adj[ev].pb(eu);
    }

    dfs();

    forz(i, n)
    {
        pos[v[i]] = i;
        a[i] = arr[v[i]];
    }

    len = int(sqrt(n + .0)) + 1;

    forz(i, n)
    {
        ql = pos[i];
        qr = pos[i] + siz[i] - 1;
        query x;
        x = {ql, qr, i};
        x.calcOrder();
        mo.pb(x);
    }
    sort(all(mo), compare);

    compute();
    forz(i, n) p0(ans[i]);
    //run_time();
    return 0;
}