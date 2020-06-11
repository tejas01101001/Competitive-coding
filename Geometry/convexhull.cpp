bool cw(pll a, pll b, pll c)
{
    return a.F * (b.S - c.S) + b.F * (c.S - a.S) + c.F * (a.S - b.S) < 0;
}

bool ccw(pll a, pll b, pll c)
{
    return a.F * (b.S - c.S) + b.F * (c.S - a.S) + c.F * (a.S - b.S) > 0;
}

vector<pll> convex(vector<pll> a)
{
    vector<pll> v = a;
    int n = int(v.si);
    if (n == 1)
        return v;

    sort(all(v));
    v.erase(unique(all(v)),v.en);
    
    vector<pll> up, down;
    pll p1 = v[0], p2 = v.back();
    up.pb(p1);
    down.pb(p1);

    if (p1 == p2)
        return {p1};

    for (int i = 1; i < v.si; i++)
    {
        if (i == int(v.si - 1) || cw(p1, v[i], p2))
        {
            while (up.si >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], v[i]))
                up.pop_back();
            up.pb(v[i]);
        }
        if (i == v.si - 1 || ccw(p1, v[i], p2))
        {
            while (down.si >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], v[i]))
                down.pop_back();
            down.pb(v[i]);
        }
    }

    v.clear();
    for (auto x : up)
        v.pb(x);
    for (int i = down.si - 2; i > 0; i--)
        v.pb(down[i]);

    return v;
}

int main()
{
    kira;
    lli n;
    cin >> n;

    vector<pll> v;
    lli x, y;
    forz(i, n)
    {
        cin >> x >> y;
        v.pb({x, y});
    }

    vector<pll> con = convex(v);
    reverse(all(con));

    p1(con.si);
    for (auto x : con)
    {
        p2(x.F, x.S);
    }
    
    return 0;
}
