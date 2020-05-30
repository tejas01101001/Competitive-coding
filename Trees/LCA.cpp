
const int N = 4e5 + 5;
int tlog[N], dis[N], early[N];
vector<vector<int>> v;
int n, q;
vector<int> adj[N];
vector<int> euler, new_old;

void log_table()
{
    for (int i = 2; i < N; i++)
        tlog[i] = tlog[i / 2] + 1;
}

void sparse_table(vector<int> &a)
{
    int n = int(a.si);
    int k = tlog[n] + 1;
    vector<vector<int>> sparse(k, vector<int>(n));

    sparse[0] = a;
    for (int row = 1; row < k; row++)
    {
        for (int i = 0; i + (1 << row) <= n; i++)
        {
            sparse[row][i] = min(sparse[row - 1][i], sparse[row - 1][i + (1 << (row - 1))]);
        }
    }

    v = sparse;
    return;
}

int lca(int x, int y)
{
    //minimum of a range [L,R] can be computed with:
    //zero based array
    int l = early[x];
    int r = early[y];
    if (l > r)
        swap(l, r);

    int row = tlog[r - l + 1];
    return new_old[min(v[row][l], v[row][r - (1 << row) + 1])];
}

int dist(int x, int y)
{
    int temp = lca(x, y);
    return (dis[x] + dis[y] - 2 * dis[temp]);
}
//EULER TOUR OF A TREE TAKES 2*N-1 space;

void dfs(int s = 1, int e = 0, int h = 0)
{
    int new_index = int(new_old.si);
    new_old.pb(s);
    early[s] = int(euler.si);
    euler.pb(new_index);
    dis[s] = h;

    for (auto u : adj[s])
    {
        if (u == e)
            continue;
        dfs(u, s, h + 1);
        euler.pb(new_index);
    }
}

void precompute()
{
    dfs();
    log_table();
    sparse_table(euler);
}

int main()
{
    kira;
    int x, y;
    cin >> n >> q;

    forz(i, n - 1)
    {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    precompute();
    while (q--)
    {
        cin >> x >> y;
        cout << dist(x, y) << endl;
    }
    return 0;
}
