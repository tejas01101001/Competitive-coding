bool isbi(int x)
{
	vector<int> color(n + 1, -1);
	bool isbi = true;
	queue<int> q;
	q.push(x);
	for (int i = 1; i <= n; i++)
	{
		if (color[i] == -1)
		{
			q.push(i);
			color[i] = 0;
			while (!q.empty())
			{
				int s = q.front();
				q.pop();
				for (int u : adj[s])
				{
					if (color[u] == -1)
					{
						color[u] = 1 - color[s];
						q.push(u);
					}
					else
					{
						isbi &= (color[u] != color[s]);
					}
				}
			}
		}
	}
	return isbi;
}
