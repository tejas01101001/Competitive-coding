//https://codeforces.com/contest/1092/problem/F
//https://codeforces.com/contest/1092/submission/74304035

const int N = 2e5 + 5;
vector<lli> adj[N];
lli sum[N], n;
lli a[N];
lli ans = 0, res = 0;
void dfs(int s, int e = -1, lli h = 0)
{
    res += a[s] * h;
    sum[s] = a[s];
    for (auto u : adj[s])
    {
        if (u == e)
            continue;
        dfs(u, s, h + 1);
        sum[s] += sum[u];
    }
}
void dfs2(int s, int e)
{
    res = max(res, ans);
    for (auto u : adj[s])
    {
        if (u == e)
            continue;

        ans -= sum[u];
        sum[s] -= sum[u];
        ans += sum[s];
        sum[u] += sum[s];

        dfs2(u, s);

        sum[u] -= sum[s];
        ans -= sum[s];
        sum[s] += sum[u];
        ans += sum[u];
    }
}
