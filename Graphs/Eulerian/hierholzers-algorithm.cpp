//Eulerian cycle 

const int N = 2e5 + 5;
list<int>adj[N];
int deg[N];
bool vis[N];
int cnt = 0;
stack<int>head,tail;

void dfs(int s)
{
    vis[s] = true;
    cnt++;
    for (auto u : adj[s])
    {
        if (vis[u])
            continue;
        dfs(u);
    }
}

int main()
{

    int n, m, x, y;
    cin >> n >> m;
   
    forz(i,m)
    {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
        ++deg[x];
        ++deg[y];
    }

    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        if (int(adj[i].size()) == 0)
            cnt++;
        if (int(adj[i].size()) % 2)
            f = 0;
    }

    dfs(1);
    if (cnt != n || f == 0)
    {
        //Eulerian Cycle Exsists only if graph is connected 
        //Nodes with zero degree maynnot be in the component
        //and all nodes have even degrees
        cout << "IMPOSSIBLE";
        return 0;
    }

    head.push(1);
    while (!head.empty())
    {
        while (deg[head.top()])
        {
            int v = adj[head.top()].back();
            adj[head.top()].pop_back();
            adj[v].remove(head.top());
            --deg[head.top()];
            head.push(v);
            --deg[v];
        }
        while (!head.empty() && !deg[head.top()])
        {
            tail.push(head.top());
            head.pop();
        }
    }

    while (!tail.empty())
    {
        cout << tail.top() << " ";
        tail.pop();
    }

    run_time();
    return 0;
}