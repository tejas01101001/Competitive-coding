
//https://codeforces.com/problemset/problem/321/E 

const int N = 4e3 + 5;
lli dp_prev[N], dp_curr[N];
lli a[N][N], mat[N][N];

lli cost(int x, int i)
{
    return mat[i][i] + mat[x - 1][x - 1] - mat[i][x - 1] - mat[x - 1][i];
}

void compute(int l, int r, int optl, int optr)
{
    if (l > r)
        return;

    int mid = (l + r) / 2;

    pll best = mp(INF, -1);
    for (int x = optl; x <= min(mid, optr); x++)
    {
        best = min(best, {dp_prev[x] + cost(x + 1, mid), x});
    }

    dp_curr[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

int main()
{
    kira;

    lli n, k;
    cin >> n >> k;

    memset(dp_curr, 0, sizeof(dp_curr));
    memset(dp_prev, 0, sizeof(dp_prev));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            mat[i][j] = mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1] + a[i][j];
        }
    }

    for (int i = 0; i <= n; i++)
    {
        dp_prev[i] = 0;
        dp_curr[i] = mat[i][i];
    }

    for (int i = 0; i < k - 1; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp_prev[j] = dp_curr[j];
        }
        compute(1, n, 1, n);
    }

    p1(dp_curr[n] / 2);

    run_time();
    return 0;
}