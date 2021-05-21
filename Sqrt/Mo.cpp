1)Lets say the block size is S.

2)If we look only look at all queries that with the left index in the same block. The queries are sorted by the right index. Therefore we will call add(cur_r) and remove(cur_r) only O(N) times for all these queries combined. This gives O(N/S*N) calls for all blocks.

3)The value of cur_l can change by at most O(S) during between two queries. Therefore we have an additional O(SQ) calls of add(cur_l) and remove(cur_l).

4)Block size of precisely N‾‾√ doesnt always offer the best runtime. For example, if N‾‾√=750 then it may happen that block size of 700 or 800 may run better. More importantly, dont compute the block size at runtime - make it const. Division by constants is well optimized by compilers.

5)In odd blocks sort the right index in ascending order and in even blocks sort it in descending order. This will minimize the movement of right pointer.

struct query
{
    int l, r, idx;
};

const int N = 2e5 + 5;
int a[N], cnt[N], ans[N];
map<int, int> m;
int len, res = 0;
int n, q, ql, qr, y;
vector<query> mo;

bool compare(query a, query b)
{
    if (a.l / len != b.l / len)
        return a.l / len < b.l / len;

    //sort even blocks sorted by desc in odd by ascending
    //purely logical is the above process
    return ((a.l / len) & 1) ? (a.r < b.r) : (a.r > b.r);
}

void add(int idx)
{
    if (cnt[a[idx]] == 0)
        res++;
    cnt[a[idx]]++;
}
void remove(int idx)
{
    cnt[a[idx]]--;
    if (cnt[a[idx]] == 0)
        res--;
}
void compute()
{
    //algo for zero based queries
    int l = 0, r = -1;
    for (query u : mo)
    {
        while (l > u.l)
        {
            l--;
            add(l);
        }
        while (r < u.r)
        {
            r++;
            add(r);
        }
        while (l < u.l)
        {
            remove(l);
            l++;
        }
        while (r > u.r)
        {
            remove(r);
            r--;
        }
        ans[u.idx] = res;
    }
}
int main()
{
    kira;

    cin >> n >> q;
    forz(i, n)
    {
        cin >> y;
        if (m.count(y))
            a[i] = m[y];
        else
        {
            a[i] = int(m.si);
            m[y] = a[i];
        }
    }

    len = int(sqrt(n + .0)) + 1;
    forz(i, q)
    {
        cin >> ql >> qr;
        mo.pb({ql - 1, qr - 1, i});
    }
    sort(all(mo), compare);

    compute();
    forz(i, q) p0(ans[i]);
    return 0;
}