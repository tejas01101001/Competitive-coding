
//https://cses.fi/problemset/task/2086

const int N = 3e3 + 5;
lli dp_prev[N], dp_curr[N];
lli a[N], pre[N];

lli cost(int x, int i)
{
    return (pre[i] - pre[x - 1]) * (pre[i] - pre[x - 1]);
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
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = 0; i <= n; i++)
    {
        dp_prev[i] = 0;
        dp_curr[i] = pre[i] * pre[i];
    }

    for (int i = 0; i < k - 1; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp_prev[j] = dp_curr[j];
        }
        compute(1, n, 1, n);
    }

    p1(dp_curr[n]);

    run_time();
    return 0;
}