1)Size of subtrees of each node can be calulated by the following.

const int N = 2e5 + 5;
vector<int> adj[N];
lli subtree[N];
void dfs(int s,int e)
{
    subtree[s]=1;
    for(auto u:adj[s])
    {
        if(u==e)continue;
        dfs(u,s);
        subtree[s]+=subtree[u];
    }
}