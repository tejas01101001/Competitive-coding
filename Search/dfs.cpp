const int N =
vector<int> adj[N];
vector<int> v;
bool vis[N];
int c = 0;
int no_of_leaves = 0;
void dfs(int s)
{
	if (vis[s])
		return;
	vis[s] = true;
	//process
	int f = 1;
	for (auto u : adj[s])
	{
		if (vis[u])
			continue;
		//process2
		dfs(u);
		f = 0;
	}
	if (f == 1)
		no_of_leaves++;
}