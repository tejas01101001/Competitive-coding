
const int N = 4e5 + 5;
int tlog[N];
void log_table()
{
    for (int i = 2; i < N; i++)
        tlog[i] = tlog[i / 2] + 1;
}

vector<vector<int>> sparse_table(vector<int> &a)
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

    return sparse;
}
int query(vector<vector<int>> &v, int l, int r)
{
    //minimum of a range [L,R] can be computed with:
    //zero based array
    int row = tlog[r - l + 1];
    return min(v[row][l], v[row][r - (1 << row) + 1]);
}
int n, q;
int dis[N];
//EULER TOUR OF A TREE TAKES 2*N-1 space;
vector<int> adj[N];
vector<int> euler, early(N), new_old;
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

    dfs();
    log_table();

    vector<vector<int>> v = sparse_table(euler);
    while (q--)
    {
        cin >> x >> y;
        int l = early[x];
        int r = early[y];
        if (l > r)
            swap(l, r);

        int new_index = query(v, l, r);
        cout << dis[x] + dis[y] - 2 * dis[new_old[new_index]] << endl;
    }
    return 0;
}
