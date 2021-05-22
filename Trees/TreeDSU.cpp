const int N = 2e5 + 5;
int sz[N];
bool big[N];
int cnt[N];
int col[N];
vector<int> adj[N];


// Function to be changed according to question
void add(int curr, int prev, int val)
{
    // Contribution of the curr node
    cnt[col[curr]] += val;

    // Contribution of all the children (bigchild may or maynot be included)
    for (auto child : adj[curr])
    {
        if (child != prev && !big[child])
            add(child, curr, val);
    }
}

ll getans(int curr)
{
    ll ans = 
    return ans;
}

// Get the size of each subtree
void getsz(int curr, int prev)
{
    sz[curr] = 1;
    for (auto child : adj[curr])
    {
        if (child == prev)
            continue;

        getsz(child, curr);
        sz[curr] += sz[child];
    }
}

void dfs(int curr, int prev, int keep)
{
    // Find the biggest child in terms of size of subtree rooted at child
    int mx = -1, bigchild = -1;
    for (auto child : adj[curr])
    {
        if (child != prev && sz[child] > mx)
        {
            mx = sz[child];
            bigchild = child;
        }
    }

    // Run the dfs on smaller children first
    // We are going to delete their contribution them after their use.
    for (auto child : adj[curr])
    {
        if (child != prev && child != bigchild)
            dfs(child, curr, 0);
    }

    // Run the DFS on the bigger child
    if (bigchild != -1)
    {
        dfs(bigchild, curr, 1);
        big[bigchild] = 1;
    }

    // All the contribution of bigchild subtree is stored here

    add(curr, prev, 1); // Contribution of node curr and the smaller subtrees is due to add function

    // Now we have the required info for subtree rooted at curr
    getans(curr);

    // Reset the big bool value
    if (bigchild != -1)
        big[bigchild] = 0;

    // Clear the contribution of subtree rooted at curr if it is smaller child of some node
    if (keep == 0)
        add(curr, prev, -1);
}