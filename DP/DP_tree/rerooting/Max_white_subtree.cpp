//https://codeforces.com/contest/1324/problem/F

//https://codeforces.com/contest/1324/submission/74288042

void dfs(int s,int e)
{
    dp[s]=a[s];
    for(auto u:adj[s])
    {
        if(u==e)continue;
        dfs(u,s);
        dp[s]+=max(0ll,dp[u]);
    }
}
void dfs2(int s,int e,lli ans)
{
    res[s]=ans;
    for(auto u:adj[s])
    {
        if(u==e)continue;
        dfs2(u,s,dp[u]+max(0ll,ans-max(0ll,dp[u])));
    }
    return;
}

//https://codeforces.com/contest/1324/submission/74294424

void dfs(int s, int e)
{
    dp[s] = a[s];
    for (auto u : adj[s])
    {
        if (u == e)
            continue;
        dfs(u, s);
        dp[s] += max(0ll, dp[u]);
    }
}

void dfs2(int s, int e)
{
    res[s] = dp[s];
    for (auto u : adj[s])
    {
        if (u == e)
            continue;
        dp[s] -= max(0ll, dp[u]);
        dp[u] += max(0ll, dp[s]);
        dfs2(u, s);
        dp[u] -= max(0ll, dp[s]);
        dp[s] += max(0ll, dp[u]);
    }
    return;
}
