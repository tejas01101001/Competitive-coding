lli histogram(vector<lli> v)
{
    int n = int(v.si);
    vector<lli> a;
    a.pb(-1);
    for (auto x : v)
        a.pb(x);

    stack<pll> s;
    lli ans = 0;
    s.push({-1, 0});

    for (int i = 1; i <= n; i++)
    {
        while (a[i] < s.top().F)
        {
            pll p = s.top();
            s.pop();
            ans = max(ans, (i - s.top().S - 1) * p.F);
        }
        s.push({a[i], i});
    }

    while (int(s.si) > 1)
    {
        pll p = s.top();
        s.pop();
        ans = max(ans, p.F * (n - s.top().S));
    }

    return ans;
}

lli max_one_matrix(vector<vector<lli>> a)
{
    int n = int(a.si);
    int m = int(a[0].si);
    vector<lli> v = a[0];
    lli ans = histogram(v);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
                v[j] = 0;
            else
                v[j]++;
        }
        ans = max(ans, histogram(v));
    }
    return ans;
}