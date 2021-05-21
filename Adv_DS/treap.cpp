// Treap is a data structure that stores pairs (X, Y) in a binary tree.
// Binary search tree by X and a Binary heap by Y. 
// Node contains values (X0, Y0)
// All nodes in the left  subtree have X < X0
// All nodes in the right subtree have X > X0
// All nodes in both left and right subtrees have Y < Y0.


// Random number generator
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int get_rand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

// Structure for treap node
struct node
{
    node *left, *right;
    int prior, size;
    ll value;
    bool invert;
    ll sum;
    node(ll v)
    {
        left = right = NULL;
        prior = get_rand(1, 2e9);
        size = 1;
        value = v;
        invert = false;
        sum = v;
    }
};

// Global declaration of treap default as NULL
node *treap;

int size(node *treap)
{
    if (treap == NULL)
        return 0;
    return treap->size;
}

ll get(node *treap)
{
    if (!treap)
        return 0;
    // Modified according to question
    return treap->sum;
}

void combine(node *treap)
{
    if (treap)
    {
        // Modified according to question
        treap->sum = treap->value + get(treap->left) + get(treap->right);
    }
}

// Used for lazy propogation of reversal
void push(node *treap)
{
    if (!treap)
        return;

    if (treap->invert)
    {
        treap->invert = false;
        swap(treap->left, treap->right);
        if (treap->left)
            treap->left->invert ^= 1;
        if (treap->right)
            treap->right->invert ^= 1;
    }
}

// The following function split implements the splitting operation.
// It recursively splits the treap treap into treaps left and right. 
// Left treap contains the first k nodes and right treap contains the remaining nodes.

void split(node *treap, node *&left, node *&right, int k)
{
    if (treap == NULL)
    {
        left = right = NULL;
    }
    else
    {
        push(treap);
        if (size(treap->left) < k)
        {
            // 
            split(treap->right, treap->right, right, k - size(treap->left) - 1);
            left = treap;
        }
        else
        {
            split(treap->left, left, treap->left, k);
            right = treap;
        }
        treap->size = size(treap->left) + size(treap->right) + 1;
        combine(treap);
    }
}

// The following function merge implements the merging operation. 
// Creates a treap that contains first the nodes of the treap left and then the nodes of the treap right.

void merge(node *&treap, node *left, node *right)
{
    push(left);
    push(right);

    if (left == NULL)
        treap = right;
    else if (right == NULL)
        treap = left;
    else
    {
        if (left->prior > right->prior)
        {
            merge(left->right, left->right, right);
            treap = left;
        }
        else
        {
            merge(right->left, left, right->left);
            treap = right;
        }
        treap->size = size(treap->left) + size(treap->right) + 1;
        combine(treap);
    }
}

void rev_subarray(node *&treap, int l, int r)
{
    node *prefix, *suffix, *waste, *subarray;

    split(treap, prefix, suffix, r);
    split(prefix, waste, subarray, l - 1);

    subarray->invert ^= 1;

    merge(prefix, waste, subarray);
    merge(treap, prefix, suffix);
}

void add_node(ll val)
{
    merge(treap, treap, new node(val));
    return;
}

ll range_sum(node *&treap, int l, int r)
{
    node *prefix, *suffix, *waste, *subarray;

    split(treap, prefix, suffix, r);
    split(prefix, waste, subarray, l - 1);

    ll ans = subarray->sum;

    merge(prefix, waste, subarray);
    merge(treap, prefix, suffix);

    return ans;
}

void print(node *treap)
{
    if (!treap)
        return;
    push(treap);
    print(treap->left);
    cout << treap->sum << " ";
    print(treap->right);
}