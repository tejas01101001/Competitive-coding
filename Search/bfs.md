# Breadth First Search

```C++
const int N = 2e5 + 5;
vector<int> adj[N];
bool vis[N];
int dis[N];

void bfs(int x)
{
	queue<int> q;
	vis[x] = true;
	dis[x] = 0;
	q.push(x);
	while (!q.empty())
	{
		int s = q.front();
		q.pop();

		for (auto u : adj[s])
		{
			if (vis[u])
				continue;
			vis[u] = true;
			dis[u] = dis[s] + 1;
			q.push(u);
		}
	}
}
```