1)The benefit of Dijsktra’s algorithm is that it is more efficient
and can be used for processing large graphs. 
However, the algorithm requires that there are NO negative weight 
edges in the graph.

2)At each step, Dijkstra’s algorithm selects a node that has not 
been processed yet and whose distance is as small as possible.
The first such node is node 1 with distance 0.

3)adj[a] contains a pair (b,w) always when there is an edge from 
node a to node b with weight w.

4)In the following code, the priority queue q contains pairs of 
the form (−d, x), meaning that the current distance to node x is d.

vector<lli> dijsktra(int x)
{
	priority_queue<pair<lli, lli>> q;
	vector<bool> vis(n + 1, false);
	vector<lli> p(n + 1, -1);
	vector<lli> dis(n + 1, INF);

	dis[x] = 0;
	q.push({0, x});
	while (!q.empty())
	{
		int s = q.top().S;
		q.pop();
		if (vis[s])
			continue;
		vis[s] = true;
		for (auto u : adj[s])
		{
			int b = u.F;
			int w = u.S;
			if (dis[s] + w < dis[b])
			{
				dis[b] = dis[s] + w;
				p[b] = s;
				q.push({-dis[b], b});
			}
		}
	}
	return dis;
}
