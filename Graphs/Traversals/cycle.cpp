CYCLE DETECTION

1)We will run a series of DFS in the graph.Initially all vertices are colored white(0).From each unvisited(white) vertex,start the DFS, mark it gray(1) while entering and mark it black(2) on exit.If DFS moves to a gray vertex, then we have found a cycle.The cycle itself can be reconstructed using parent array.

NOTE:If the graph is undirected, the edge to parent is not considered

const int N =
vector<lli> color(N, 0),pred(N);
vector<lli> adj[N];
lli cycst, cycen;
lli n, m;

bool dfs(lli s)
{
    color[s] = 1;
    for (auto u : adj[s])
    {
        if (color[u] == 0)
        {
            pred[u] = s;
            if (dfs(u))
                return true;
        }
        else if (color[u] == 1&& pred[s]!=u)
        {
            //FOR DIRECTED GRAPH REMOVE pred[s]!=u
            cycen = s;
            cycst = u;
            return true;
        }
    }
    color[s] = 2;
    return false;
}

void findcyc()
{
    color.assign(n+1, 0);
    pred.assign(n+1, -1);
    cycst = -1;
    for(int i=1;i<=n;i++)
    {
        if (color[i] == 0 && dfs(i))
            break;
    }
    if (cycst == -1)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    vector<lli> path;
    path.pb(cycst);
    for (lli v = cycen; v != cycst; v = pred[v])
        path.pb(v);
    path.pb(cycst);
    reverse(all(path));
    cout<<path.si<<endl;
    for (auto x : path)
        p0(x);
}