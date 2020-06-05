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
