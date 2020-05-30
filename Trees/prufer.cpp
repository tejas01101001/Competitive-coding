1)The Prüfer code is a way of encoding a labeled tree with n vertices using a sequence of n−2 integers in the interval [0;n−1]. This encoding also acts as a bijection between all spanning trees of a complete graph and the numerical sequences.

2)The Prüfer code is constructed as follows. We will repeat the following procedure n−2 times: we select the leaf of the tree with the smallest number, remove it from the tree, and write down the number of the vertex that was connected to it. After n−2 iterations there will only remain 2 vertices, and the algorithm ends.

3)After constructing the Prüfer code two vertices will remain. One of them is the highest vertex n−1, but nothing else can be said about the other one.

4)Each vertex appears in the Prüfer code exactly a fixed number of times - its degree minus one. This can be easily checked, since the degree will get smaller every time we record its label in the code, and we remove it once the degree is 1. For the two remaining vertices this fact is also true.

//================Build prufer=========================

void dfs(int v)
{
    for (int u : adj[v])
    {
        if (u != parent[v])
        {
            parent[u] = v;
            dfs(u);
        }
    }
}

vector<int> prufer_code()
{
    int n = adj.size();
    parent.resize(n);
    parent[n - 1] = -1;
    dfs(n - 1);

    int ptr = -1;
    vector<int> degree(n);
    for (int i = 0; i < n; i++)
    {
        degree[i] = adj[i].size();
        if (degree[i] == 1 && ptr == -1)
            ptr = i;
    }

    vector<int> code(n - 2);
    int leaf = ptr;
    for (int i = 0; i < n - 2; i++)
    {
        int next = parent[leaf];
        code[i] = next;
        if (--degree[next] == 1 && next < ptr)
        {
            leaf = next;
        }
        else
        {
            ptr++;
            while (degree[ptr] != 1)
                ptr++;
            leaf = ptr;
        }
    }

    return code;
}

//====================DECODE===========================

vector<pll> prufer_decode(vector<lli> code)
{
    lli n = code.si + 2;
    vector<lli> deg(n + 1, 1);
    for (auto x : code)
        deg[x]++;
    lli in = 1;
    while (deg[in] != 1)
        in++;
    lli leaf = in;
    vector<pll> edges;
    for (auto x : code)
    {
        edges.pb({leaf, x});
        if (--deg[x] == 1 && x < in)
            leaf = x;
        else
        {
            in++;
            while (deg[in] != 1)
                in++;
            leaf = in;
        }
    }
    edges.pb({leaf, n});
    return edges;
}