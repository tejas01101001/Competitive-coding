const int N = 2e5 + 5;
int tlog[N];
void log_table()
{
    for (int i = 2; i < N; i++)
        tlog[i] = tlog[i / 2] + 1;
}

vector<vector<lli>> sparse_table(vector<lli> &a)
{
    int n = int(a.si);
    int k = tlog[n] + 1;
    vector<vector<lli>> sparse(k, vector<lli>(n));

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
lli query(vector<vector<lli>> &v, int l, int r)
{
    //minimum of a range [L,R] can be computed with:
    //zero based array
    int row = tlog[r - l + 1];
    return min(v[row][l], v[row][r - (1 << row) + 1]);
}

int main()
{
    kira;
    lli n;
    cin >> n;
    vector<lli> a(n);
    forz(i, n) cin >> a[i];
    log_table();
    vector<vector<lli>> v = sparse_table(a);
    int q, l, r;
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        cout<<query(v,l,r)<<endl;
    }
    return 0;
}
