1)Meet in the middle is a technique where the search space is divided into two parts of about equal size. A separate search is performed for both of the parts,and finally the results of the searches are combined.
The technique can be used if there is an efficient way to combine the results of the searches. In such a situation, the two searches may require less time than
one large search. Typically, we can turn a factor of 2^n into a factor of 2^n/2 using the meet in the middle technique.

//NO OF SUBSETS WITH SUM >=K
const lli INF = 1e12;
lli k;
vector<lli> subset(vector<lli> &v)
{
    lli n = v.si;
    vector<lli> sum;
    for (int i = 0; i < (1 << n); i++)
    {
        lli s = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                s += v[j];
        }
        if (s <= k)
        {
            sum.pb(s);
        }
    }
    return sum;
}
int main()
{
    kira;
    lli n, x;
    cin >> n >> k;
    vector<lli> a, b;
    forz(i, n)
    {
        cin >> x;
        if (i < n / 2)
            b.pb(x);
        else
            a.pb(x);
    }
    vector<lli> sa = subset(a);
    vector<lli> sb = subset(b);
    lli c = 0;
    sort(all(sb));
    for (auto x : sa)
    {
        auto it=er(sb.be,sb.en,k-x);
        c+=it.S-it.F;
    }
    cout << c;
    return 0;
}