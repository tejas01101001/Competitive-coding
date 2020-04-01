//https://codeforces.com/contest/1187/problem/E
//https://codeforces.com/contest/1187/submission/74281657


void dfs(int s,int e)
{
    sz[s]=1;
    for(auto u:adj[s])
    {
        if(u==e)continue;
        dfs(u,s);
        sz[s]+=sz[u];
    }
    ans+=sz[s];
    return;
}

void dfs2(int s,int e,lli ans)
{
    for(auto u:adj[s])
    {
        if(u==e)continue;
        res=max(ans-2*sz[u]+n,res);
        dfs2(u,s,ans-2*sz[u]+n);
    }
}
