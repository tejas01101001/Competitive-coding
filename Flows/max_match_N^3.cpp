1)mat[i] stores the match of i 
2)O(n^3);

const int N = 500;
int n, k, a[N], p[N], mat[N];
bool adj[N][N], vis[N];

bool dfs(int u)
{
    vis[u] = 1;
    for (int v = 0; v < n; ++v)
    {
        if (adj[u][v] && (mat[v] < 0 || !vis[mat[v]] && dfs(mat[v])))
        {
            mat[v] = u;
            return 1;
        }
    }
    return 0;
}
int max_match()
{
    memset(mat,-1,sizeof(mat));
    int flow=0;
    for(int i=0;i<n;i++)
    {
        memset(vis,0,n);
        flow+=dfs(i);
    }
    return flow;
}